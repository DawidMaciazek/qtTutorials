#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDir>
#include <QTextStream>
#include <QIODevice>

QString mainText;

QString searchText;
QString changeText;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open...", QDir::homePath());

    if(fileName.isEmpty())
        return;

    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    mainText.clear();

    QTextStream stream(&file);

    mainText = stream.readAll();

    ui->textEdit->setText(mainText);
}

MainWindow::~MainWindow()
{
    delete ui;
}


// slots

void MainWindow::on_actionOpen_triggered()
{
    openFile();
}
