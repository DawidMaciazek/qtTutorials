#include "widget.h"
#include "ui_widget.h"
#include "mywidget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setCe
}

Widget::~Widget()
{
    delete ui;
}
