#ifndef QMINIMONSTERSCHEDULER_H
#define QMINIMONSTERSCHEDULER_H

#include <QObject>
#include <QDateTime>
#include <QStringList>
#include <QList>
#include <QTimer>
#include <QListIterator>

#include <qminimonsterschedulertask.h>

class qMiniMonsterScheduler : public QObject
{
    Q_OBJECT
private:
    QList<qMiniMonsterSchedulerTask*> *tasks;

    QTimer *mainTimer;
    QStringList taskNames;


public:
    explicit qMiniMonsterScheduler(QObject *parent = 0);
    ~qMiniMonsterScheduler();

    void addTask(QString device, int port, int mode, int repeatInterval, QDateTime time, bool initLoad = false);
    void deleteTask(QString device, int port, int mode, QDateTime time);
    
signals:
    void onLog(QString message);
    void onCountChaged(int count);

    void onAddJobToQueue(QString device, int port, int mode);

    void onJobRemoved(QString device, int port, int repeatInterval, int switchMode, QDateTime time);
    void onJobAdded(QString device, int port, int repeatInterval, int switchMode, QDateTime time, bool initLoad);
    
public slots:
    void onJobEmited(QString device, int port, int taskMode, int interval, qMiniMonsterSchedulerTask *task);
    
};

#endif // QMINIMONSTERSCHEDULER_H

