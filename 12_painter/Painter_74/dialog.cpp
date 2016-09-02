#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *paintEvent)
{
    QPainter painter(this);
    QPen paintpen(Qt::black);

    paintpen.setWidth(12);

    QPen lainepen(Qt::red);
    lainepen.setWidth(4);


    QPoint p1;
    p1.setX(10);
    p1.setY(10);

    QPoint p2;
    p2.setX(120);
    p2.setY(310);


    painter.setPen(lainepen);
    painter.drawLine(p1, p2);



    painter.setPen(paintpen);
    painter.drawPoint(p1);
    painter.drawPoint(p2);
}
