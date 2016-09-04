#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pen(Qt::black);
    pen.setWidth(20);

    QPoint point_start(20, 30);
    QPoint point_end(40, 200);

    pen.setCapStyle(Qt::FlatCap);
    painter.setPen(pen);
    painter.drawLine(point_start, point_end);

    point_start.setY(80);
    point_end.setY(80);
    pen.setCapStyle(Qt::SquareCap);
    painter.setPen(pen);
    painter.drawLine(point_start, point_end);
}
