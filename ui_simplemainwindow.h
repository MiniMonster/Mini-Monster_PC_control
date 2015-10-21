/********************************************************************************
** Form generated from reading UI file 'simplemainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLEMAINWINDOW_H
#define UI_SIMPLEMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_simpleMainWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lblLog;
    QTextEdit *textLog;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnEdit;

    void setupUi(QWidget *simpleMainWindow)
    {
        if (simpleMainWindow->objectName().isEmpty())
            simpleMainWindow->setObjectName(QStringLiteral("simpleMainWindow"));
        simpleMainWindow->resize(400, 300);
        QIcon icon;
        icon.addFile(QStringLiteral(":/1.png"), QSize(), QIcon::Normal, QIcon::Off);
        simpleMainWindow->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(simpleMainWindow);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lblLog = new QLabel(simpleMainWindow);
        lblLog->setObjectName(QStringLiteral("lblLog"));

        verticalLayout->addWidget(lblLog);

        textLog = new QTextEdit(simpleMainWindow);
        textLog->setObjectName(QStringLiteral("textLog"));

        verticalLayout->addWidget(textLog);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnEdit = new QPushButton(simpleMainWindow);
        btnEdit->setObjectName(QStringLiteral("btnEdit"));

        horizontalLayout->addWidget(btnEdit);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(simpleMainWindow);

        QMetaObject::connectSlotsByName(simpleMainWindow);
    } // setupUi

    void retranslateUi(QWidget *simpleMainWindow)
    {
        simpleMainWindow->setWindowTitle(QApplication::translate("simpleMainWindow", "qMiniMonster", 0));
        lblLog->setText(QApplication::translate("simpleMainWindow", "Messages:", 0));
        btnEdit->setText(QApplication::translate("simpleMainWindow", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class simpleMainWindow: public Ui_simpleMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLEMAINWINDOW_H
