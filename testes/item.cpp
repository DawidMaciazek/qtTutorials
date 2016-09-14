#include "item.h"
#include "ui_item.h"
#include <QDebug>
#include <functiondelta.h>
#include <functiongauss.h>

Item::Item(QString name, int index, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Item),
    index(index),
    name(name)
{
    isDestroyable = false;
    ui->setupUi(this);
    //ui->label->setText(name);
    //ui->lineEdit->setValidator(new QDoubleValidator(0,3000,2,this));

    //left = ui->lineEdit;
    ui->comboBox->addItem("Gaussian");
    ui->comboBox->addItem("Delta");
    ui->comboBox->addItem("Custom");
}

Item::~Item()
{
    delete ui;
}

int Item::getIndex()
{
    return index;
}

void Item::on_comboBox_currentIndexChanged(int index)
{
    qDebug() << "current index" << index;
    if(isDestroyable)
    {
        currentDisplay->deleteLater();
    }
    else
    {
        isDestroyable = true;
    }

    if(index == 0)
    {
        currentDisplay = new FunctionDelta(this);
    }
    else if(index == 1)
    {
        currentDisplay = new functionGauss(this);
    }

    ui->horizontalLayout->addWidget(currentDisplay);
}

void Item::on_toolButton_clicked()
{
    //this->deleteLater();
    //emit removeItem(index);
    emit deleteItem(this);
}

