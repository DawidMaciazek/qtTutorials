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

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    QLinearGradient gradl(25, 100, 150, 175);
    QRadialGradient gradr(QPoint(100,100), 100);
    QConicalGradient gradc(QPoint(100, 100), 90);

    gradc.setColorAt(0.0, Qt::white);
    gradc.setColorAt(0.2, Qt::red);
    gradc.setColorAt(1.0, Qt::yellow);

    QRect rec(10, 10, 200, 200);
    painter.fillRect(rec, gradc);
}
