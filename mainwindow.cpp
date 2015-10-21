#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, bool silentMode) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lbl_DeviceNotReachible->setVisible(false);

    if (!silentMode)
        QObject::connect(&realtimeUpdateTimer, SIGNAL(timeout()), this, SLOT(processRealtimeUpdate()));
    else
        QObject::connect(&killerTimer, SIGNAL(timeout()), this, SLOT(onKillerTimer()));

    if (!silentMode)
    {
        tasker = new qMiniMonsterScheduler(this);

        QObject::connect(tasker, SIGNAL(onLog(QString)), this, SLOT(toLog(QString)));
        QObject::connect(tasker, SIGNAL(onCountChaged(int)), this, SLOT(doUpdateScheduledTasksCount(int)));
        QObject::connect(tasker, SIGNAL(onAddJobToQueue(QString,int,int)), this, SLOT(doAddJobToQueue(QString,int,int)));
        QObject::connect(tasker, SIGNAL(onJobAdded(QString, int, int, int, QDateTime, bool)), this, SLOT(onSchedulerJobAdded(QString, int, int, int, QDateTime, bool)));
        QObject::connect(tasker, SIGNAL(onJobRemoved(QString, int, int, int, QDateTime)), this, SLOT(onSchedulerJobRemoved(QString, int, int, int, QDateTime)));

        trayIcon = new QSystemTrayIcon(this);
        trayIcon->setToolTip("QmiMoControl");

        trayIcon->setIcon(QIcon(":/1.png"));

        QObject::connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(onTrayIconActivated(QSystemTrayIcon::ActivationReason)));

        trayIcon->show();
    }

    if (!silentMode)
    {
        ui->dateTimeEdit_scheduler->setDateTime(QDateTime::currentDateTime());

        ui->tbl_sheduler->installEventFilter(this);
    }

    sdb = QSqlDatabase::addDatabase("QSQLITE");

    sdb.setDatabaseName("miMoDB.sqlite");

    if (!sdb.open())
    {
        ui->tabWidget->setCurrentIndex(4);
        emit toLog(tr("Can't open database with error: ") + sdb.lastError().text());
        ui->tabWidget->setEnabled(0);
    }
    else
    {
        if (!silentMode)
            if (getSettingFromDB("translation") == "1")
            {
                translator.load("miMo2_" + QLocale::system().name());
                qApp->installTranslator(&translator);
                ui->retranslateUi(this);

                ui->cbEnableTranslation->setChecked(1);
            }

        emit toLog(tr("Database opened"));

        // Проверяем, пуста ли база данных, если пуста, то создаем необходимые таблицы

        emit toLog(tr("Checking database content..."));

        QSqlQuery query("SELECT NAME FROM SQLITE_MASTER;");

        bool isTableSettingsPresent, isTableDevicesPresent, isTableTasksPresent;

        isTableDevicesPresent = false;
        isTableSettingsPresent = false;
        isTableTasksPresent = false;

        // Проверяем наличие нужных таблиц
        while (query.next())
        {
            QString *tmp = new QString(query.value(0).toString().toLower());

            if (*tmp == "tasks")
            {
                isTableTasksPresent = true;
                emit toLog(tr("Table") + " " + *tmp + " " + tr("found"));
            };

            if (*tmp == "settings")
            {
                isTableSettingsPresent = true;
                emit toLog(tr("Table") + " " + *tmp + " " + tr("found"));
            };

            if (*tmp == "devices")
            {
                isTableDevicesPresent = true;
                emit toLog(tr("Table") + " " + *tmp + " " + tr("found"));
            };

            delete tmp;
        }

        // Нет таблицы устройств, создаем
        if (!isTableDevicesPresent)
        {
            //CREATE TABLE "devices" (address TEXT, localName TEXT, remoteName TEXT, "temp" TEXT, port1state TEXT, port2state TEXT, port3state TEXT, port4state TEXT, port5state TEXT, port6state TEXT, port1label TEXT DEFAULT 1, port2label TEXT DEFAULT 2, port3label TEXT DEFAULT 3, port4label TEXT DEFAULT 4, port5label TEXT DEFAULT 5, port6label TEXT DEFAULT 6)
            QSqlQuery query("CREATE TABLE \"devices\" (address TEXT, localName TEXT, remoteName TEXT, \"temp\" TEXT, port1state TEXT, port2state TEXT, port3state TEXT, port4state TEXT, port5state TEXT, port6state TEXT, port1label TEXT DEFAULT 1, port2label TEXT DEFAULT 2, port3label TEXT DEFAULT 3, port4label TEXT DEFAULT 4, port5label TEXT DEFAULT 5, port6label TEXT DEFAULT 6)");
            emit toLog(tr("Table") + " " + "devices" + " " + tr("created"));
        }

        // Нет таблицы настроек, создаем
        if (!isTableSettingsPresent)
        {
            //CREATE TABLE "settings" (setting_name TEXT, value INTEGER)
            QSqlQuery query("CREATE TABLE \"settings\" (setting_name TEXT, value INTEGER)");

            // Заполняем таблицу настроек
            QSqlQuery query1("INSERT INTO settings ('setting_name', 'value') VALUES ('translation', '0');");
            QSqlQuery query2("INSERT INTO settings ('setting_name', 'value') VALUES ('rt_update_interval', '2');");
            QSqlQuery query3("INSERT INTO settings ('setting_name', 'value') VALUES ('iterTime', '400');");


            emit toLog(tr("Table") + " " + "settings" + " " + tr("created"));
        }

        // Нет таблицы задач, создаем
        if (!isTableTasksPresent)
        {
            //CREATE TABLE "tasks" (device TEXT, port TEXT, mode TEXT, interval TEXT, "time" TEXT)
            QSqlQuery query("CREATE TABLE \"tasks\" (device TEXT, port TEXT, mode TEXT, interval TEXT, \"time\" TEXT)");
            emit toLog(tr("Table") + " " + "tasks" + " " + tr("created"));
        }
        //

        if (!silentMode)
        {
            QString *interval = new QString(getSettingFromDB("rt_update_interval"));
            ui->sbRealtimeUpdateInterval->setValue(interval->toInt());
        }

        int tmpTime = getSettingFromDB("iterTime").toInt();
        ui->sbWorkerIterationTime->setValue(tmpTime);

        if (silentMode)
            worker = new qMiniMonsterWorker(tmpTime, true, this);
        else
            worker = new qMiniMonsterWorker(tmpTime, false, this);

        //if (!silentMode)
        QObject::connect(worker, SIGNAL(onWorkerExit()), this, SLOT(onWorkerExits()));
        QObject::connect(worker, SIGNAL(onLog(QString)), this, SLOT(toLog(QString)));
        QObject::connect(worker, SIGNAL(onStat(QString,QString,QString,QString,QString,QString,QString,QString,QString)), this, SLOT(toStat(QString,QString,QString,QString,QString,QString,QString,QString,QString)));
        QObject::connect(worker, SIGNAL(onDeviceNotReachable(QString)), this, SLOT(onDeviceNotReachable(QString)));


        if (!silentMode)
        {
            emit doUpdateDevicesList(true);
            emit doUpdateGroupsList();

            QSqlQuery query("SELECT device, port, mode, interval, time FROM tasks");

            while (query.next())
            {
                tasker->addTask(query.value(0).toString(), query.value(1).toInt(), query.value(2).toInt(), query.value(3).toInt(), QDateTime::fromString(query.value(4).toString()), true);
            }
        }

    }

    strOn = tr("Switched ON (Click to OFF)");
    strOff = tr("Switched OFF (Click to ON)");

    if (!silentMode)
        this->show();
}

