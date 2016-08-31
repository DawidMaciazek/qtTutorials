#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString sPath = "/home";
    dirmodel = new QFileSystemModel(this);
    dirmodel->setRootPath(sPath);

    ui->treeView->setModel(dirmodel);

    QModelIndex index = dirmodel->index("/");
    ui->treeView->expand(index);
    ui->treeView->scrollTo(index);

    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);


    filemodel = new QFileSystemModel(this);
    filemodel->setFilter(QDir::Files | QDir:: NoDotAndDotDot);
    filemodel->setRootPath(sPath);

    ui->listView->setModel(filemodel);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    QString sPath = dirmodel->fileInfo(index).absoluteFilePath();
    ui->listView->setRootIndex(filemodel->setRootPath(sPath));
}
