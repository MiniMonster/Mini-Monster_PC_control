#include "qminimonsterworker.h"
#include <QJsonValue>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QJsonArray>

qMiniMonsterWorker::qMiniMonsterWorker(int timerInterval, bool singleMode, QObject *parent) :
    QObject(parent)
{
    isSingleMode = singleMode;
    mainQueue = new QStringList();
    mainTimer = new QTimer(this);
    nextFast = false;

    nam = new QNetworkAccessManager(this);
    testSocket = new QTcpSocket(this);
    QObject::connect(testSocket, SIGNAL(connected()), this, SLOT(onTestConnected()));


    QObject::connect(mainTimer, SIGNAL(timeout()), this, SLOT(update()));
    QObject::connect(nam,SIGNAL(finished(QNetworkReply*)),this,SLOT(workRequestFinished(QNetworkReply*)));
    mainTimer->setInterval(timerInterval);
}


void qMiniMonsterWorker::update()
{
    if (mainQueue->size() == 0)
    {
        emit onLog(tr("Queue is empty, disabling worker.."));
        mainTimer->stop();

        if (isSingleMode)
            emit onWorkerExit();
    }
    else
    {
        emit onLog(tr("Working on") + " " + mainQueue->last());

        nam->get(QNetworkRequest(QUrl(mainQueue->last())));

        mainQueue->removeLast();
    }
}

void qMiniMonsterWorker::onTestConnected()
{
    testSocket->disconnect();
}

void qMiniMonsterWorker::addTask(QString addr, QString port, QString mode, bool now)
{
    if (isDeviceReachable(addr))
    {
        emit onLog(tr("Adding task") + " " + "http://" + addr + "/?sw=" + port + "-" + mode + " to queue...");

        // http://ip-адрес/пароль/?sw=1-0
        mainQueue->prepend("http://" + addr + "/?sw=" + port + "-" + mode);

        emit addStat(addr, now);

        if (!mainTimer->isActive())
            mainTimer->start();

        if (now)
            emit update();
    }
    else
        if (isSingleMode)
            if (mainQueue->count() <= 0)
                emit onWorkerExit();
}

void qMiniMonsterWorker::addStat(QString addr, bool now)
{
    if (isDeviceReachable(addr))
    {
        emit onLog(tr("Adding status request") + " " + "http://" + addr + " " + tr("to queue") + "...");

        //здесь мы ультимативно запросим JS. Монстр на неизвестные запросы отдаёт main,
        //так что данные мы так или иначе получим.
        //проверка старый/новый производится непосредственно при парсинге
        mainQueue->prepend("http://" + addr + "/?js=");

        if (!mainTimer->isActive())
            mainTimer->start();

        if (now)
            emit update();
    }
    else
        if (isSingleMode)
            if (mainQueue->count() <= 0)
                emit onWorkerExit();
}