void MainWindow::singleDevice(QString addr, int port, int mode)
{
    worker->addTask(addr, QString::number(port), QString::number(mode));
}

void MainWindow::singleGroup(QString group, int mode)
{
    QSqlQuery query("SELECT addr, port FROM gr_" + ui->cb_GroupSelect->currentText());

    while (query.next())
        worker->addTask(query.value(0).toString(), query.value(1).toString(), QString::number(mode));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_checkbox_getRemoteName_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
        ui->edit_newModuleName->setEnabled(0);
    else
        ui->edit_newModuleName->setEnabled(1);
}

void MainWindow::toLog(QString message)
{
    if (!(ui->checkBox_logDisabled->isChecked()))
    {
        ui->text_Log->insertPlainText("[" + QDateTime::currentDateTime().toString() + "] " + message + "\n");
        qDebug() << message;
    }
    else
        return;

    if (ui->centralWidget->isVisible())
    {
        ui->statusBar->showMessage("[" + QDateTime::currentDateTime().toString() + "] " + message, 5000);
    }
    else
    {
            //trayIcon->showMessage("QmiMoControl", message, QSystemTrayIcon::Information, 1500);
    }
}

void MainWindow::toStat(QString addr, QString remoteName, QString temp, QString port1state, QString port2state, QString port3state, QString port4state, QString port5state, QString port6state)
{

    QSqlQuery query("UPDATE devices SET port1state='" + port1state + "', port2state='" + port2state + "', port3state='" + port3state + "', port4state='" + port4state + "', port5state='" + port5state + "', port6state='" + port6state + "', remoteName='" + remoteName + "', temp='" + temp + "' WHERE address = '" + addr + "'");

    if (ui->cb_DeviceSelection->currentText() == addr)
    {
        if (ui->lbl_DeviceNotReachible->isVisible())
            ui->lbl_DeviceNotReachible->setVisible(false);

        emit doUpdateCurrentSelectedDevice(addr);
    }

    emit doUpdateDevicesList(false);
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if (index == 0)
    {
        if (realtimeUpdateTimer.isActive())
            return;

        if (ui->cbRealtimeUpdateIntervalEnabled->isChecked())
        {
            realtimeUpdateTimer.start();
        }
    }
    else
        realtimeUpdateTimer.stop();
}

void MainWindow::on_btn_logClear_clicked()
{
    ui->text_Log->clear();
}

