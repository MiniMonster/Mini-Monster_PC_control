#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QTranslator>
#include <QMessageBox>
#include <QThread>
#include <QKeyEvent>
#include <QListIterator>
#include <QMutableListIterator>
#include <QSystemTrayIcon>

#include <qminimonsterworker.h>
#include <qminimonsterscheduler.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0, bool silentMode = false);
    void singleDevice(QString addr, int port, int mode);
    void singleGroup(QString group, int mode);
    ~MainWindow();
    
private slots:
    void toLog(QString message);

    void toStat(QString addr, QString remoteName, QString temp, QString port1state, QString port2state, QString port3state, QString port4state, QString port5state, QString port6state);

    void doUpdateDevicesList(bool updateMainTab = true);

    void doUpdateGroupsList();

    void processRealtimeUpdate();

    void onKillerTimer();

    void doAddJobToQueue(QString device, int port, int mode);

    void onSchedulerJobRemoved(QString device, int port, int repeatInterval, int switchMode, QDateTime time);

    void onDeviceNotReachable(QString addr);

    void onSchedulerJobAdded(QString device, int port, int repeatInterval, int switchMode, QDateTime time, bool initLoad = false);

    void doUpdateScheduledTasksCount(int count);

    void onTrayIconActivated(QSystemTrayIcon::ActivationReason reason);

    void deviceNotReachible(QString addr);

    void onWorkerExits();

    void invertPort(QString addr, QString port);

    void doUpdatePortLocalName(QString addr, QString port, QString desc);

    void doUpdateCurrentSelectedDevice(QString addr);

    void on_checkbox_getRemoteName_stateChanged(int arg1);

    void on_tabWidget_currentChanged(int index);

    void on_btn_logClear_clicked();

    void on_btn_addModule_clicked();

    void on_btn_p1_clicked();

    void on_btn_removeSelectedModules_clicked();

    void on_btn_addSelectedToNewGroup_clicked();

    void on_cb_DeviceSelection_currentIndexChanged(int index);

    void on_btn_p1_2_clicked();

    void on_btn_p1_3_clicked();

    void on_btn_p1_4_clicked();

    void on_btn_p1_5_clicked();

    void on_btn_p1_6_clicked();

    void on_btn_currentDeviceRefresh_clicked();

    void on_listGroups_currentTextChanged(const QString &currentText);

    void on_btn_GroupSwitchOff_clicked();

    void on_btn_GroupSwitchOn_clicked();

    void on_btn_GroupInverse_clicked();

    void on_cb_DeviceSelection_currentIndexChanged(const QString &arg1);

    void on_cb_DeviceSelection_currentTextChanged(const QString &arg1);

    void on_btn_removeSelectedGroups_clicked();

    void on_btn_removeSelectedPorts_clicked();

    void on_edit_p1_editingFinished();

    void on_edit_p1_2_editingFinished();

    void on_edit_p1_3_editingFinished();

    void on_edit_p1_4_editingFinished();

    void on_edit_p1_5_editingFinished();

    void on_edit_p1_6_editingFinished();

    void on_lblAddTaskToSchedule_clicked();

    void on_cb_repeatEvery_toggled(bool checked);

    void on_cbEnableTranslation_toggled(bool checked);

    void on_cb_DeviceSelection_editTextChanged(const QString &arg1);

    void on_cbRealtimeUpdateIntervalEnabled_toggled(bool checked);

    void on_sbRealtimeUpdateInterval_valueChanged(int arg1);

    void on_lblRemoveSelectedTasks_clicked();

    void on_cbRealtimeUpdateIntervalEnabled_clicked();

    void on_sbWorkerIterationTime_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_cbEnableTranslation_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;

    QTranslator translator;

    QSystemTrayIcon *trayIcon;

    qMiniMonsterScheduler* tasker;

    QTimer realtimeUpdateTimer;
    QTimer killerTimer;

    void addPortToGroup(QString groupName, QString addr, QString port);

    bool eventFilter(QObject *target, QEvent *event);

    bool areYouShure();

    bool currentDevicePort1State;
    bool currentDevicePort2State;
    bool currentDevicePort3State;
    bool currentDevicePort4State;
    bool currentDevicePort5State;
    bool currentDevicePort6State;

    QString getSettingFromDB(QString settingName);
    void setSettingToDB(QString settingName, QString settingValue);

    QString strOn;
    QString strOff;
    QString lastCurrentDeviceAddress;

    qMiniMonsterWorker *worker;

    QSqlDatabase sdb;
};

#endif // MAINWINDOW_H
