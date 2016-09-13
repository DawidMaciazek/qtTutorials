#include "dialog.h"
#include "ui_dialog.h"
#include "item.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    counter = 0;
    deletedItems = 0;

    ui->setupUi(this);
    ui->label->setText(QString::number(deletedItems));

    namesNum = 2;
    names = QVector<QString>(namesNum);
    names[0] = "Itemme 1";
    names[1] = "Tretem 2";
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{


    Item *itemm = new Item(names[counter % namesNum], this);
    counter += 1;
    //ui->verticalLayout_2->addWidget(itemm);
    ui->verticalLayout_3->addWidget(itemm);
    //ui->scrollAreaWidgetContents->addWidget(itemm);
    connect(itemm, SIGNAL(destroyed(QObject*)),
            this, SLOT(chlidrenDestroyed()));

    //connect(itemm->left, SIGNAL(textEdited(QString)),
    //        this, SLOT(childrenEdited(QString)));
}

void Dialog::chlidrenDestroyed()
{
    qDebug() << "DESTROYED";
    deletedItems += 1;
    ui->label->setText(QString::number(deletedItems));
}

void Dialog::childrenEdited(QString str)
{
    qDebug() << "MAIN WIDGET KNOW THAT CHILD IS CHANGEEEEEDDD@!!!";
    qDebug() << str;
}
