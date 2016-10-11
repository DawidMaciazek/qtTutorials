#include "dragitem.h"

#include <QMimeData>
#include <QWidget>
#include <QDebug>
#include <QDrag>
#include <QPainter>

DragItem::DragItem(QWidget *parent): QLabel(parent)
{
    this->setText("<DRAG>");

    this->setStyleSheet("QLabel { background-color : gray ; }");
    setCursor((Qt::OpenHandCursor));
}

DragItem::~DragItem()
{
}

void DragItem::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "mouse clicked ...";
    setCursor(Qt::ClosedHandCursor);
    QDrag *drag = new QDrag(this);
    QMimeData *mime = new QMimeData;


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
