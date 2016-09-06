#include "dialog.h"
#include "ui_dialog.h"

#include "overloads.h"
#include "person.h"

#include <QtCore>



void save()
{
    Person person1;
    person1.age = 22;
    person1.name = "Ray";

    Person person2;
    person2.age = 21;
    person2.name = "Heather";

    QFile file("/tmp/save_test.txt");

    if(!file.open(QIODevice::WriteOnly))
        return;

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_7);

    out << person1;
    out << person2;

    file.flush();
    file.close();
}

void load()
{

}

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    save();
}

Dialog::~Dialog()
{
    delete ui;
}
