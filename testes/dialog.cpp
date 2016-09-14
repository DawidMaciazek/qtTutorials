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


    Item *itemm = new Item(names[counter % namesNum], counter, this);
    counter += 1;
    ui->verticalLayout_3->addWidget(itemm);
    //connect(itemm, SIGNAL(destroyed(QObject*)),
    //        this, SLOT(chlidrenDestroyed(QObject*)));
    //connect(itemm, SIGNAL(removeItem(int)),
    //        this, SLOT(chlidrenDestroyed(int)));
    //QList<Item *> itemList = this->findChildren<Item *>();
    //qDebug() << itemList.size();
    connect(itemm, SIGNAL(deleteItem(Item*)),
            this, SLOT(removeIten(Item*)));


}

void Dialog::chlidrenDestroyed()
{
    qDebug() << "DESTROYED";
    deletedItems += 1;
    ui->label->setText(QString::number(deletedItems));
}

void Dialog::chlidrenDestroyed(int itemIndex)
{
    qDebug() << "This chldren whant to be destroyed ..." ;
    qDebug() << itemIndex;
}



void Dialog::childrenEdited(QString str)
{
    qDebug() << "MAIN WIDGET KNOW THAT CHILD IS CHANGEEEEEDDD@!!!";
    qDebug() << str;
}

void Dialog::removeIten(Item *item)
{
    qDebug() << "CHildren pointer to children";
    qDebug() << "";
    qDebug() << "item index === " << item;
    QList<Item *> itemList = this->findChildren<Item *>();

    qDebug() << "CURRENT CHILDRENS";
    foreach(Item *item_ptr, itemList)
    {
        qDebug() << item_ptr;
        if( item_ptr == item)
        {
            item->deleteLater();
           qDebug() << "above pointer is right:)" ;
           break;
        }
    }
    qDebug() << "";
}