void MainWindow::doUpdateDevicesList(bool updateMainTab)
{
    emit toLog(tr("Getting devices from database") + "...");

    if (updateMainTab)
        ui->cb_DeviceSelection->clear();
    ui->cb_scheduledDevice->clear();
    ui->table_modules->setRowCount(0);

    QSqlQuery query("SELECT address, localName, remoteName, port1state, port2state, port3state, port4state, port5state, port6state, temp, port1label, port2label, port3label, port4label, port5label, port6label FROM devices");

    while (query.next())
    {
        ui->table_modules->setRowCount(ui->table_modules->rowCount()+1);

        int *row = new int;

        *row = ui->table_modules->rowCount()-1;

        if (updateMainTab)
            ui->cb_DeviceSelection->addItem(query.value(0).toString());
        ui->cb_scheduledDevice->addItem(query.value(0).toString());

        QTableWidgetItem *newItem1 = new QTableWidgetItem(query.value(0).toString());
        QTableWidgetItem *newItem2 = new QTableWidgetItem(query.value(1).toString());
        QTableWidgetItem *newItem3 = new QTableWidgetItem(query.value(2).toString());

        QTableWidgetItem *newItem4 = new QTableWidgetItem(query.value(3).toString());
        QTableWidgetItem *newItem5 = new QTableWidgetItem(query.value(4).toString());
        QTableWidgetItem *newItem6 = new QTableWidgetItem(query.value(5).toString());
        QTableWidgetItem *newItem7 = new QTableWidgetItem(query.value(6).toString());
        QTableWidgetItem *newItem8 = new QTableWidgetItem(query.value(7).toString());
        QTableWidgetItem *newItem9 = new QTableWidgetItem(query.value(8).toString());
        QTableWidgetItem *newItem10 = new QTableWidgetItem(query.value(9).toString());

        QTableWidgetItem *newItem11 = new QTableWidgetItem(query.value(10).toString());
        QTableWidgetItem *newItem12 = new QTableWidgetItem(query.value(11).toString());
        QTableWidgetItem *newItem13 = new QTableWidgetItem(query.value(12).toString());
        QTableWidgetItem *newItem14 = new QTableWidgetItem(query.value(13).toString());
        QTableWidgetItem *newItem15 = new QTableWidgetItem(query.value(14).toString());
        QTableWidgetItem *newItem16 = new QTableWidgetItem(query.value(15).toString());

        ui->table_modules->setItem(*row, 0, newItem1);
        ui->table_modules->setItem(*row, 1, newItem2);
        ui->table_modules->setItem(*row, 2, newItem3);
        ui->table_modules->setItem(*row, 3, newItem4);
        ui->table_modules->setItem(*row, 4, newItem5);
        ui->table_modules->setItem(*row, 5, newItem6);
        ui->table_modules->setItem(*row, 6, newItem7);
        ui->table_modules->setItem(*row, 7, newItem8);
        ui->table_modules->setItem(*row, 8, newItem9);
        ui->table_modules->setItem(*row, 9, newItem10);

        ui->table_modules->setItem(*row, 10, newItem11);
        ui->table_modules->setItem(*row, 11, newItem12);
        ui->table_modules->setItem(*row, 12, newItem13);
        ui->table_modules->setItem(*row, 13, newItem14);
        ui->table_modules->setItem(*row, 14, newItem15);
        ui->table_modules->setItem(*row, 15, newItem16);

        delete row;
    }
}

void MainWindow::doUpdateGroupsList()
{
    /// !!!!!!!!!!!!!!!!!!!!!!!!!
    emit toLog(tr("Getting groups from database") + "...");

    ui->cb_GroupSelect->clear();
    ui->cb_scheduledGroup->clear();
    ui->listGroups->clear();
    ui->cb_newGroupSelect->clear();

    QSqlQuery query("select name from sqlite_master where name like 'gr_%'");

    while (query.next())
    {
        QString *tmp = new QString(query.value(0).toString().remove("gr_"));

        ui->cb_GroupSelect->addItem(*tmp);
        ui->cb_scheduledGroup->addItem(*tmp);
        ui->listGroups->addItem(*tmp);
        ui->cb_newGroupSelect->addItem(*tmp);

        //qDebug() << *tmp;

        delete tmp;
    }
}

void MainWindow::processRealtimeUpdate()
{
    if (ui->tabWidget->currentIndex() == 0)
        worker->addStat(ui->cb_DeviceSelection->currentText());
}

void MainWindow::onKillerTimer()
{
    this->close();
}

void MainWindow::doAddJobToQueue(QString device, int port, int mode)
{
    if (mode < 2)
        worker->addTask(device, QString::number(port), QString::number(mode));
    else
        invertPort(device, QString::number(port));
}

void MainWindow::onSchedulerJobRemoved(QString device, int port, int repeatInterval, int switchMode, QDateTime time)
{
    ui->tbl_sheduler->selectAll();

    QListIterator<QTableWidgetItem *> i(ui->tbl_sheduler->selectedItems());

    QTableWidgetItem *itemTmp;  //device
    QTableWidgetItem *itemTmp2; //port
    QTableWidgetItem *itemTmp3; //action
    QTableWidgetItem *itemTmp4; //time
    QTableWidgetItem *itemTmp5; //repeat

    while(i.hasNext())
    {
        itemTmp = i.next();
        itemTmp2 = i.next();
        itemTmp3 = i.next();
        itemTmp4 = i.next();
        itemTmp5 = i.next();

        if (itemTmp->text() == device)
            if (itemTmp2->text() == QString::number(port))
                if (itemTmp3->text() == QString::number(switchMode))
                    if (time.secsTo(QDateTime::fromString(itemTmp4->text())) == 0)
                    {
                        ui->tbl_sheduler->removeRow(itemTmp->row());
                        QSqlQuery query("DELETE FROM tasks WHERE device = '" + device + "' AND port = '" + QString::number(port) + "' AND mode ='" + QString::number(switchMode) + "' AND time ='" + time.toString() + "'");
                        //emit toLog("DELETE FROM tasks WHERE device = '" + device + "' AND port = '" + QString::number(port) + "' AND mode ='" + QString::number(switchMode) + "' AND time ='" + itemTmp4->text() + "'");

                        break;
                    }
    }

    itemTmp = 0;
    itemTmp2 = 0;
    itemTmp3 = 0;
    itemTmp4 = 0;
    itemTmp5 = 0;

    delete itemTmp;
    delete itemTmp2;
    delete itemTmp3;
    delete itemTmp4;
    delete itemTmp5;

    ui->tbl_sheduler->clearSelection();
}

void MainWindow::onDeviceNotReachable(QString addr)
{
    if (ui->tab_Main->isVisible())
        if (ui->cb_DeviceSelection->currentText() == addr)
        {
            ui->lbl_DeviceNotReachible->setVisible(true);
        }
}

