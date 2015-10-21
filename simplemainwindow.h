#ifndef SIMPLEMAINWINDOW_H
#define SIMPLEMAINWINDOW_H

#include <QWidget>
#include <qminimonsterworker.h>

namespace Ui {
class simpleMainWindow;
}

class simpleMainWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit simpleMainWindow(QWidget *parent = 0);
    ~simpleMainWindow();
    
private slots:
    void toLog(QString message);
    void onWorkerExit();

    void on_btnEdit_clicked();

private:
    Ui::simpleMainWindow *ui;

    qMiniMonsterWorker *worker;
};

#endif // SIMPLEMAINWINDOW_H
