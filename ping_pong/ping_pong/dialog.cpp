#include "dialog.h"
#include "ui_dialog.h"
#include <QString>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>
#include <QtSerialPort/QSerialPort>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // set up scene
    scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(QBrush(Qt::black));

    ui->graphicsView->setScene(scene);
    this->setFocus();

    // ball
    ballSize = 10;
    xCenter = 300 - ballSize/2;
    yCenter = 200 - ballSize/2;

    // create boundary
    leftBoundary = new PPBoundary(-10, -10, 10, 420, 1, 0);
    rightBoundary = new PPBoundary(600, -10, 10, 420, -1, 0);

    topBoundary = new PPBoundary(-10, -10, 620, 10, 0, -1);
    bottomBoundary = new PPBoundary(-10, 400, 620, 10, 0, 1);

    // paddle
    leftPaddle = new PPpaddle(-2,10,100,0,400, 10);
    rightPaddle = new PPpaddle(592,10,100,0,400, 10);


    scene->addItem(leftBoundary);
    scene->addItem(rightBoundary);

    scene->addItem(topBoundary);
    scene->addItem(bottomBoundary);

    scene->addItem(leftPaddle);
    scene->addItem(rightPaddle);

    startNewGame();

    // animation
    fps = 24;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),
            scene, SLOT(advance()));
    timer->start(1000/fps);

    // serial communication
    serial = new QSerialPort(this);
    serial->setPortName("/dev/pts/2");
    serial->open(QIODevice::ReadWrite);
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    //serial->write("11w 3 \n\n");

    connect(serial, SIGNAL(readyRead()),
            this, SLOT(serialReceived()));

    connect(timer, SIGNAL(timeout()),
            this, SLOT(sendToPaddle()));
    qDebug() << "Serial connected";

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::serialReceived()
{
    char command = char(serial->readAll()[0]);
    if(command == 'u')
    {
        rightPaddle->move(-1);
    }
    else if(command == 'd')
    {
        rightPaddle->move(1);
    }
}

void Dialog::startNewGame()
{
    ball = new PPBall(this, xCenter, yCenter, ballSize, 5, 3);
    scene->addItem(ball);
}

void Dialog::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
    {
       leftPaddle->move(-1);
    }
    else if(event->key() == Qt::Key_Down)
    {
       leftPaddle->move(1);
    }
}

void Dialog::sendToPaddle()
{
    int dist = ball->distanceToPaddle(rightPaddle);
    QString str;
    str.setNum(dist);
    QByteArray ba = str.toLatin1();
    const char *c_str2 = ba.data();
    serial->write(c_str2);
    serial->write("\n");
}
