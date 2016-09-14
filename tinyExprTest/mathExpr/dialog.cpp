#include "dialog.h"
#include "ui_dialog.h"
#include "tinyexpr.h"

#include "expparser.h"

#include <QDebug>
#include <string>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->lineEdit_2->setText("2");

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_lineEdit_editingFinished()
{
    double x = ui->lineEdit_2->text().toDouble();
    double res = (ExpParser(ui->lineEdit->text()))(x);

    ui->label->setText(QString::number(res));
}
