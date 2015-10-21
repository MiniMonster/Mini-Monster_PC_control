#include "qminimonsterschedulertask.h"

qMiniMonsterSchedulerTask::qMiniMonsterSchedulerTask(QString newDevice, int newPort, QDateTime newStartTime, int newTaskMode, int newRepeat, QObject *parent) :
    QObject(parent)
{
    device = new QString(newDevice);
    port = newPort;
    startTime = new QDateTime(newStartTime);
    repeat = newRepeat;
    taskMode = newTaskMode;
}

qMiniMonsterSchedulerTask::~qMiniMonsterSchedulerTask()
{
    delete device;
    delete startTime;
}

QString qMiniMonsterSchedulerTask::getDevice()
{
    return *device;
}

void qMiniMonsterSchedulerTask::onTimerTick()
{
    if (QDateTime::currentDateTime().secsTo(*startTime) == 0)
    {
        emit onTimeHasCome(*device, port, taskMode, repeat, this);
    }
}


int qMiniMonsterSchedulerTask::getPort()
{
    return port;
}

QDateTime qMiniMonsterSchedulerTask::getTime()
{
    return *startTime;
}
