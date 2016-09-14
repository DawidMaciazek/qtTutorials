#include "functioneditor.h"
#include "ui_functioneditor.h"

FunctionEditor::FunctionEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FunctionEditor)
{
    ui->setupUi(this);
}

FunctionEditor::~FunctionEditor()
{
    delete ui;
}
