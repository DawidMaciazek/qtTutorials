#include "dragger.h"
#include "ui_dragger.h"

#include "qcustomplot.h"

#include <QDebug>

Dragger::Dragger(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dragger)
{
    ui->setupUi(this);
}

Dragger::~Dragger()
{
    delete ui;
}

void Dragger::mousePressEvent(QMouseEvent *event)
{
    event->ignore();
    qDebug() << "dragger clicked";
}
