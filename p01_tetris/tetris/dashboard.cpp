#include "dashboard.h"
#include "ui_dashboard.h"
#include <QLineF>
#include <QPainter>

DashBoard::DashBoard(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::DashBoard)
{
    ui->setupUi(this);

    QLine line(19.0, 80.0, 90.0, 20.0);
    QPainter p(this);

    p.drawLine(line);
}

DashBoard

DashBoard::~DashBoard()
{
    delete ui;
}
