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

void Dialog::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    // make polygon

    QPolygon poly;
    poly << QPoint(10,10);
    poly << QPoint(10,340);
    poly << QPoint(300,10);
    poly << QPoint(300,200);

    // make a pen
    QPen linepen;
    linepen.setWidth(10);
    linepen.setColor(Qt::blue);
    linepen.setJoinStyle(Qt::RoundJoin);
    linepen.setJoinStyle(Qt::MiterJoin);

    // make brush
    QBrush fillbrush;
    fillbrush.setColor(Qt::green);
    fillbrush.setStyle(Qt::SolidPattern);


    // fill the polyghon
    QPainterPath path;
    path.addPolygon(poly);

    // drawpolygon
    painter.setPen(linepen);
    painter.drawPolygon(poly);

    painter.fillPath(path, fillbrush);

}
