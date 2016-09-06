#include "dialog.h"
#include "ui_dialog.h"

#include <QtCore>
#include <QDebug>

void write()
{
    QFile file("/tmp/xtest.txt");

    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);

        stream << "Hello \n World \n Now";

        stream.flush();
        file.flush();
        file.close();
    }
}

void read()
{
    QFile file("/tmp/xtest.txt");

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);

        QString line;
        do
        {
           line = stream.readLine();
           qDebug() << line;
        }while(!line.isNull());

        stream.flush();
        file.flush();
        file.close();
    }


}

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    write();
    read();
}

Dialog::~Dialog()
{
    delete ui;
}
