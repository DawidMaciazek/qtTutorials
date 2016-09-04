#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);

    QBrush redBrush(Qt::red);
    QBrush blueBrush(Qt::blue);
    QBrush greenBrush(Qt::green);

    QPen blackPen(Qt::black);

    blackPen.setWidth(6);

    ellipse = scene->addEllipse(10,100,100,100,blackPen,redBrush);

    rect = scene->addRect(-100,-100,50,50,blackPen, greenBrush);
    rect->setFlag(QGraphicsItem::ItemIsMovable);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    ui->graphicsView->rotate(-1);
}

void Dialog::on_pushButton_2_clicked()
{
    ui->graphicsView->rotate(1);
}
