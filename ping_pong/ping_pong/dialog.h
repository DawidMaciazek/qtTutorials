#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QGraphicsScene>
#include <QtSerialPort/QSerialPort>

#include "ppball.h"
#include "ppboundary.h"
#include "pppaddle.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);

    void startNewGame();

    void keyPressEvent(QKeyEvent *event);


    ~Dialog();

    // boundary
    PPBoundary *leftBoundary;
    PPBoundary *rightBoundary;

    PPBoundary *topBoundary;
    PPBoundary *bottomBoundary;

    PPpaddle *leftPaddle;
    PPpaddle *rightPaddle;

private slots:
    void serialReceived();
    void sendToPaddle();

private:
    Ui::Dialog *ui;

    QGraphicsScene *scene;
    PPBall *ball;

    QSerialPort *serial;

    // ball
    double xCenter;
    double yCenter;
    double ballSize;

    // animation
    QTimer *timer;
    int fps;
};

#endif // DIALOG_H
