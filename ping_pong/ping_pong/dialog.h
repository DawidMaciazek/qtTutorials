#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QGraphicsScene>

#include "ppball.h"
#include "ppboundary.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    void startNewGame();
    ~Dialog();

private:
    Ui::Dialog *ui;

    QGraphicsScene *scene;
    PPBall *ball;

    // ball
    double xCenter;
    double yCenter;
    double ballSize;

    // boundary
    PPBoundary *leftBoundary;
    PPBoundary *rightBoundary;

    PPBoundary *topBoundary;
    PPBoundary *bottomBoundary;

    // animation
    QTimer *timer;
};

#endif // DIALOG_H
