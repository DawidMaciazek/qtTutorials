#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialog>
#include <QtGui>
#include <QtCore>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    QRect rec(20, 20, 100, 200);
    QPen framepan(Qt::red);
    framepan.setWidth(10);

    QBrush brush(Qt::blue, Qt::Dense3Pattern);

    painter.fillRect(rec, brush);


    painter.setPen(framepan);
    painter.drawRect(rec);

    painter.drawEllipse(rec);

}
