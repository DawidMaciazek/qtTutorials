#include "item.h"
#include "ui_item.h"
#include <QDebug>

Item::Item(QString name, int index, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Item),
    index(index),
    name(name)
{
    ui->setupUi(this);
    ui->label->setText(name);
    ui->lineEdit->setValidator(new QDoubleValidator(0,3000,2,this));

    left = ui->lineEdit;

    QLabel *lab = new QLabel("NEW!", this);
    this->layout()->addWidget(lab);
}

Item::~Item()
{
    delete ui;
}

int Item::getIndex()
{
    return index;
}

void Item::on_pushButton_clicked()
{
    //this->deleteLater();
    //emit removeItem(index);
    emit deleteItem(this);
}

void Item::on_lineEdit_editingFinished()
{
    qDebug() << "new value for: " << name;
    qDebug() << ui->lineEdit->text().toDouble();
}

void Item::on_lineEdit_2_editingFinished()
{

    qDebug() << "Right valuer: " <<  ui->lineEdit_2->text();
}