void MainWindow::onSchedulerJobAdded(QString device, int port, int repeatInterval, int switchMode, QDateTime time, bool initLoad)
{
    ui->tbl_sheduler->setRowCount(ui->tbl_sheduler->rowCount() +1);

    int *row = new int;

    *row = ui->tbl_sheduler->rowCount()-1;

    QTableWidgetItem *newItem1 = new QTableWidgetItem(device);
    QTableWidgetItem *newItem2 = new QTableWidgetItem(QString::number(port));
    QTableWidgetItem *newItem3 = new QTableWidgetItem(QString::number(switchMode));
    QTableWidgetItem *newItem4 = new QTableWidgetItem(time.toString());
    if ((time.secsTo(QDateTime::currentDateTime())) > 0)
        newItem4->setBackgroundColor(QColor("pink"));
    QTableWidgetItem *newItem5 = new QTableWidgetItem(QString::number(repeatInterval));

    ui->tbl_sheduler->setItem(*row, 0, newItem1);
    ui->tbl_sheduler->setItem(*row, 1, newItem2);
    ui->tbl_sheduler->setItem(*row, 2, newItem3);
    ui->tbl_sheduler->setItem(*row, 3, newItem4);
    ui->tbl_sheduler->setItem(*row, 4, newItem5);

    // device port mode interval time
    if (!(initLoad))
        QSqlQuery query("INSERT INTO tasks VALUES ('" + device + "', '" + QString::number(port) + "', '" + QString::number(switchMode) + "', '" + QString::number(repeatInterval)+ "', '" + time.toString()+ "')");

    delete row;
}

void MainWindow::doUpdateScheduledTasksCount(int count)
{
    ui->lblScheduledTasksCount->setText(QString::number(count));
}

void MainWindow::onTrayIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    if (reason == QSystemTrayIcon::DoubleClick)
        this->setVisible(!(this->isVisible()));
}

void MainWindow::deviceNotReachible(QString addr)
{

}

void MainWindow::onWorkerExits()
{
    //qDebug() << "wanted to close";
    //this->close();
    killerTimer.start();
}

void MainWindow::invertPort(QString addr, QString port)
{
    emit toLog(tr("Inverting port") + "" + port + " " + tr("on device") + " " + addr);
    bool oldState = false;

    QSqlQuery query("SELECT port" + port + "state FROM devices WHERE address='" +  addr + "'");

    while (query.next()) {
        oldState = query.value(0).toBool();
    }

    worker->addTask(addr, port, QString::number(!(oldState)));
}

void MainWindow::doUpdatePortLocalName(QString addr, QString port, QString desc)
{
    emit toLog(tr("Updating port description for port ") + addr + " (" + port + ")");

    QSqlQuery query("UPDATE devices SET port" + port + "label='" + desc+ "' WHERE address='" + addr + "'");
}

void MainWindow::doUpdateCurrentSelectedDevice(QString addr)
{
    QSqlQuery query("SELECT localName, remoteName, port1state, port2state, port3state, port4state, port5state, port6state, port1label, port2label, port3label, port4label, port5label, port6label, temp FROM devices WHERE address = '" + addr + "'");

    while (query.next())
    {
        if (query.value(0).toString().length() == 0)
            ui->lbl_currentModuleName->setText(query.value(1).toString() + tr("(Remote)"));
        else
            ui->lbl_currentModuleName->setText(query.value(0).toString() + tr("(Local)"));

        currentDevicePort1State = query.value(2).toBool();
        currentDevicePort2State = query.value(3).toBool();
        currentDevicePort3State = query.value(4).toBool();
        currentDevicePort4State = query.value(5).toBool();
        currentDevicePort5State = query.value(6).toBool();
        currentDevicePort6State = query.value(7).toBool();

        ui->edit_p1->setText(query.value(8).toString());
        ui->edit_p1_2->setText(query.value(9).toString());
        ui->edit_p1_3->setText(query.value(10).toString());
        ui->edit_p1_4->setText(query.value(11).toString());
        ui->edit_p1_5->setText(query.value(12).toString());
        ui->edit_p1_6->setText(query.value(13).toString());

        ui->lbl_Temp->setText(query.value(14).toString() + 'c');

        if (currentDevicePort1State)
        {
            ui->btn_p1->setText(strOn);
            ui->btn_p1->setStyleSheet("background-color: rgb(181, 230, 29);");
        }
        else
        {
            ui->btn_p1->setText(strOff);
            ui->btn_p1->setStyleSheet("background-color: rgb(251, 123, 47);");
        }

        if (currentDevicePort2State)
        {
            ui->btn_p1_2->setText(strOn);
            ui->btn_p1_2->setStyleSheet("background-color: rgb(181, 230, 29);");
        }
        else
        {
            ui->btn_p1_2->setText(strOff);
            ui->btn_p1_2->setStyleSheet("background-color: rgb(251, 123, 47);");
        }

        if (currentDevicePort3State)
        {
            ui->btn_p1_3->setText(strOn);
            ui->btn_p1_3->setStyleSheet("background-color: rgb(181, 230, 29);");
        }
        else
        {
            ui->btn_p1_3->setText(strOff);
            ui->btn_p1_3->setStyleSheet("background-color: rgb(251, 123, 47);");
        }

        if (currentDevicePort4State)
        {
            ui->btn_p1_4->setText(strOn);
            ui->btn_p1_4->setStyleSheet("background-color: rgb(181, 230, 29);");
        }
        else
        {
            ui->btn_p1_4->setText(strOff);
            ui->btn_p1_4->setStyleSheet("background-color: rgb(251, 123, 47);");
        }

        if (currentDevicePort5State)
        {
            ui->btn_p1_5->setText(strOn);
            ui->btn_p1_5->setStyleSheet("background-color: rgb(181, 230, 29);");
        }
        else
        {
            ui->btn_p1_5->setText(strOff);
            ui->btn_p1_5->setStyleSheet("background-color: rgb(251, 123, 47);");
        }

        if (currentDevicePort6State)
        {
            ui->btn_p1_6->setText(strOn);
            ui->btn_p1_6->setStyleSheet("background-color: rgb(181, 230, 29);");
        }
        else
        {
            ui->btn_p1_6->setText(strOff);
            ui->btn_p1_6->setStyleSheet("background-color: rgb(251, 123, 47);");
        }
    }
}

