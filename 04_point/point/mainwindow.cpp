#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    cout << "lest start" << endl;
    ui->setupUi(this);
    ui->display->display(11);

    connect(ui->displaySlider, SIGNAL(valueChanged(int)),
            ui->display, SLOT(display(int)));
    connect(ui->displaySlider, SIGNAL(valueChanged(int)),
            ui->progressBar, SLOT(setValue(int)));
}

void MainWindow::handleSlider(double value){
    cout << value << endl;

}

void MainWindow::handlerButton(){
    cout << "released" << endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void updateDisplay(){
//	ui->display->
//}
