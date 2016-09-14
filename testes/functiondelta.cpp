#include "functiondelta.h"
#include "ui_functiondelta.h"

FunctionDelta::FunctionDelta(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FunctionDelta)
{
    ui->setupUi(this);
}

FunctionDelta::~FunctionDelta()
{
    delete ui;
}