void qMiniMonsterWorker::workRequestFinished(QNetworkReply *reply)
{

    if(reply->error() == QNetworkReply::NoError)

    {
            // Успешно установили состояние
            emit onLog(tr("Network request finished with no error"));

            //Получили параметры модуля
            QString *replyText = new QString(reply->readAll());

/******
Порядок: 1. неизв и пустой(0) 2. темп (1) 3. метка TH (неакт) (2) 4. метка WD (неакт) (3) 5. порты(4) 6. локальное имя Модуля(5)
******/

/******
Здесь мы имеем некую странную проверку. Похоже, проверяется, не команда ли в буфере.
Почему и зачем она тут, я не знаю (комментируйте код!),
но в нынешних реалиях надо её расширять
Без неё вываливается аж в сегментейшн фолт
******/
            if ((reply->url().toString().indexOf("/?js=")) != -1 ){
            if ( replyText->startsWith("{") )
            {
//                // Получили параметры модуля
//                QString *replyText = new QString(reply->readAll());

                //начинаем разбор JSON
                QJsonParseError  parseError;
                QJsonDocument MM_JS_answer = QJsonDocument::fromJson(replyText->toUtf8(), &parseError);

                if(parseError.error == QJsonParseError::NoError)
                {
                    QJsonObject answer_param = MM_JS_answer.object();

                    emit onLog(tr("Actual data mode"));

                    //оказывается, адрес нужен, причем именно в виде addr/pass
                    //по нему модули пишутся в MySQL
                    QString *tempAddrString = new QString(reply->url().toString());
                    tempAddrString->remove("http://", Qt::CaseInsensitive);
                    if (tempAddrString->endsWith('=')) tempAddrString->chop(5);

                    QString *id = new QString(answer_param["id"].toString());

                    //quint16 pwmt = answer_param["pwmt"].toDouble();

                    //t может и не быть в сборке. Сделать исключение
                    QJsonArray tmpr = answer_param["t"].toArray();
                    QString *tmprs = new QString(tmpr[0].toString());

                    QJsonArray ports_js = answer_param["prt"].toArray();

                    emit onStat(*tempAddrString, *id, *tmprs, QString::number(ports_js[0].toDouble()), QString::number(ports_js[1].toDouble()), QString::number(ports_js[2].toDouble()), QString::number(ports_js[3].toDouble()), QString::number(ports_js[4].toDouble()), QString::number(ports_js[5].toDouble()));

                    delete tempAddrString;
                    delete replyText;
                    delete id;

                    return ;

                }
                else
                {
                    emit onLog(tr("JSON parse error: ")+ parseError.errorString() );
                }
            }

            else
            //предполагается, что предыдущий и этот if'ы -- два взаимоисключающих состояния
            //if ((reply->url().toString().indexOf("/?")) == -1 )
            {

                emit onLog(tr("Old data mode"));

                //QString *replyText = new QString(reply->readAll());

                *replyText = replyText->right(replyText->length() - 3 - replyText->lastIndexOf(">"));

                QStringList *params = new QStringList(replyText->split(","));

                QString *tempAddrString = new QString(reply->url().toString());
                tempAddrString->remove("http://", Qt::CaseInsensitive);
                if (tempAddrString->endsWith('/')) tempAddrString->chop(1);
                //это для нового формата адреса с ?js=
                if (tempAddrString->endsWith('=')) tempAddrString->chop(5);
                params->prepend(*tempAddrString);
                delete tempAddrString;

                delete replyText;

                bool is1, is2 , is3, is4, is5, is6 = false;

                unsigned int ports;
                ports = 0;
                ports = params->at(4).toInt();

                is1 = checkBit(ports, 0);
                is2 = checkBit(ports, 1);
                is3 = checkBit(ports, 2);
                is4 = checkBit(ports, 3);
                is5 = checkBit(ports, 4);
                is6 = checkBit(ports, 5);

                emit onStat(params->at(0), params->at(5), params->at(1), QString::number(is1), QString::number(is2), QString::number(is3), QString::number(is4), QString::number(is5), QString::number(is6));

                delete params;
            };
            }

        }

        else
        {
            emit onLog(tr("Network request finished with error") + ": " + reply->errorString());
        }
}

void qMiniMonsterWorker::updateTimerInterval(int interval)
{
    mainTimer->setInterval(interval);
    emit onLog(tr("Worker interval set to ") + QString::number(interval) + tr(" msecs."));
}

bool qMiniMonsterWorker::checkBit(unsigned int dwNumber, int iBit)
{
    return ( (dwNumber & (1 << iBit)) != 0 );
}

bool qMiniMonsterWorker::isDeviceReachable(QString addr)
{
    QString old = addr;

    int tmp;

    tmp = addr.lastIndexOf("/");
    addr.remove(tmp, addr.length() - tmp);

    addr.remove("http:");
    addr.remove("/");
    addr.remove("\\");
    addr = addr.trimmed();

    emit onLog(tr("Testing connection with ") + old);

    testSocket->connectToHost(addr, 80);

    if(testSocket->waitForConnected(400))
    {
        testSocket->abort();
        return true;
    }

    emit onLog(tr("Device not reachable ") + old);

    emit onDeviceNotReachable(old);

    return false;
}
