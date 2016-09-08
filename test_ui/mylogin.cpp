#include "mylogin.h"
#include "ui_mylogin.h"

MyLogin::MyLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyLogin)
{
    ui->setupUi(this);
}

MyLogin::~MyLogin()
{
    delete ui;
}

void MyLogin::on_pushButton_clicked()
{
   // change to mywidget
}