void MainWindow::on_btn_addModule_clicked()
{
    if (ui->edit_newModuleAddress->text().length() > 0)
    {
        QString tmp = ui->edit_newModuleAddress->text().trimmed();
        tmp.replace("\\", "/");

        QSqlQuery query1("SELECT address FROM devices WHERE address = '" + tmp + "'");

        while (query1.next())
        {
            QMessageBox::information(0, "", tr("This module is already in the DB"));
            return;
        }

        emit toLog(tr("Adding new module to database") + "...");

        QSqlQuery query("INSERT INTO devices (address, localName) VALUES ('" + tmp + "', '" + ui->edit_newModuleName->text()  + "')");

        emit doUpdateDevicesList();

        worker->addStat(tmp);
    }
    else
        QMessageBox::information(0, "", tr("Module address can not be null"));
}

void MainWindow::on_btn_p1_clicked()
{
    if (!(areYouShure()))
            return;
    worker->addTask(ui->cb_DeviceSelection->currentText(), "1", QString::number(!currentDevicePort1State), true);
}

void MainWindow::on_btn_removeSelectedModules_clicked()
{
    int ret =  QMessageBox::question(this, tr("Are you shure to delete all of selected ") + tr("modules") + "?", tr("Are you shure to delete all of selected ") + tr("modules") + "?", tr("&Yes"), tr("&No"), QString::null, 0, 1);

    QListIterator<QTableWidgetItem *> i(ui->table_modules->selectedItems());
    QTableWidgetItem *itemTmp;

    switch (ret)
    {
        case 1:
            break;

        case 0:
            while(i.hasNext())
            {
                itemTmp = i.next();

                if (itemTmp->column() == 0)
                {
                    toLog(tr("Deleting device") + " " + itemTmp->text() + " from database...");
                    QSqlQuery query("DELETE FROM devices WHERE address = '" + itemTmp->text() + "'");

                    //// Удаление записей о модуле из групп
                    QSqlQuery query2("select name from sqlite_master where name like 'gr_%'");

                    while (query2.next())
                    {
                        QSqlQuery query3("DELETE FROM " + query2.value(0).toString() + " WHERE addr = '" + itemTmp->text() + "'");
                    }
                }
            }

            emit doUpdateDevicesList();

            break;

      default:
          break;
     }
}

void MainWindow::on_btn_addSelectedToNewGroup_clicked()
{
    bool groupPresent = false;

    QString *newGroupName = new QString("gr_" + ui->cb_newGroupSelect->currentText());

    QSqlQuery query("SELECT name FROM sqlite_master WHERE name = '" + *newGroupName + "'");

    while (query.next())
    {
        groupPresent = true;
    }

    if (!groupPresent)
    {
        emit toLog(tr("Adding group ") + ui->cb_newGroupSelect->currentText() + " to database...");

        QSqlQuery query2("CREATE TABLE " + *newGroupName + " (addr TEXT, port TEXT)");

        emit doUpdateGroupsList();
    }

    if (ui->checkbox_p1->isChecked())
        addPortToGroup(*newGroupName, ui->cb_DeviceSelection->currentText(), "1");

    if (ui->checkbox_p1_2->isChecked())
        addPortToGroup(*newGroupName, ui->cb_DeviceSelection->currentText(), "2");

    if (ui->checkbox_p1_3->isChecked())
        addPortToGroup(*newGroupName, ui->cb_DeviceSelection->currentText(), "3");

    if (ui->checkbox_p1_4->isChecked())
        addPortToGroup(*newGroupName, ui->cb_DeviceSelection->currentText(), "4");

    if (ui->checkbox_p1_5->isChecked())
        addPortToGroup(*newGroupName, ui->cb_DeviceSelection->currentText(), "5");

    if (ui->checkbox_p1_6->isChecked())
        addPortToGroup(*newGroupName, ui->cb_DeviceSelection->currentText(), "6");



    delete newGroupName;
}

void MainWindow::on_cb_DeviceSelection_currentIndexChanged(int index)
{
    if (index <= 0)
        return;

    emit doUpdateCurrentSelectedDevice(ui->cb_DeviceSelection->currentText());
}

void MainWindow::on_btn_p1_2_clicked()
{
    if (!(areYouShure()))
            return;
    worker->addTask(ui->cb_DeviceSelection->currentText(), "2", QString::number(!currentDevicePort2State), true);
    //worker->addStat(ui->cb_DeviceSelection->currentText());
}

void MainWindow::on_btn_p1_3_clicked()
{
    if (!(areYouShure()))
            return;
    worker->addTask(ui->cb_DeviceSelection->currentText(), "3", QString::number(!currentDevicePort3State), true);
    //worker->addStat(ui->cb_DeviceSelection->currentText());
}

void MainWindow::on_btn_p1_4_clicked()
{
    if (!(areYouShure()))
            return;
    worker->addTask(ui->cb_DeviceSelection->currentText(), "4", QString::number(!currentDevicePort4State), true);
}

