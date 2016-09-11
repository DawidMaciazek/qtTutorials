#include "dialog.h"
#include "ui_dialog.h"
#include <QTimer>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // set up scene
    scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(QBrush(Qt::black));

    ui->graphicsView->setScene(scene);

    // ball
    ballSize = 10;
    xCenter = 300 - ballSize/2;
    yCenter = 200 - ballSize/2;

    // create boundary
    leftBoundary = new PPBoundary(-10, -10, 10, 420, 1, 0);
    rightBoundary = new PPBoundary(600, -10, 10, 420, -1, 0);

    topBoundary = new PPBoundary(-10, -10, 620, 10, 0, -1);
    bottomBoundary = new PPBoundary(-10, 400, 620, 10, 0, 1);


    scene->addItem(leftBoundary);
    scene->addItem(rightBoundary);

    scene->addItem(topBoundary);
    scene->addItem(bottomBoundary);

    startNewGame();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),
            scene, SLOT(advance()));
    timer->start(100);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::startNewGame()
{
    ball = new PPBall(xCenter, yCenter, ballSize, 5, 3);
    scene->addItem(ball);
}
