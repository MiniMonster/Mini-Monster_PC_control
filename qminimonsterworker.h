#ifndef QMINIMONSTERWORKER_H
#define QMINIMONSTERWORKER_H

#include <QObject>
#include <QStringList>
#include <QTimer>
#include <QString>
#include <QTcpSocket>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>

class qMiniMonsterWorker : public QObject
{
    Q_OBJECT
public:
    explicit qMiniMonsterWorker(int timerInterval = 1000, bool singleMode = false, QObject *parent = 0);
    
signals:
    void onLog(QString message);
    void onWorkerExit();
    void onStat(QString addr, QString remoteName, QString temp, QString port1state, QString port2state, QString port3state, QString port4state, QString port5state, QString port6state);
    void onDeviceNotReachable(QString addr);
    
private slots:
    void update();
    void onTestConnected();

public slots:
    void addTask(QString addr, QString port = "1", QString mode = "0", bool now = false);
    void addStat(QString addr, bool now = false);
    void workRequestFinished(QNetworkReply *reply);
    void updateTimerInterval(int interval);

private:
    QStringList *mainQueue;
    QTimer *mainTimer;
    QNetworkAccessManager *nam;
    QTcpSocket *testSocket;
    bool isSingleMode;

    bool checkBit(unsigned int dwNumber, int iBit);
    bool nextFast;

    bool isDeviceReachable(QString addr);
};

#endif // QMINIMONSTERWORKER_H