void MainWindow::on_btn_p1_5_clicked()
{
    if (!(areYouShure()))
            return;
    worker->addTask(ui->cb_DeviceSelection->currentText(), "5", QString::number(!currentDevicePort5State), true);
}

void MainWindow::on_btn_p1_6_clicked()
{
    if (!(areYouShure()))
            return;
    worker->addTask(ui->cb_DeviceSelection->currentText(), "6", QString::number(!currentDevicePort6State), true);
}

void MainWindow::on_btn_currentDeviceRefresh_clicked()
{

}

void MainWindow::addPortToGroup(QString groupName, QString addr, QString port)
{
    emit toLog(tr("Adding device port ") + addr + " (" + port + ") " + tr("to group") + " " + QString(groupName));

    QSqlQuery query("SELECT addr, port FROM " + groupName + " WHERE addr = '" + addr + "' AND port = '" + port + "'");

    while (query.next())
        return;

    QSqlQuery query2("INSERT INTO " + groupName + " VALUES ('" + addr + "', '" + port + "')");
}

bool MainWindow::eventFilter(QObject *target, QEvent *event)
{
    if (target == ui->tbl_sheduler)
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent *keyEvent = (QKeyEvent *)event;

            if (keyEvent->key() == Qt::Key_Delete)
            {
                QListIterator<QTableWidgetItem *> i(ui->tbl_sheduler->selectedItems());

                QTableWidgetItem *itemTmp;  //device
                QTableWidgetItem *itemTmp2; //port
                QTableWidgetItem *itemTmp3; //action
                QTableWidgetItem *itemTmp4; //time
                QTableWidgetItem *itemTmp5; //repeat

                while(i.hasNext())
                {
                    itemTmp = i.next();
                    itemTmp2 = i.next();
                    itemTmp3 = i.next();
                    itemTmp4 = i.next();
                    itemTmp5 = i.next();

                    if (itemTmp->column() == 0)
                    {
                        tasker->deleteTask(itemTmp->text(), itemTmp2->text().toInt(), itemTmp3->text().toInt(), QDateTime::fromString(itemTmp4->text()));
                    }
                }

                itemTmp = 0;
                itemTmp2 = 0;
                itemTmp3 = 0;
                itemTmp4 = 0;
                itemTmp5 = 0;

                delete itemTmp;
                delete itemTmp2;
                delete itemTmp3;
                delete itemTmp4;
                delete itemTmp5;

                return true;
            }
        }
    return QMainWindow::eventFilter(target ,event);
}

bool MainWindow::areYouShure()
{
    if (ui->checkBox_showRequest->isChecked())
    {
        int ret =  QMessageBox::question(this, tr("Warning"), tr("Are you shure to switch port?"), tr("&Yes"), tr("&No"), QString::null, 0, 1);

        switch (ret)
        {
            case 0:
                return true;
                break;

            case 1:

                break;

          default:
              break;
         }

        return false;
    }

    return true;
}

QString MainWindow::getSettingFromDB(QString settingName)
{
    QSqlQuery query("SELECT value FROM settings WHERE setting_name = '" + settingName + "'");

    while (query.next())
    {
        return query.value(0).toString();
    }

    return "";
}

void MainWindow::setSettingToDB(QString settingName, QString settingValue)
{
    QSqlQuery query("UPDATE settings SET value='" + settingValue + "' WHERE setting_name = '" + settingName + "'");
}

void MainWindow::on_listGroups_currentTextChanged(const QString &currentText)
{
    ui->table_groupPorts->setRowCount(0);

    QSqlQuery query("SELECT addr, port FROM gr_" + currentText);

    while (query.next())
    {
        ui->table_groupPorts->setRowCount(ui->table_groupPorts->rowCount()+1);

        int *row = new int;

        *row = ui->table_groupPorts->rowCount()-1;


        QTableWidgetItem *newItem1 = new QTableWidgetItem(query.value(0).toString());
        QTableWidgetItem *newItem2 = new QTableWidgetItem(query.value(1).toString());

        ui->table_groupPorts->setItem(*row, 0, newItem1);
        ui->table_groupPorts->setItem(*row, 1, newItem2);

        delete row;
    }
}

void MainWindow::on_btn_GroupSwitchOff_clicked()
{
    if (ui->checkbox_GroupControl->isChecked())
    {
        // Выключаем группу

        QSqlQuery query("SELECT addr, port FROM gr_" + ui->cb_GroupSelect->currentText());

        while (query.next())
            worker->addTask(query.value(0).toString(), query.value(1).toString());
    }
    else
    {
        // Выключаем по галочкам

        if (ui->checkbox_p1->isChecked())
            worker->addTask(ui->cb_DeviceSelection->currentText(), "1");

        if (ui->checkbox_p1_2->isChecked())
            worker->addTask(ui->cb_DeviceSelection->currentText(), "2");

        if (ui->checkbox_p1_3->isChecked())
            worker->addTask(ui->cb_DeviceSelection->currentText(), "3");

        if (ui->checkbox_p1_4->isChecked())
            worker->addTask(ui->cb_DeviceSelection->currentText(), "4");

        if (ui->checkbox_p1_5->isChecked())
            worker->addTask(ui->cb_DeviceSelection->currentText(), "5");

        if (ui->checkbox_p1_6->isChecked())
            worker->addTask(ui->cb_DeviceSelection->currentText(), "6");
    }
}

