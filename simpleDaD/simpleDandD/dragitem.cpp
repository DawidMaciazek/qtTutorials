#include "dragitem.h"

#include <QMimeData>
#include <QWidget>
#include <QDebug>
#include <QDrag>
#include <QPainter>

DragItem::DragItem(int i, QWidget *parent): QLabel(parent)
{
    this->setText("~~~~~\n-----\n<(" + QString::number(i) + ")>\n-----\n~~~~~");

    this->setStyleSheet("QLabel { background-color : gray ; }");
    setCursor((Qt::OpenHandCursor));
    this->setMaximumHeight(150);
}

DragItem::~DragItem()
{
}

void DragItem::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "mouse clicked ...";
    setCursor(Qt::ClosedHandCursor);
    QDrag *drag = new QDrag(this);

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);

    QMimeData *mime = new QMimeData;
    mime->setData("application/x-dnditemdata", itemData);



    QImage image(":/resource/plot_img.png");
    mime->setImageData(image);

    drag->setMimeData(mime);

    drag->setPixmap(QPixmap::fromImage(image));
    drag->setHotSpot(QPoint(40,30));
    drag->exec();
    setCursor(Qt::OpenHandCursor);
}

void DragItem::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "release!";
    setCursor(Qt::OpenHandCursor);


}
