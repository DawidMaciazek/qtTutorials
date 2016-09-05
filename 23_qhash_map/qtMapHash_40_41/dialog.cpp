#include "dialog.h"
#include "ui_dialog.h"
#include <QMap>
// <QHash>
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QMap<int, QString> emp;
    emp.insert(1, "bob");
    emp.insert(2, "tob");
    emp.insert(3, "rob");

    foreach(int i, emp.keys())
    {
        qDebug() << emp[i];
    }


    QMapIterator<int, QString> iter(emp);
    while(iter.hasNext())
    {
        iter.next();
        qDebug() << iter.key() << "" << iter.value();
    }



}

Dialog::~Dialog()
{
    delete ui;
}
