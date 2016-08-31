#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStandardItemModel(4,2,this);

    for(int row=0; row<5; row++)
    {
        for(int col=0; col<3; col++)
        {
            QModelIndex index = model->index(row, col, QModelIndex());
            model->setData(index, col*row);
        }
    }

    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}