void MainWindow::on_btn_GroupSwitchOn_clicked()
{
    if (ui->checkbox_GroupControl->isChecked())
    {

        // Включаем группу

        QSqlQuery query("SELECT addr, port FROM gr_" + ui->cb_GroupSelect->currentText());

        while (query.next())
            worker->addTask(query.value(0).toString(), query.value(1).toString(), "1");
    }
    else
    {
        // Включаем по галочкам

        if (ui->checkbox_p1->isChecked())
            worker->addTask(ui->cb_DeviceSelection->currentText(), "1", "1");

        if (ui->checkbox_p1_2->isChecked())
            worker->addTask(ui->cb_DeviceSelection->currentText(), "2", "1");

        if (ui->checkbox_p1_3->isChecked())
            worker->addTask(ui->cb_DeviceSelection->currentText(), "3", "1");

        if (ui->checkbox_p1_4->isChecked())
            worker->addTask(ui->cb_DeviceSelection->currentText(), "4", "1");

        if (ui->checkbox_p1_5->isChecked())
            worker->addTask(ui->cb_DeviceSelection->currentText(), "5", "1");

        if (ui->checkbox_p1_6->isChecked())
            worker->addTask(ui->cb_DeviceSelection->currentText(), "6", "1");
    }
}

void MainWindow::on_btn_GroupInverse_clicked()
{
    if (!(ui->checkbox_GroupControl->isChecked()))
    {
        // Инвертируем по глочкам

        if (ui->checkbox_p1->isChecked())
            emit invertPort(ui->cb_DeviceSelection->currentText(), "1");

        if (ui->checkbox_p1_2->isChecked())
            emit invertPort(ui->cb_DeviceSelection->currentText(), "2");

        if (ui->checkbox_p1_3->isChecked())
            emit invertPort(ui->cb_DeviceSelection->currentText(), "3");

        if (ui->checkbox_p1_4->isChecked())
            emit invertPort(ui->cb_DeviceSelection->currentText(), "4");

        if (ui->checkbox_p1_5->isChecked())
            emit invertPort(ui->cb_DeviceSelection->currentText(), "5");

        if (ui->checkbox_p1_6->isChecked())
            emit invertPort(ui->cb_DeviceSelection->currentText(), "6");
    }
    else
    {
        // Инвертируем группу

        emit toLog(tr("Inverting group ") + ui->cb_GroupSelect->currentText());

        QSqlQuery query("SELECT addr, port FROM gr_" + ui->cb_GroupSelect->currentText());

        while (query.next()) {
            emit invertPort(query.value(0).toString(), query.value(1).toString());
        }
    }
}

void MainWindow::on_cb_DeviceSelection_currentIndexChanged(const QString &arg1)
{

}

void MainWindow::on_cb_DeviceSelection_currentTextChanged(const QString &arg1)
{
    worker->addStat(arg1);
}

void MainWindow::on_btn_removeSelectedGroups_clicked()
{
    int ret =  QMessageBox::question(this, tr("Are you shure to delete all of selected ") + tr("groups") + "?", tr("Are you shure to delete all of selected ") + tr("groups") + "?", tr("&Yes"), tr("&No"), QString::null, 0, 1);

    QListIterator<QListWidgetItem *> i(ui->listGroups->selectedItems());
    QListWidgetItem *itemTmp;

    switch (ret)
    {
        case 1:
            break;

        case 0:
            while(i.hasNext())
            {
                itemTmp = i.next();

                toLog(tr("Deleting group") + " " + itemTmp->text() + tr(" from database..."));
                QSqlQuery query("DROP TABLE gr_" + itemTmp->text());
            }

            emit doUpdateGroupsList();

            break;

      default:
          break;
     }
}

void MainWindow::on_btn_removeSelectedPorts_clicked()
{
    int ret =  QMessageBox::question(this, tr("Are you shure to delete all of selected ports?"), tr("Are you shure to delete all of selected ports?"), tr("&Yes"), tr("&No"), QString::null, 0, 1);

    QListIterator<QTableWidgetItem *> i(ui->table_groupPorts->selectedItems());
    QTableWidgetItem *itemTmp; // первый столбец
    QTableWidgetItem *itemTmp2; // второй столбец

    switch (ret)
    {
        case 1:
            break;

        case 0:
            while(i.hasNext())
            {
                itemTmp = i.next();
                itemTmp2 = i.next();

                if (itemTmp->column() == 0)
                {
                    toLog(tr("Deleting port") + " " + itemTmp2->text() + tr(" of device ") + itemTmp->text() + tr(" from database..."));

                    QSqlQuery query("DELETE FROM gr_" + ui->listGroups->currentItem()->text() +" where addr = '" + itemTmp->text() + "' AND port = '" + itemTmp2->text() + "'");


                }
            }

            emit on_listGroups_currentTextChanged(ui->listGroups->currentItem()->text());

            break;

      default:
          break;
     }
}

void MainWindow::on_edit_p1_editingFinished()
{
    emit doUpdatePortLocalName(ui->cb_DeviceSelection->currentText(), "1", ui->edit_p1->text());
}

void MainWindow::on_edit_p1_2_editingFinished()
{
    emit doUpdatePortLocalName(ui->cb_DeviceSelection->currentText(), "2", ui->edit_p1_2->text());
}

void MainWindow::on_edit_p1_3_editingFinished()
{
    emit doUpdatePortLocalName(ui->cb_DeviceSelection->currentText(), "3", ui->edit_p1_3->text());
}

void MainWindow::on_edit_p1_4_editingFinished()
{
    emit doUpdatePortLocalName(ui->cb_DeviceSelection->currentText(), "4", ui->edit_p1_4->text());
}

void MainWindow::on_edit_p1_5_editingFinished()
{
    emit doUpdatePortLocalName(ui->cb_DeviceSelection->currentText(), "5", ui->edit_p1_5->text());
}

