#include "dialog.h"
#include "ui_dialog.h"

#include <QtCore>
#include <QFile>
#include <QString>
#include <QMap>
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    int myNum = 22;
    QMap<qint64, QString> map;
    map.insert(1, "one");
    map.insert(2, "two");
    map.insert(3, "three");

    //save it to disk
    QFile file("/tmp/serialized.txt");


    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "Problem with file ! :(";
        return;
    }

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_7);

    out << myNum << map;

    file.flush();
    file.close();


    // now reading

    QFile file2("/tmp/serialized.txt");
    if(!file2.open(QIODevice::ReadOnly))
    {
        qDebug() << "Problem with file ! :(";
        return;
    }

    QDataStream in(&file2);
    in.setVersion(QDataStream::Qt_5_7);

    int myNumNew;
    QMap<qint64, QString> mapNew;
    in >> myNumNew >> mapNew;


    file2.close();
    qDebug() << "num = " << myNumNew ;
    foreach (QString item, mapNew.keys()) {
        qDebug() << "key = " << item;

    }
}

Dialog::~Dialog()
{
    delete ui;
}
