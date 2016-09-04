#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    painter.drawText(100, 100, "Hello String");

    QRect rec(100, 150, 250, 55);
    painter.drawRect(rec);
    painter.drawText(rec,Qt::AlignLeft, "LEFTY");
    painter.drawText(rec,Qt::AlignRight | Qt::AlignCenter, "RIGHT");
    painter.drawText(rec,Qt::AlignCenter, "CENTER");

    QRect rec2(100, 200, 25, 25);
    painter.drawRect(rec2);
    painter.drawText(rec2, "OMG THIS SHLOUD LKSADJlsdkfjlaskf j");

    QTextDocument doc;
    QRect rec3(0,0,250,250);
    painter.translate(20, 20);
    doc.setTextWidth(rec3.width());
    doc.setHtml("<b><u> HELLO N</u></b>");
    doc.drawContents(&painter, rec3);
}
