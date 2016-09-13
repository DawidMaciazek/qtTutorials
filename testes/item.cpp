#include "item.h"
#include "ui_item.h"
#include <QDebug>

Item::Item(QString name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Item),
    name(name)
{
    ui->setupUi(this);
    ui->label->setText(name);
    ui->lineEdit->setValidator(new QDoubleValidator(0,3000,2,this));

    left = ui->lineEdit;
}

Item::~Item()
{
    delete ui;
}

void Item::on_pushButton_clicked()
{
    this->deleteLater();
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
