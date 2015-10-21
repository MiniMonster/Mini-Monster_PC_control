#include "simplemainwindow.h"
#include "ui_simplemainwindow.h"

simpleMainWindow::simpleMainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::simpleMainWindow)
{
    ui->setupUi(this);

    worker = new qMiniMonsterWorker(500, true, this);
    QObject::connect(worker, SIGNAL(onLog(QString)), this, SLOT(toLog(QString)));
    QObject::connect(worker, SIGNAL(onExit()), this, SLOT(onWorkerExit()));

    //worker->addTask("95.84.158.17/password", "2", "1");
    //worker->addTask("95.84.158.17/password", "2", "0");
}

simpleMainWindow::~simpleMainWindow()
{
    delete ui;
}

void simpleMainWindow::toLog(QString message)
{
    ui->textLog->insertPlainText(message + "\n");
}

void simpleMainWindow::onWorkerExit()
{
    this->close();
}

void simpleMainWindow::on_btnEdit_clicked()
{
    this->close();
}
