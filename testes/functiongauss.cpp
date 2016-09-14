#include "functiongauss.h"
#include "ui_functiongauss.h"

functionGauss::functionGauss(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::functionGauss)
{
    ui->setupUi(this);
}

functionGauss::~functionGauss()
{
    delete ui;
}
