#ifndef QMINIMONSTERSCHEDULERTASK_H
#define QMINIMONSTERSCHEDULERTASK_H

#include <QObject>
#include <QString>
#include <QDateTime>

class qMiniMonsterSchedulerTask : public QObject
{
    Q_OBJECT

private:
    QDateTime *startTime;
    int taskMode; // 0 - off, 1 - on, 2 - inverse
    QString *device;
    int port;
    int repeat;

public:
    explicit qMiniMonsterSchedulerTask(QString newDevice, int newPort, QDateTime newStartTime, int newTaskMode, int newRepeat = 0, QObject *parent = 0);
    ~qMiniMonsterSchedulerTask();

    QString getDevice();
    int getPort();
    QDateTime getTime();

    
signals:
    void onTimeHasCome(QString device, int port, int mode, int repeatInterval, qMiniMonsterSchedulerTask* task);
    
public slots:
    void onTimerTick();
    
};

#endif // QMINIMONSTERSCHEDULERTASK_H
