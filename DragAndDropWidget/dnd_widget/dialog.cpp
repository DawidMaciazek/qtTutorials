#include "dialog.h"
#include "ui_dialog.h"

#include "form.h"

#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->frame->setAcceptDrops(true);

    ui->gridLayout->addWidget(new Form(this),0,0);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::mousePressEvent(QMouseEvent *event)
{
    //qDebug() << "presed";
}