void MainWindow::on_edit_p1_6_editingFinished()
{
    emit doUpdatePortLocalName(ui->cb_DeviceSelection->currentText(), "6", ui->edit_p1_6->text());
}

void MainWindow::on_lblAddTaskToSchedule_clicked()
{
    // считаем период повтора
    int repeatTime = 0;
    if (ui->cb_repeatEvery->isChecked())
    {
        repeatTime = repeatTime + ui->sbSeconds->value();
        repeatTime = repeatTime + ui->sbMinutes->value() * 60;
        repeatTime = repeatTime + ui->sbHours->value() * 60 * 60;
    }

    if (ui->rb_addModule->isChecked())
    {
        // добавляем устройство в планировщик


        if (ui->checkbox_sched_p1->isChecked())
            tasker->addTask(ui->cb_scheduledDevice->currentText(), 1, ui->cbScheduleTaskState->currentIndex(), repeatTime, ui->dateTimeEdit_scheduler->dateTime());

        if (ui->checkbox_sched_p2->isChecked())
            tasker->addTask(ui->cb_scheduledDevice->currentText(), 2, ui->cbScheduleTaskState->currentIndex(), repeatTime, ui->dateTimeEdit_scheduler->dateTime());

        if (ui->checkbox_sched_p3->isChecked())
            tasker->addTask(ui->cb_scheduledDevice->currentText(), 3, ui->cbScheduleTaskState->currentIndex(), repeatTime, ui->dateTimeEdit_scheduler->dateTime());

        if (ui->checkbox_sched_p4->isChecked())
            tasker->addTask(ui->cb_scheduledDevice->currentText(), 4, ui->cbScheduleTaskState->currentIndex(), repeatTime, ui->dateTimeEdit_scheduler->dateTime());

        if (ui->checkbox_sched_p5->isChecked())
            tasker->addTask(ui->cb_scheduledDevice->currentText(), 5, ui->cbScheduleTaskState->currentIndex(), repeatTime, ui->dateTimeEdit_scheduler->dateTime());

        if (ui->checkbox_sched_p6->isChecked())
            tasker->addTask(ui->cb_scheduledDevice->currentText(), 6, ui->cbScheduleTaskState->currentIndex(), repeatTime, ui->dateTimeEdit_scheduler->dateTime());
    }
    else if (ui->rb_addGroup->isChecked())
    {
        // добавляем группу в планировщик
        QSqlQuery query("SELECT addr, port FROM gr_" + ui->cb_scheduledGroup->currentText());

        while (query.next())
        {
            tasker->addTask(query.value(0).toString(), query.value(1).toInt(), ui->cbScheduleTaskState->currentIndex(), repeatTime, ui->dateTimeEdit_scheduler->dateTime());
        }
    }
}

void MainWindow::on_cb_repeatEvery_toggled(bool checked)
{
    ui->sbSeconds->setEnabled(checked);
    ui->sbMinutes->setEnabled(checked);
    ui->sbHours->setEnabled(checked);
}

void MainWindow::on_cbEnableTranslation_toggled(bool checked)
{
    setSettingToDB("translation", QString::number(checked));
}

void MainWindow::on_cb_DeviceSelection_editTextChanged(const QString &arg1)
{

}

void MainWindow::on_cbRealtimeUpdateIntervalEnabled_toggled(bool checked)
{
    ui->sbRealtimeUpdateInterval->setEnabled(checked);
    realtimeUpdateTimer.setInterval(ui->sbRealtimeUpdateInterval->value() * 1000);
}

void MainWindow::on_sbRealtimeUpdateInterval_valueChanged(int arg1)
{
    realtimeUpdateTimer.setInterval(arg1 * 1000);
    setSettingToDB("rt_update_interval", QString::number(arg1));
}

void MainWindow::on_lblRemoveSelectedTasks_clicked()
{
    int ret =  QMessageBox::question(this, tr("Warning"), tr("Are you shure to delete all of selected jobs?"), tr("&Yes"), tr("&No"), QString::null, 0, 1);

    if (ret == 1)
        return;

    QListIterator<QTableWidgetItem *> i(ui->tbl_sheduler->selectedItems());

    QTableWidgetItem *itemTmp;  //device
    QTableWidgetItem *itemTmp2; //port
    QTableWidgetItem *itemTmp3; //action
    QTableWidgetItem *itemTmp4; //time
    QTableWidgetItem *itemTmp5; //repeat

    while(i.hasNext())
    {
        itemTmp = i.next();
        itemTmp2 = i.next();
        itemTmp3 = i.next();
        itemTmp4 = i.next();
        itemTmp5 = i.next();

        if (itemTmp->column() == 0)
        {
            tasker->deleteTask(itemTmp->text(), itemTmp2->text().toInt(), itemTmp3->text().toInt(), QDateTime::fromString(itemTmp4->text()));
        }
    }

    itemTmp = 0;
    itemTmp2 = 0;
    itemTmp3 = 0;
    itemTmp4 = 0;
    itemTmp5 = 0;

    delete itemTmp;
    delete itemTmp2;
    delete itemTmp3;
    delete itemTmp4;
    delete itemTmp5;
}

void MainWindow::on_cbRealtimeUpdateIntervalEnabled_clicked()
{

}

void MainWindow::on_sbWorkerIterationTime_valueChanged(int arg1)
{
   if (ui->sbWorkerIterationTime->isVisible())
   {
        setSettingToDB("iterTime", QString::number(arg1));
        emit worker->updateTimerInterval(arg1);
   }
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_cbEnableTranslation_stateChanged(int arg1)
{

}
