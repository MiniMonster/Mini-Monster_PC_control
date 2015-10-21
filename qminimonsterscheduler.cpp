#include "qminimonsterscheduler.h"

qMiniMonsterScheduler::qMiniMonsterScheduler(QObject *parent) :
    QObject(parent)
{
    tasks = new QList<qMiniMonsterSchedulerTask*>;

    mainTimer = new QTimer();
    mainTimer->start(1000);

    taskNames.append(tr("Switch off"));
    taskNames.append(tr("Switch on"));
    taskNames.append(tr("Inverse"));
}

qMiniMonsterScheduler::~qMiniMonsterScheduler()
{
    delete tasks;
}

void qMiniMonsterScheduler::addTask(QString device, int port, int mode, int repeatInterval, QDateTime time, bool initLoad)
{
    tasks->append(new qMiniMonsterSchedulerTask(device, port, time, mode, repeatInterval));

    QObject::connect(mainTimer, SIGNAL(timeout()), tasks->last(), SLOT(onTimerTick()));
    QObject::connect(tasks->last(), SIGNAL(onTimeHasCome(QString, int, int, int, qMiniMonsterSchedulerTask*)), this, SLOT(onJobEmited(QString, int, int, int, qMiniMonsterSchedulerTask*)));

    emit onLog(tr("Task ") + taskNames.at(mode) + tr(" added to scheduler on port ") + QString::number(port) + tr(" at time ") + time.toString() + tr(" for device ") + device + tr(" with interval ") + QString::number(repeatInterval));
    emit onCountChaged(tasks->count());

    emit onJobAdded(device, port, repeatInterval, mode, time, initLoad);
}

void qMiniMonsterScheduler::deleteTask(QString device, int port, int mode, QDateTime time)
{
    qMiniMonsterSchedulerTask *task;

    for (int i = 0; i < tasks->count(); i++)
    {
        task = tasks->at(i);

        QString *tmp = new QString(task->getDevice());

        if (*tmp == device)
        {
            if (task->getPort() == port)
            {
                if (task->getTime().secsTo(time) == 0)
                {
                    tasks->removeOne(task);
                    delete task;

                    emit onJobRemoved(device, port, 0, mode, time);

                    emit onCountChaged(tasks->count());

                    break;
                }
            }
        }

        delete tmp;
        task = 0;
        delete task;
    }
}


void qMiniMonsterScheduler::onJobEmited(QString device, int port, int taskMode, int interval, qMiniMonsterSchedulerTask *task)
{
    emit onLog(tr("Job emited ") + device + tr(" port ") + QString::number(port) + tr(" at ") + QDateTime::currentDateTime().toString());

    emit onJobRemoved(device, port, 0, taskMode, task->getTime());

    tasks->removeOne(task);
    delete task;
    emit onCountChaged(tasks->count());

    if (interval > 0)
    {
        emit onLog(tr("Repeating task in ") + QString::number(interval) + tr(" seconds"));

        QDateTime *tmp = new QDateTime();
        *tmp = tmp->currentDateTime();
        *tmp = tmp->addSecs(interval);

        emit addTask(device, port, taskMode, interval, *tmp);

        delete tmp;
    }

    emit onAddJobToQueue(device, port, taskMode);
}
