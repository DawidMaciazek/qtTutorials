#include "dialog.h"
#include "ui_dialog.h"
#include "ppball.h"
#include <QDebug>
#include <QTimer>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(QBrush(Qt::black));



    ui->graphicsView->setScene(scene);

    ball = new PPball(100, 100, 10, 10);
    ball->setFlag(QGraphicsItem::ItemIsFocusable);
    ball->setFocus();
    scene->addItem(ball);

    // Start animation
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),
            scene, SLOT(advance()));
    timer->start(1000/100);

}

Dialog::~Dialog()
{
    delete ui;
    delete ball;
    delete ball2;
}

