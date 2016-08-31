#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QInputDialog>
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QDirModel(this);
    model->setReadOnly(false);

    model->setSorting(QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);

    ui->treeView->setModel(model);

    QModelIndex index = model->index("/");

    ui->treeView->expand(index);
    ui->treeView->scrollTo(index);
    ui->treeView->setCurrentIndex(index);
    ui->treeView->resizeColumnToContents(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    cout << "pushed!" << endl;

    QModelIndex index = ui->treeView->currentIndex();
    if(!index.isValid())
        return;

    QString name = QInputDialog::getText(this, "Name", "Enter a name");

    cout << "name: " << name.toLocal8Bit().constData() << endl;


    if(name.isEmpty())
        return;

    cout << "lets make dir" << endl;
    model->mkdir(index, name);
}

void MainWindow::on_pushButton_2_clicked()
{
    //delete dir
}
