#include "dialog.h"
#include "ui_dialog.h"

#include <QVariant>
#include <QDebug>

#include "myclass.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QVariant v = 1233.03;

    qDebug() << v.toInt();
    qDebug() << v.toDouble();

    if(v.canConvert<QString>())
    {
        qDebug() << v.toString();
    }


    MyClass myclass;
    myclass.number = 213123;
    QVariant z = QVariant::fromValue(myclass);
    MyClass zclass = z.value<MyClass>();

    qDebug() << zclass.number;
}

Dialog::~Dialog()
{
    delete ui;
}
