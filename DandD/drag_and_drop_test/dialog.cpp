#include "dialog.h"
#include "ui_dialog.h"
#include "dragger.h"

#include <QDebug>
#include <QDrag>

#include <QMouseEvent>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->verticalLayout->addWidget(new Dragger(this));
    ui->verticalLayout->addWidget(new Dragger(this));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "mouse presed";
    Dragger *child = static_cast<Dragger *>(childAt(event->pos())) ;
    if(!child)
    {
        qDebug() << "NOT CHILD >>>";
        return;
    }
    else
    {
        qDebug() << "child pressed ..";
    }


    QDrag *drag = new QDrag(this);
    if (drag->exec(Qt::CopyAction , Qt::CopyAction) == Qt::MoveAction) {
        child->close();
    } else {
        child->close();
    }
}
