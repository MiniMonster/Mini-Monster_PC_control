#include "mainwindow.h"
#include <qtsingleapplication.h>
#include <QApplication>
#include <QDebug>

#include <QxtCommandOptions>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    MainWindow *w;

    QtSingleApplication a(argc, argv);

    if (a.isRunning())
             return 0;


    QString paramAddr = "";
    QString paramGroup = "";
    int paramPort = -1;
    int paramCommand = -1;

    QxtCommandOptions options;

    options.setFlagStyle(QxtCommandOptions::SingleDash);
    options.setParamStyle(QxtCommandOptions::Space);

    options.add("address", "add device by address", QxtCommandOptions::ValueRequired);
    options.alias("address", "a");
    options.add("port", "point to port by number (1 - 6)", QxtCommandOptions::ValueRequired);
    options.alias("port", "p");
    options.add("command", "do command (1 - on 0 - off 2 - inverse)", QxtCommandOptions::ValueRequired);
    options.alias("command", "c");
    options.add("group", "add devices by group name", QxtCommandOptions::ValueRequired);
    options.alias("group", "g");
    options.add("help", "show this help text");
    options.alias("help", "h");

    options.parse(QCoreApplication::arguments());

    if(options.count("help") || options.showUnrecognizedWarning())
    {
         QMessageBox::information(0, "Help", options.getUsage());
         return -1;
    }

    if(options.count("port") & options.count("group"))
    {
        QMessageBox::information(0, "Help", "Port mode and Group mode can't work together!");
        return -1;
    }

    if(options.count("port"))
    {
         paramPort = options.value("port").toInt();
    }

    if(options.count("command"))
    {
         paramCommand = options.value("command").toInt();
    }

    if(options.count("address"))
    {
         paramAddr = options.value("address").toString();
    }

    if(options.count("group"))
    {
         paramGroup = options.value("group").toString();
    }

    qDebug() << "Group: " << paramGroup;
    qDebug() << "Address: " << paramAddr;
    qDebug() << "Port: " << paramPort;
    qDebug() << "Command: " << paramCommand;

    if (paramCommand > -1)
    {
        w = new MainWindow(0, true);

        if (paramAddr.length() > 0)
        {
            w->singleDevice(paramAddr, paramPort, paramCommand);
        }
        else
        {
            w->singleGroup(paramGroup, paramCommand);
        }
    }
    else
    {
        w = new MainWindow(0, false);
    }

    a.setActivationWindow(w->window());

    QRect r = w->geometry();

    r.moveCenter(QApplication::desktop()->availableGeometry().center());

    w->setGeometry(r);

    return a.exec();
}
