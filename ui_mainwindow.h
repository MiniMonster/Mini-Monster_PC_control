/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_16;
    QTabWidget *tabWidget;
    QWidget *tab_Main;
    QVBoxLayout *verticalLayout;
    QLabel *lbl_Device;
    QHBoxLayout *horizontalLayout_18;
    QComboBox *cb_DeviceSelection;
    QLabel *lbl_Temp;
    QLabel *lbl_currentModuleName;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkbox_p1;
    QLabel *lbl_p1;
    QLineEdit *edit_p1;
    QPushButton *btn_p1;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkbox_p1_2;
    QLabel *lbl_p1_2;
    QLineEdit *edit_p1_2;
    QPushButton *btn_p1_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkbox_p1_3;
    QLabel *lbl_p1_3;
    QLineEdit *edit_p1_3;
    QPushButton *btn_p1_3;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkbox_p1_4;
    QLabel *lbl_p1_4;
    QLineEdit *edit_p1_4;
    QPushButton *btn_p1_4;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *checkbox_p1_5;
    QLabel *lbl_p1_5;
    QLineEdit *edit_p1_5;
    QPushButton *btn_p1_5;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *checkbox_p1_6;
    QLabel *lbl_p1_6;
    QLineEdit *edit_p1_6;
    QPushButton *btn_p1_6;
    QVBoxLayout *verticalLayout_11;
    QLabel *lbl_NewGroupName;
    QHBoxLayout *horizontalLayout_8;
    QComboBox *cb_newGroupSelect;
    QPushButton *btn_addSelectedToNewGroup;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *checkbox_GroupControl;
    QComboBox *cb_GroupSelect;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lbl_DeviceNotReachible;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *checkBox_showRequest;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btn_GroupSwitchOff;
    QPushButton *btn_GroupSwitchOn;
    QPushButton *btn_GroupInverse;
    QWidget *tab_Groups;
    QHBoxLayout *horizontalLayout_17;
    QVBoxLayout *verticalLayout_16;
    QLabel *lbl_CurrentGroups;
    QListWidget *listGroups;
    QHBoxLayout *horizontalLayout_15;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *btn_removeSelectedGroups;
    QVBoxLayout *verticalLayout_17;
    QLabel *lbl_devicesInGroup;
    QTableWidget *table_groupPorts;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btn_removeSelectedPorts;
    QWidget *tab_Scheduler;
    QVBoxLayout *verticalLayout_26;
    QLabel *lbl_scheduledTasks;
    QTableWidget *tbl_sheduler;
    QLabel *lbl_emitTime;
    QHBoxLayout *horizontalLayout_20;
    QDateTimeEdit *dateTimeEdit_scheduler;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_23;
    QVBoxLayout *verticalLayout_19;
    QRadioButton *rb_addModule;
    QComboBox *cb_scheduledDevice;
    QLabel *lbl_schedPorts;
    QHBoxLayout *horizontalLayout_19;
    QVBoxLayout *verticalLayout_12;
    QCheckBox *checkbox_sched_p1;
    QCheckBox *checkbox_sched_p2;
    QCheckBox *checkbox_sched_p3;
    QVBoxLayout *verticalLayout_18;
    QCheckBox *checkbox_sched_p4;
    QCheckBox *checkbox_sched_p5;
    QCheckBox *checkbox_sched_p6;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_20;
    QRadioButton *rb_addGroup;
    QComboBox *cb_scheduledGroup;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_9;
    QVBoxLayout *verticalLayout_25;
    QVBoxLayout *verticalLayout_24;
    QCheckBox *cb_repeatEvery;
    QHBoxLayout *horizontalLayout_22;
    QVBoxLayout *verticalLayout_21;
    QLabel *lblRepeatSecs;
    QSpinBox *sbSeconds;
    QVBoxLayout *verticalLayout_22;
    QLabel *lblRepeatMins;
    QSpinBox *sbMinutes;
    QVBoxLayout *verticalLayout_23;
    QLabel *lblRepeatHours;
    QSpinBox *sbHours;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_21;
    QLabel *lblTasksCount;
    QLabel *lblScheduledTasksCount;
    QSpacerItem *horizontalSpacer_11;
    QLabel *lblOperation;
    QComboBox *cbScheduleTaskState;
    QPushButton *lblAddTaskToSchedule;
    QPushButton *lblRemoveSelectedTasks;
    QWidget *tab_Settings;
    QVBoxLayout *verticalLayout_15;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_14;
    QLabel *lbl_moduleAddress;
    QLineEdit *edit_newModuleAddress;
    QLabel *lbl_moduleName;
    QLineEdit *edit_newModuleName;
    QPushButton *btn_addModule;
    QSpacerItem *horizontalSpacer_4;
    QLabel *lbl_currentModules;
    QTableWidget *table_modules;
    QHBoxLayout *horizontalLayout_25;
    QLabel *lblWorkerIterationTime;
    QSpinBox *sbWorkerIterationTime;
    QSpacerItem *horizontalSpacer_13;
    QHBoxLayout *horizontalLayout_24;
    QCheckBox *cbRealtimeUpdateIntervalEnabled;
    QSpinBox *sbRealtimeUpdateInterval;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_13;
    QCheckBox *cbEnableTranslation;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btn_removeSelectedModules;
    QWidget *tab_Log;
    QVBoxLayout *verticalLayout_13;
    QLabel *lbl_logMessages;
    QTextEdit *text_Log;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *checkBox_logDisabled;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_logClear;
    QPushButton *btn_LogSaveAs;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(596, 566);
        QIcon icon;
        icon.addFile(QStringLiteral(":/1.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_16 = new QHBoxLayout(centralWidget);
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_Main = new QWidget();
        tab_Main->setObjectName(QStringLiteral("tab_Main"));
        verticalLayout = new QVBoxLayout(tab_Main);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lbl_Device = new QLabel(tab_Main);
        lbl_Device->setObjectName(QStringLiteral("lbl_Device"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lbl_Device->sizePolicy().hasHeightForWidth());
        lbl_Device->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(lbl_Device);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        cb_DeviceSelection = new QComboBox(tab_Main);
        cb_DeviceSelection->setObjectName(QStringLiteral("cb_DeviceSelection"));
        cb_DeviceSelection->setEditable(false);
        cb_DeviceSelection->setModelColumn(0);

        horizontalLayout_18->addWidget(cb_DeviceSelection);

        lbl_Temp = new QLabel(tab_Main);
        lbl_Temp->setObjectName(QStringLiteral("lbl_Temp"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lbl_Temp->sizePolicy().hasHeightForWidth());
        lbl_Temp->setSizePolicy(sizePolicy1);
        lbl_Temp->setMaximumSize(QSize(16777215, 16777215));
        lbl_Temp->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_18->addWidget(lbl_Temp);


        verticalLayout->addLayout(horizontalLayout_18);

        lbl_currentModuleName = new QLabel(tab_Main);
        lbl_currentModuleName->setObjectName(QStringLiteral("lbl_currentModuleName"));
        QFont font;
        font.setPointSize(10);
        lbl_currentModuleName->setFont(font);

        verticalLayout->addWidget(lbl_currentModuleName);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkbox_p1 = new QCheckBox(tab_Main);
        checkbox_p1->setObjectName(QStringLiteral("checkbox_p1"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(checkbox_p1->sizePolicy().hasHeightForWidth());
        checkbox_p1->setSizePolicy(sizePolicy2);
        checkbox_p1->setText(QStringLiteral(""));

        horizontalLayout->addWidget(checkbox_p1);

        lbl_p1 = new QLabel(tab_Main);
        lbl_p1->setObjectName(QStringLiteral("lbl_p1"));

        horizontalLayout->addWidget(lbl_p1);

        edit_p1 = new QLineEdit(tab_Main);
        edit_p1->setObjectName(QStringLiteral("edit_p1"));
        edit_p1->setText(QStringLiteral(""));

        horizontalLayout->addWidget(edit_p1);


        verticalLayout_2->addLayout(horizontalLayout);

        btn_p1 = new QPushButton(tab_Main);
        btn_p1->setObjectName(QStringLiteral("btn_p1"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btn_p1->sizePolicy().hasHeightForWidth());
        btn_p1->setSizePolicy(sizePolicy3);
        btn_p1->setMinimumSize(QSize(0, 50));
        btn_p1->setAutoFillBackground(false);
        btn_p1->setCheckable(false);
        btn_p1->setFlat(false);

        verticalLayout_2->addWidget(btn_p1);


        verticalLayout_8->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        checkbox_p1_2 = new QCheckBox(tab_Main);
        checkbox_p1_2->setObjectName(QStringLiteral("checkbox_p1_2"));
        sizePolicy2.setHeightForWidth(checkbox_p1_2->sizePolicy().hasHeightForWidth());
        checkbox_p1_2->setSizePolicy(sizePolicy2);
        checkbox_p1_2->setText(QStringLiteral(""));

        horizontalLayout_2->addWidget(checkbox_p1_2);

        lbl_p1_2 = new QLabel(tab_Main);
        lbl_p1_2->setObjectName(QStringLiteral("lbl_p1_2"));

        horizontalLayout_2->addWidget(lbl_p1_2);

        edit_p1_2 = new QLineEdit(tab_Main);
        edit_p1_2->setObjectName(QStringLiteral("edit_p1_2"));
        edit_p1_2->setText(QStringLiteral(""));

        horizontalLayout_2->addWidget(edit_p1_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        btn_p1_2 = new QPushButton(tab_Main);
        btn_p1_2->setObjectName(QStringLiteral("btn_p1_2"));
        sizePolicy3.setHeightForWidth(btn_p1_2->sizePolicy().hasHeightForWidth());
        btn_p1_2->setSizePolicy(sizePolicy3);
        btn_p1_2->setMinimumSize(QSize(0, 50));
        btn_p1_2->setAutoFillBackground(false);
        btn_p1_2->setFlat(false);

        verticalLayout_3->addWidget(btn_p1_2);


        verticalLayout_8->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        checkbox_p1_3 = new QCheckBox(tab_Main);
        checkbox_p1_3->setObjectName(QStringLiteral("checkbox_p1_3"));
        sizePolicy2.setHeightForWidth(checkbox_p1_3->sizePolicy().hasHeightForWidth());
        checkbox_p1_3->setSizePolicy(sizePolicy2);
        checkbox_p1_3->setText(QStringLiteral(""));

        horizontalLayout_3->addWidget(checkbox_p1_3);

        lbl_p1_3 = new QLabel(tab_Main);
        lbl_p1_3->setObjectName(QStringLiteral("lbl_p1_3"));

        horizontalLayout_3->addWidget(lbl_p1_3);

        edit_p1_3 = new QLineEdit(tab_Main);
        edit_p1_3->setObjectName(QStringLiteral("edit_p1_3"));
        edit_p1_3->setText(QStringLiteral(""));

        horizontalLayout_3->addWidget(edit_p1_3);


        verticalLayout_4->addLayout(horizontalLayout_3);

        btn_p1_3 = new QPushButton(tab_Main);
        btn_p1_3->setObjectName(QStringLiteral("btn_p1_3"));
        sizePolicy3.setHeightForWidth(btn_p1_3->sizePolicy().hasHeightForWidth());
        btn_p1_3->setSizePolicy(sizePolicy3);
        btn_p1_3->setMinimumSize(QSize(0, 50));
        btn_p1_3->setAutoFillBackground(false);
        btn_p1_3->setFlat(false);

        verticalLayout_4->addWidget(btn_p1_3);


        verticalLayout_8->addLayout(verticalLayout_4);


        horizontalLayout_7->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        checkbox_p1_4 = new QCheckBox(tab_Main);
        checkbox_p1_4->setObjectName(QStringLiteral("checkbox_p1_4"));
        sizePolicy2.setHeightForWidth(checkbox_p1_4->sizePolicy().hasHeightForWidth());
        checkbox_p1_4->setSizePolicy(sizePolicy2);
        checkbox_p1_4->setText(QStringLiteral(""));

        horizontalLayout_4->addWidget(checkbox_p1_4);

        lbl_p1_4 = new QLabel(tab_Main);
        lbl_p1_4->setObjectName(QStringLiteral("lbl_p1_4"));

        horizontalLayout_4->addWidget(lbl_p1_4);

        edit_p1_4 = new QLineEdit(tab_Main);
        edit_p1_4->setObjectName(QStringLiteral("edit_p1_4"));
        edit_p1_4->setText(QStringLiteral(""));

        horizontalLayout_4->addWidget(edit_p1_4);


        verticalLayout_5->addLayout(horizontalLayout_4);

        btn_p1_4 = new QPushButton(tab_Main);
        btn_p1_4->setObjectName(QStringLiteral("btn_p1_4"));
        sizePolicy3.setHeightForWidth(btn_p1_4->sizePolicy().hasHeightForWidth());
        btn_p1_4->setSizePolicy(sizePolicy3);
        btn_p1_4->setMinimumSize(QSize(0, 50));
        btn_p1_4->setAutoFillBackground(false);
        btn_p1_4->setFlat(false);

        verticalLayout_5->addWidget(btn_p1_4);


        verticalLayout_9->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        checkbox_p1_5 = new QCheckBox(tab_Main);
        checkbox_p1_5->setObjectName(QStringLiteral("checkbox_p1_5"));
        sizePolicy2.setHeightForWidth(checkbox_p1_5->sizePolicy().hasHeightForWidth());
        checkbox_p1_5->setSizePolicy(sizePolicy2);
        checkbox_p1_5->setText(QStringLiteral(""));

        horizontalLayout_5->addWidget(checkbox_p1_5);

        lbl_p1_5 = new QLabel(tab_Main);
        lbl_p1_5->setObjectName(QStringLiteral("lbl_p1_5"));

        horizontalLayout_5->addWidget(lbl_p1_5);

        edit_p1_5 = new QLineEdit(tab_Main);
        edit_p1_5->setObjectName(QStringLiteral("edit_p1_5"));
        edit_p1_5->setText(QStringLiteral(""));

        horizontalLayout_5->addWidget(edit_p1_5);


        verticalLayout_6->addLayout(horizontalLayout_5);

        btn_p1_5 = new QPushButton(tab_Main);
        btn_p1_5->setObjectName(QStringLiteral("btn_p1_5"));
        sizePolicy3.setHeightForWidth(btn_p1_5->sizePolicy().hasHeightForWidth());
        btn_p1_5->setSizePolicy(sizePolicy3);
        btn_p1_5->setMinimumSize(QSize(0, 50));
        btn_p1_5->setAutoFillBackground(false);
        btn_p1_5->setFlat(false);

        verticalLayout_6->addWidget(btn_p1_5);


        verticalLayout_9->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        checkbox_p1_6 = new QCheckBox(tab_Main);
        checkbox_p1_6->setObjectName(QStringLiteral("checkbox_p1_6"));
        sizePolicy2.setHeightForWidth(checkbox_p1_6->sizePolicy().hasHeightForWidth());
        checkbox_p1_6->setSizePolicy(sizePolicy2);
        checkbox_p1_6->setText(QStringLiteral(""));

        horizontalLayout_6->addWidget(checkbox_p1_6);

        lbl_p1_6 = new QLabel(tab_Main);
        lbl_p1_6->setObjectName(QStringLiteral("lbl_p1_6"));

        horizontalLayout_6->addWidget(lbl_p1_6);

        edit_p1_6 = new QLineEdit(tab_Main);
        edit_p1_6->setObjectName(QStringLiteral("edit_p1_6"));
        edit_p1_6->setText(QStringLiteral(""));

        horizontalLayout_6->addWidget(edit_p1_6);


        verticalLayout_7->addLayout(horizontalLayout_6);

        btn_p1_6 = new QPushButton(tab_Main);
        btn_p1_6->setObjectName(QStringLiteral("btn_p1_6"));
        sizePolicy3.setHeightForWidth(btn_p1_6->sizePolicy().hasHeightForWidth());
        btn_p1_6->setSizePolicy(sizePolicy3);
        btn_p1_6->setMinimumSize(QSize(0, 50));
        btn_p1_6->setAutoFillBackground(false);
        btn_p1_6->setFlat(false);

        verticalLayout_7->addWidget(btn_p1_6);


        verticalLayout_9->addLayout(verticalLayout_7);


        horizontalLayout_7->addLayout(verticalLayout_9);


        verticalLayout->addLayout(horizontalLayout_7);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        lbl_NewGroupName = new QLabel(tab_Main);
        lbl_NewGroupName->setObjectName(QStringLiteral("lbl_NewGroupName"));

        verticalLayout_11->addWidget(lbl_NewGroupName);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        cb_newGroupSelect = new QComboBox(tab_Main);
        cb_newGroupSelect->setObjectName(QStringLiteral("cb_newGroupSelect"));
        cb_newGroupSelect->setEditable(true);

        horizontalLayout_8->addWidget(cb_newGroupSelect);

        btn_addSelectedToNewGroup = new QPushButton(tab_Main);
        btn_addSelectedToNewGroup->setObjectName(QStringLiteral("btn_addSelectedToNewGroup"));

        horizontalLayout_8->addWidget(btn_addSelectedToNewGroup);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);


        verticalLayout_11->addLayout(horizontalLayout_8);


        verticalLayout->addLayout(verticalLayout_11);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        checkbox_GroupControl = new QCheckBox(tab_Main);
        checkbox_GroupControl->setObjectName(QStringLiteral("checkbox_GroupControl"));

        horizontalLayout_9->addWidget(checkbox_GroupControl);

        cb_GroupSelect = new QComboBox(tab_Main);
        cb_GroupSelect->setObjectName(QStringLiteral("cb_GroupSelect"));

        horizontalLayout_9->addWidget(cb_GroupSelect);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);


        verticalLayout_10->addLayout(horizontalLayout_9);


        verticalLayout->addLayout(verticalLayout_10);

        lbl_DeviceNotReachible = new QLabel(tab_Main);
        lbl_DeviceNotReachible->setObjectName(QStringLiteral("lbl_DeviceNotReachible"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        lbl_DeviceNotReachible->setFont(font1);
        lbl_DeviceNotReachible->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        lbl_DeviceNotReachible->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lbl_DeviceNotReachible);

        verticalSpacer = new QSpacerItem(20, 23, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        checkBox_showRequest = new QCheckBox(tab_Main);
        checkBox_showRequest->setObjectName(QStringLiteral("checkBox_showRequest"));

        horizontalLayout_12->addWidget(checkBox_showRequest);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_5);

        btn_GroupSwitchOff = new QPushButton(tab_Main);
        btn_GroupSwitchOff->setObjectName(QStringLiteral("btn_GroupSwitchOff"));

        horizontalLayout_12->addWidget(btn_GroupSwitchOff);

        btn_GroupSwitchOn = new QPushButton(tab_Main);
        btn_GroupSwitchOn->setObjectName(QStringLiteral("btn_GroupSwitchOn"));

        horizontalLayout_12->addWidget(btn_GroupSwitchOn);

        btn_GroupInverse = new QPushButton(tab_Main);
        btn_GroupInverse->setObjectName(QStringLiteral("btn_GroupInverse"));

        horizontalLayout_12->addWidget(btn_GroupInverse);


        verticalLayout->addLayout(horizontalLayout_12);

        tabWidget->addTab(tab_Main, QString());
        tab_Groups = new QWidget();
        tab_Groups->setObjectName(QStringLiteral("tab_Groups"));
        horizontalLayout_17 = new QHBoxLayout(tab_Groups);
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        lbl_CurrentGroups = new QLabel(tab_Groups);
        lbl_CurrentGroups->setObjectName(QStringLiteral("lbl_CurrentGroups"));

        verticalLayout_16->addWidget(lbl_CurrentGroups);

        listGroups = new QListWidget(tab_Groups);
        listGroups->setObjectName(QStringLiteral("listGroups"));
        listGroups->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listGroups->setSelectionMode(QAbstractItemView::SingleSelection);
        listGroups->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_16->addWidget(listGroups);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_7);

        btn_removeSelectedGroups = new QPushButton(tab_Groups);
        btn_removeSelectedGroups->setObjectName(QStringLiteral("btn_removeSelectedGroups"));

        horizontalLayout_15->addWidget(btn_removeSelectedGroups);


        verticalLayout_16->addLayout(horizontalLayout_15);


        horizontalLayout_17->addLayout(verticalLayout_16);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        lbl_devicesInGroup = new QLabel(tab_Groups);
        lbl_devicesInGroup->setObjectName(QStringLiteral("lbl_devicesInGroup"));

        verticalLayout_17->addWidget(lbl_devicesInGroup);

        table_groupPorts = new QTableWidget(tab_Groups);
        if (table_groupPorts->columnCount() < 2)
            table_groupPorts->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_groupPorts->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_groupPorts->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        table_groupPorts->setObjectName(QStringLiteral("table_groupPorts"));
        table_groupPorts->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table_groupPorts->setSelectionMode(QAbstractItemView::MultiSelection);
        table_groupPorts->setSelectionBehavior(QAbstractItemView::SelectRows);
        table_groupPorts->verticalHeader()->setVisible(false);

        verticalLayout_17->addWidget(table_groupPorts);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_8);

        btn_removeSelectedPorts = new QPushButton(tab_Groups);
        btn_removeSelectedPorts->setObjectName(QStringLiteral("btn_removeSelectedPorts"));

        horizontalLayout_14->addWidget(btn_removeSelectedPorts);


        verticalLayout_17->addLayout(horizontalLayout_14);


        horizontalLayout_17->addLayout(verticalLayout_17);

        tabWidget->addTab(tab_Groups, QString());
        tab_Scheduler = new QWidget();
        tab_Scheduler->setObjectName(QStringLiteral("tab_Scheduler"));
        verticalLayout_26 = new QVBoxLayout(tab_Scheduler);
        verticalLayout_26->setSpacing(6);
        verticalLayout_26->setContentsMargins(11, 11, 11, 11);
        verticalLayout_26->setObjectName(QStringLiteral("verticalLayout_26"));
        lbl_scheduledTasks = new QLabel(tab_Scheduler);
        lbl_scheduledTasks->setObjectName(QStringLiteral("lbl_scheduledTasks"));

        verticalLayout_26->addWidget(lbl_scheduledTasks);

        tbl_sheduler = new QTableWidget(tab_Scheduler);
        if (tbl_sheduler->columnCount() < 5)
            tbl_sheduler->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tbl_sheduler->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tbl_sheduler->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tbl_sheduler->setHorizontalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tbl_sheduler->setHorizontalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tbl_sheduler->setHorizontalHeaderItem(4, __qtablewidgetitem6);
        tbl_sheduler->setObjectName(QStringLiteral("tbl_sheduler"));
        tbl_sheduler->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tbl_sheduler->setSelectionMode(QAbstractItemView::MultiSelection);
        tbl_sheduler->setSelectionBehavior(QAbstractItemView::SelectRows);
        tbl_sheduler->setSortingEnabled(true);
        tbl_sheduler->verticalHeader()->setVisible(false);

        verticalLayout_26->addWidget(tbl_sheduler);

        lbl_emitTime = new QLabel(tab_Scheduler);
        lbl_emitTime->setObjectName(QStringLiteral("lbl_emitTime"));

        verticalLayout_26->addWidget(lbl_emitTime);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        dateTimeEdit_scheduler = new QDateTimeEdit(tab_Scheduler);
        dateTimeEdit_scheduler->setObjectName(QStringLiteral("dateTimeEdit_scheduler"));
        dateTimeEdit_scheduler->setInputMethodHints(Qt::ImhPreferNumbers);
        dateTimeEdit_scheduler->setCalendarPopup(true);

        horizontalLayout_20->addWidget(dateTimeEdit_scheduler);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_10);


        verticalLayout_26->addLayout(horizontalLayout_20);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setSpacing(6);
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        rb_addModule = new QRadioButton(tab_Scheduler);
        rb_addModule->setObjectName(QStringLiteral("rb_addModule"));
        rb_addModule->setChecked(true);

        verticalLayout_19->addWidget(rb_addModule);

        cb_scheduledDevice = new QComboBox(tab_Scheduler);
        cb_scheduledDevice->setObjectName(QStringLiteral("cb_scheduledDevice"));

        verticalLayout_19->addWidget(cb_scheduledDevice);

        lbl_schedPorts = new QLabel(tab_Scheduler);
        lbl_schedPorts->setObjectName(QStringLiteral("lbl_schedPorts"));
        sizePolicy.setHeightForWidth(lbl_schedPorts->sizePolicy().hasHeightForWidth());
        lbl_schedPorts->setSizePolicy(sizePolicy);

        verticalLayout_19->addWidget(lbl_schedPorts);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        checkbox_sched_p1 = new QCheckBox(tab_Scheduler);
        checkbox_sched_p1->setObjectName(QStringLiteral("checkbox_sched_p1"));
        checkbox_sched_p1->setText(QStringLiteral("1"));

        verticalLayout_12->addWidget(checkbox_sched_p1);

        checkbox_sched_p2 = new QCheckBox(tab_Scheduler);
        checkbox_sched_p2->setObjectName(QStringLiteral("checkbox_sched_p2"));
        checkbox_sched_p2->setText(QStringLiteral("2"));

        verticalLayout_12->addWidget(checkbox_sched_p2);

        checkbox_sched_p3 = new QCheckBox(tab_Scheduler);
        checkbox_sched_p3->setObjectName(QStringLiteral("checkbox_sched_p3"));
        checkbox_sched_p3->setText(QStringLiteral("3"));

        verticalLayout_12->addWidget(checkbox_sched_p3);


        horizontalLayout_19->addLayout(verticalLayout_12);

        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setSpacing(6);
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        checkbox_sched_p4 = new QCheckBox(tab_Scheduler);
        checkbox_sched_p4->setObjectName(QStringLiteral("checkbox_sched_p4"));
        checkbox_sched_p4->setText(QStringLiteral("4"));

        verticalLayout_18->addWidget(checkbox_sched_p4);

        checkbox_sched_p5 = new QCheckBox(tab_Scheduler);
        checkbox_sched_p5->setObjectName(QStringLiteral("checkbox_sched_p5"));
        checkbox_sched_p5->setText(QStringLiteral("5"));

        verticalLayout_18->addWidget(checkbox_sched_p5);

        checkbox_sched_p6 = new QCheckBox(tab_Scheduler);
        checkbox_sched_p6->setObjectName(QStringLiteral("checkbox_sched_p6"));
        checkbox_sched_p6->setText(QStringLiteral("6"));

        verticalLayout_18->addWidget(checkbox_sched_p6);


        horizontalLayout_19->addLayout(verticalLayout_18);


        verticalLayout_19->addLayout(horizontalLayout_19);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_19->addItem(verticalSpacer_4);


        horizontalLayout_23->addLayout(verticalLayout_19);

        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setSpacing(6);
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        rb_addGroup = new QRadioButton(tab_Scheduler);
        rb_addGroup->setObjectName(QStringLiteral("rb_addGroup"));

        verticalLayout_20->addWidget(rb_addGroup);

        cb_scheduledGroup = new QComboBox(tab_Scheduler);
        cb_scheduledGroup->setObjectName(QStringLiteral("cb_scheduledGroup"));

        verticalLayout_20->addWidget(cb_scheduledGroup);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_20->addItem(verticalSpacer_2);


        horizontalLayout_23->addLayout(verticalLayout_20);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_23->addItem(horizontalSpacer_9);

        verticalLayout_25 = new QVBoxLayout();
        verticalLayout_25->setSpacing(6);
        verticalLayout_25->setObjectName(QStringLiteral("verticalLayout_25"));
        verticalLayout_24 = new QVBoxLayout();
        verticalLayout_24->setSpacing(6);
        verticalLayout_24->setObjectName(QStringLiteral("verticalLayout_24"));
        cb_repeatEvery = new QCheckBox(tab_Scheduler);
        cb_repeatEvery->setObjectName(QStringLiteral("cb_repeatEvery"));

        verticalLayout_24->addWidget(cb_repeatEvery);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setSpacing(6);
        verticalLayout_21->setObjectName(QStringLiteral("verticalLayout_21"));
        lblRepeatSecs = new QLabel(tab_Scheduler);
        lblRepeatSecs->setObjectName(QStringLiteral("lblRepeatSecs"));

        verticalLayout_21->addWidget(lblRepeatSecs);

        sbSeconds = new QSpinBox(tab_Scheduler);
        sbSeconds->setObjectName(QStringLiteral("sbSeconds"));
        sbSeconds->setEnabled(false);
        sbSeconds->setMinimum(0);
        sbSeconds->setMaximum(60);

        verticalLayout_21->addWidget(sbSeconds);


        horizontalLayout_22->addLayout(verticalLayout_21);

        verticalLayout_22 = new QVBoxLayout();
        verticalLayout_22->setSpacing(6);
        verticalLayout_22->setObjectName(QStringLiteral("verticalLayout_22"));
        lblRepeatMins = new QLabel(tab_Scheduler);
        lblRepeatMins->setObjectName(QStringLiteral("lblRepeatMins"));

        verticalLayout_22->addWidget(lblRepeatMins);

        sbMinutes = new QSpinBox(tab_Scheduler);
        sbMinutes->setObjectName(QStringLiteral("sbMinutes"));
        sbMinutes->setEnabled(false);
        sbMinutes->setMaximum(60);

        verticalLayout_22->addWidget(sbMinutes);


        horizontalLayout_22->addLayout(verticalLayout_22);

        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setSpacing(6);
        verticalLayout_23->setObjectName(QStringLiteral("verticalLayout_23"));
        lblRepeatHours = new QLabel(tab_Scheduler);
        lblRepeatHours->setObjectName(QStringLiteral("lblRepeatHours"));

        verticalLayout_23->addWidget(lblRepeatHours);

        sbHours = new QSpinBox(tab_Scheduler);
        sbHours->setObjectName(QStringLiteral("sbHours"));
        sbHours->setEnabled(false);
        sbHours->setMaximum(168);

        verticalLayout_23->addWidget(sbHours);


        horizontalLayout_22->addLayout(verticalLayout_23);


        verticalLayout_24->addLayout(horizontalLayout_22);


        verticalLayout_25->addLayout(verticalLayout_24);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_25->addItem(verticalSpacer_3);


        horizontalLayout_23->addLayout(verticalLayout_25);


        verticalLayout_26->addLayout(horizontalLayout_23);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        lblTasksCount = new QLabel(tab_Scheduler);
        lblTasksCount->setObjectName(QStringLiteral("lblTasksCount"));

        horizontalLayout_21->addWidget(lblTasksCount);

        lblScheduledTasksCount = new QLabel(tab_Scheduler);
        lblScheduledTasksCount->setObjectName(QStringLiteral("lblScheduledTasksCount"));

        horizontalLayout_21->addWidget(lblScheduledTasksCount);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_11);

        lblOperation = new QLabel(tab_Scheduler);
        lblOperation->setObjectName(QStringLiteral("lblOperation"));

        horizontalLayout_21->addWidget(lblOperation);

        cbScheduleTaskState = new QComboBox(tab_Scheduler);
        cbScheduleTaskState->setObjectName(QStringLiteral("cbScheduleTaskState"));

        horizontalLayout_21->addWidget(cbScheduleTaskState);

        lblAddTaskToSchedule = new QPushButton(tab_Scheduler);
        lblAddTaskToSchedule->setObjectName(QStringLiteral("lblAddTaskToSchedule"));

        horizontalLayout_21->addWidget(lblAddTaskToSchedule);

        lblRemoveSelectedTasks = new QPushButton(tab_Scheduler);
        lblRemoveSelectedTasks->setObjectName(QStringLiteral("lblRemoveSelectedTasks"));

        horizontalLayout_21->addWidget(lblRemoveSelectedTasks);


        verticalLayout_26->addLayout(horizontalLayout_21);

        tabWidget->addTab(tab_Scheduler, QString());
        tab_Settings = new QWidget();
        tab_Settings->setObjectName(QStringLiteral("tab_Settings"));
        verticalLayout_15 = new QVBoxLayout(tab_Settings);
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        lbl_moduleAddress = new QLabel(tab_Settings);
        lbl_moduleAddress->setObjectName(QStringLiteral("lbl_moduleAddress"));

        verticalLayout_14->addWidget(lbl_moduleAddress);

        edit_newModuleAddress = new QLineEdit(tab_Settings);
        edit_newModuleAddress->setObjectName(QStringLiteral("edit_newModuleAddress"));

        verticalLayout_14->addWidget(edit_newModuleAddress);

        lbl_moduleName = new QLabel(tab_Settings);
        lbl_moduleName->setObjectName(QStringLiteral("lbl_moduleName"));
        sizePolicy.setHeightForWidth(lbl_moduleName->sizePolicy().hasHeightForWidth());
        lbl_moduleName->setSizePolicy(sizePolicy);

        verticalLayout_14->addWidget(lbl_moduleName);

        edit_newModuleName = new QLineEdit(tab_Settings);
        edit_newModuleName->setObjectName(QStringLiteral("edit_newModuleName"));

        verticalLayout_14->addWidget(edit_newModuleName);


        horizontalLayout_11->addLayout(verticalLayout_14);

        btn_addModule = new QPushButton(tab_Settings);
        btn_addModule->setObjectName(QStringLiteral("btn_addModule"));
        sizePolicy2.setHeightForWidth(btn_addModule->sizePolicy().hasHeightForWidth());
        btn_addModule->setSizePolicy(sizePolicy2);

        horizontalLayout_11->addWidget(btn_addModule);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_4);


        verticalLayout_15->addLayout(horizontalLayout_11);

        lbl_currentModules = new QLabel(tab_Settings);
        lbl_currentModules->setObjectName(QStringLiteral("lbl_currentModules"));

        verticalLayout_15->addWidget(lbl_currentModules);

        table_modules = new QTableWidget(tab_Settings);
        if (table_modules->columnCount() < 16)
            table_modules->setColumnCount(16);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table_modules->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        table_modules->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        table_modules->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        table_modules->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        table_modules->setHorizontalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        table_modules->setHorizontalHeaderItem(5, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        table_modules->setHorizontalHeaderItem(6, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        table_modules->setHorizontalHeaderItem(7, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        table_modules->setHorizontalHeaderItem(8, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        table_modules->setHorizontalHeaderItem(9, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        table_modules->setHorizontalHeaderItem(10, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        table_modules->setHorizontalHeaderItem(11, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        table_modules->setHorizontalHeaderItem(12, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        table_modules->setHorizontalHeaderItem(13, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        table_modules->setHorizontalHeaderItem(14, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        table_modules->setHorizontalHeaderItem(15, __qtablewidgetitem22);
        table_modules->setObjectName(QStringLiteral("table_modules"));
        table_modules->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table_modules->setAlternatingRowColors(false);
        table_modules->setSelectionMode(QAbstractItemView::MultiSelection);
        table_modules->setSelectionBehavior(QAbstractItemView::SelectRows);
        table_modules->setCornerButtonEnabled(false);
        table_modules->setRowCount(0);
        table_modules->verticalHeader()->setVisible(false);

        verticalLayout_15->addWidget(table_modules);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        lblWorkerIterationTime = new QLabel(tab_Settings);
        lblWorkerIterationTime->setObjectName(QStringLiteral("lblWorkerIterationTime"));

        horizontalLayout_25->addWidget(lblWorkerIterationTime);

        sbWorkerIterationTime = new QSpinBox(tab_Settings);
        sbWorkerIterationTime->setObjectName(QStringLiteral("sbWorkerIterationTime"));
        sbWorkerIterationTime->setMinimumSize(QSize(55, 0));
        sbWorkerIterationTime->setMinimum(100);
        sbWorkerIterationTime->setMaximum(5000);
        sbWorkerIterationTime->setSingleStep(100);

        horizontalLayout_25->addWidget(sbWorkerIterationTime);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_25->addItem(horizontalSpacer_13);


        verticalLayout_15->addLayout(horizontalLayout_25);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        cbRealtimeUpdateIntervalEnabled = new QCheckBox(tab_Settings);
        cbRealtimeUpdateIntervalEnabled->setObjectName(QStringLiteral("cbRealtimeUpdateIntervalEnabled"));

        horizontalLayout_24->addWidget(cbRealtimeUpdateIntervalEnabled);

        sbRealtimeUpdateInterval = new QSpinBox(tab_Settings);
        sbRealtimeUpdateInterval->setObjectName(QStringLiteral("sbRealtimeUpdateInterval"));
        sbRealtimeUpdateInterval->setMinimum(2);
        sbRealtimeUpdateInterval->setMaximum(120);

        horizontalLayout_24->addWidget(sbRealtimeUpdateInterval);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_24->addItem(horizontalSpacer_12);


        verticalLayout_15->addLayout(horizontalLayout_24);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        cbEnableTranslation = new QCheckBox(tab_Settings);
        cbEnableTranslation->setObjectName(QStringLiteral("cbEnableTranslation"));

        horizontalLayout_13->addWidget(cbEnableTranslation);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_6);

        btn_removeSelectedModules = new QPushButton(tab_Settings);
        btn_removeSelectedModules->setObjectName(QStringLiteral("btn_removeSelectedModules"));

        horizontalLayout_13->addWidget(btn_removeSelectedModules);


        verticalLayout_15->addLayout(horizontalLayout_13);

        tabWidget->addTab(tab_Settings, QString());
        tab_Log = new QWidget();
        tab_Log->setObjectName(QStringLiteral("tab_Log"));
        verticalLayout_13 = new QVBoxLayout(tab_Log);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        lbl_logMessages = new QLabel(tab_Log);
        lbl_logMessages->setObjectName(QStringLiteral("lbl_logMessages"));

        verticalLayout_13->addWidget(lbl_logMessages);

        text_Log = new QTextEdit(tab_Log);
        text_Log->setObjectName(QStringLiteral("text_Log"));
        text_Log->setReadOnly(true);

        verticalLayout_13->addWidget(text_Log);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        checkBox_logDisabled = new QCheckBox(tab_Log);
        checkBox_logDisabled->setObjectName(QStringLiteral("checkBox_logDisabled"));

        horizontalLayout_10->addWidget(checkBox_logDisabled);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_3);

        btn_logClear = new QPushButton(tab_Log);
        btn_logClear->setObjectName(QStringLiteral("btn_logClear"));

        horizontalLayout_10->addWidget(btn_logClear);

        btn_LogSaveAs = new QPushButton(tab_Log);
        btn_LogSaveAs->setObjectName(QStringLiteral("btn_LogSaveAs"));

        horizontalLayout_10->addWidget(btn_LogSaveAs);


        verticalLayout_13->addLayout(horizontalLayout_10);

        tabWidget->addTab(tab_Log, QString());

        horizontalLayout_16->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setStyleSheet(QStringLiteral(""));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QMiniMonsterControl", 0));
        action->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\262 \321\204\320\260\320\271\320\273", 0));
        lbl_Device->setText(QApplication::translate("MainWindow", "Module (You can add new one in \"Settings\" tab above):", 0));
        cb_DeviceSelection->setCurrentText(QString());
        lbl_Temp->setText(QApplication::translate("MainWindow", "t", 0));
        lbl_currentModuleName->setText(QApplication::translate("MainWindow", "Current module name here", 0));
        lbl_p1->setText(QApplication::translate("MainWindow", "Port name:", 0));
        btn_p1->setText(QApplication::translate("MainWindow", "Port state (Click to change)", 0));
        lbl_p1_2->setText(QApplication::translate("MainWindow", "Port name:", 0));
        btn_p1_2->setText(QApplication::translate("MainWindow", "Port state (Click to change)", 0));
        lbl_p1_3->setText(QApplication::translate("MainWindow", "Port name:", 0));
        btn_p1_3->setText(QApplication::translate("MainWindow", "Port state (Click to change)", 0));
        lbl_p1_4->setText(QApplication::translate("MainWindow", "Port name:", 0));
        btn_p1_4->setText(QApplication::translate("MainWindow", "Port state (Click to change)", 0));
        lbl_p1_5->setText(QApplication::translate("MainWindow", "Port name:", 0));
        btn_p1_5->setText(QApplication::translate("MainWindow", "Port state (Click to change)", 0));
        lbl_p1_6->setText(QApplication::translate("MainWindow", "Port name:", 0));
        btn_p1_6->setText(QApplication::translate("MainWindow", "Port state (Click to change)", 0));
        lbl_NewGroupName->setText(QApplication::translate("MainWindow", "Group name:", 0));
        btn_addSelectedToNewGroup->setText(QApplication::translate("MainWindow", "Add checked ports to group", 0));
        checkbox_GroupControl->setText(QApplication::translate("MainWindow", "Group control:", 0));
        lbl_DeviceNotReachible->setText(QApplication::translate("MainWindow", "Device not reachable!", 0));
        checkBox_showRequest->setText(QApplication::translate("MainWindow", "Prompt me when i want to switch port", 0));
        btn_GroupSwitchOff->setText(QApplication::translate("MainWindow", "Switch off", 0));
        btn_GroupSwitchOn->setText(QApplication::translate("MainWindow", "Switch on", 0));
        btn_GroupInverse->setText(QApplication::translate("MainWindow", "Inverse", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_Main), QApplication::translate("MainWindow", "Control", 0));
        lbl_CurrentGroups->setText(QApplication::translate("MainWindow", "Current groups:", 0));
        btn_removeSelectedGroups->setText(QApplication::translate("MainWindow", "Remove selected groups", 0));
        lbl_devicesInGroup->setText(QApplication::translate("MainWindow", "Ports in selected group:", 0));
        QTableWidgetItem *___qtablewidgetitem = table_groupPorts->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Device", 0));
        QTableWidgetItem *___qtablewidgetitem1 = table_groupPorts->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Port", 0));
        btn_removeSelectedPorts->setText(QApplication::translate("MainWindow", "Remove selected ports", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_Groups), QApplication::translate("MainWindow", "Groups", 0));
        lbl_scheduledTasks->setText(QApplication::translate("MainWindow", "Scheduled tasks:", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tbl_sheduler->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Device", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tbl_sheduler->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Port", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tbl_sheduler->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Action", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tbl_sheduler->horizontalHeaderItem(3);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Time", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tbl_sheduler->horizontalHeaderItem(4);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Repeat (sec.)", 0));
        lbl_emitTime->setText(QApplication::translate("MainWindow", "Emit time:", 0));
        rb_addModule->setText(QApplication::translate("MainWindow", "Add device", 0));
        lbl_schedPorts->setText(QApplication::translate("MainWindow", "Select ports:", 0));
        rb_addGroup->setText(QApplication::translate("MainWindow", "Add group", 0));
        cb_repeatEvery->setText(QApplication::translate("MainWindow", "Repeat task every:", 0));
        lblRepeatSecs->setText(QApplication::translate("MainWindow", "Seconds:", 0));
        lblRepeatMins->setText(QApplication::translate("MainWindow", "Minutes:", 0));
        lblRepeatHours->setText(QApplication::translate("MainWindow", "Hours:", 0));
        lblTasksCount->setText(QApplication::translate("MainWindow", "Tasks count:", 0));
        lblScheduledTasksCount->setText(QApplication::translate("MainWindow", "0", 0));
        lblOperation->setText(QApplication::translate("MainWindow", "Operation:", 0));
        cbScheduleTaskState->clear();
        cbScheduleTaskState->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Switch off", 0)
         << QApplication::translate("MainWindow", "Switch on", 0)
         << QApplication::translate("MainWindow", "Inverse", 0)
        );
        lblAddTaskToSchedule->setText(QApplication::translate("MainWindow", "Add task", 0));
        lblRemoveSelectedTasks->setText(QApplication::translate("MainWindow", "Remove selected tasks", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_Scheduler), QApplication::translate("MainWindow", "Scheduler", 0));
        lbl_moduleAddress->setText(QApplication::translate("MainWindow", "Module address (IP or doman):", 0));
        lbl_moduleName->setText(QApplication::translate("MainWindow", "Module local name:", 0));
        btn_addModule->setText(QApplication::translate("MainWindow", "Add new module", 0));
        lbl_currentModules->setText(QApplication::translate("MainWindow", "Current modules:", 0));
        QTableWidgetItem *___qtablewidgetitem7 = table_modules->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Address", 0));
        QTableWidgetItem *___qtablewidgetitem8 = table_modules->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Local name", 0));
        QTableWidgetItem *___qtablewidgetitem9 = table_modules->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Remote name", 0));
        QTableWidgetItem *___qtablewidgetitem10 = table_modules->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "Port 1", 0));
        QTableWidgetItem *___qtablewidgetitem11 = table_modules->horizontalHeaderItem(4);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "Port 2", 0));
        QTableWidgetItem *___qtablewidgetitem12 = table_modules->horizontalHeaderItem(5);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "Port 3", 0));
        QTableWidgetItem *___qtablewidgetitem13 = table_modules->horizontalHeaderItem(6);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "Port 4", 0));
        QTableWidgetItem *___qtablewidgetitem14 = table_modules->horizontalHeaderItem(7);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "Port 5", 0));
        QTableWidgetItem *___qtablewidgetitem15 = table_modules->horizontalHeaderItem(8);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "Port 6", 0));
        QTableWidgetItem *___qtablewidgetitem16 = table_modules->horizontalHeaderItem(9);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "Temp", 0));
        QTableWidgetItem *___qtablewidgetitem17 = table_modules->horizontalHeaderItem(10);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "Port 1 label", 0));
        QTableWidgetItem *___qtablewidgetitem18 = table_modules->horizontalHeaderItem(11);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "Port 2 label", 0));
        QTableWidgetItem *___qtablewidgetitem19 = table_modules->horizontalHeaderItem(12);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "Port 3 label", 0));
        QTableWidgetItem *___qtablewidgetitem20 = table_modules->horizontalHeaderItem(13);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "Port 4 label", 0));
        QTableWidgetItem *___qtablewidgetitem21 = table_modules->horizontalHeaderItem(14);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "Port 5 label", 0));
        QTableWidgetItem *___qtablewidgetitem22 = table_modules->horizontalHeaderItem(15);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "Port 6 label", 0));
        lblWorkerIterationTime->setText(QApplication::translate("MainWindow", "Worker iteration time:", 0));
        cbRealtimeUpdateIntervalEnabled->setText(QApplication::translate("MainWindow", "Enable realtime update (in seconds):", 0));
        cbEnableTranslation->setText(QApplication::translate("MainWindow", "Enable translation (requiered restart)", 0));
        btn_removeSelectedModules->setText(QApplication::translate("MainWindow", "Remove selected modules", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_Settings), QApplication::translate("MainWindow", "Settings", 0));
        lbl_logMessages->setText(QApplication::translate("MainWindow", "Log messages:", 0));
        checkBox_logDisabled->setText(QApplication::translate("MainWindow", "Disable log", 0));
        btn_logClear->setText(QApplication::translate("MainWindow", "Clear log", 0));
        btn_LogSaveAs->setText(QApplication::translate("MainWindow", "Save as..", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_Log), QApplication::translate("MainWindow", "Log", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
