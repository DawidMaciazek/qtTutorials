#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "functioneditor.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->widget);
    //new FunctionEditor(this)
}

MainWindow::~MainWindow()
{
    delete ui;
}
