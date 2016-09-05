#include "myitem.h"
#include <QTime>
#include <iostream>

MyItem::MyItem(int seedNum)
{
    // random rotation
    QTime timeZero(0, 0, 1);
    QTime time = QTime::currentTime();
    int seedTime = timeZero.secsTo(time) + seedNum;

    qsrand(seedTime);

    //angle = (qrand() % 360);
    angle = 0;
    setRotation(angle);

    // random start position
    int startX = 0;
    int startY = 0;

    if((qrand() % 1)){
        startX = (qrand() % 200);
        startY = (qrand() % 200);
    }
    else
    {
        startX = (qrand() % -100);
        startY = (qrand() % -100);
    }

    setPos(mapToParent(startX, startY));

    // set speed
    speed = 5;
}

QRectF MyItem::boundingRect() const
{
    return QRect(0, 0, 20, 20);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush brush = QBrush(Qt::blue);

    // colision detection
    if(scene()->collidingItems(this).isEmpty())
    {
        // no collision
        brush.setColor(Qt::green);
    }
    else
    {
        // colsion
        brush.setColor(Qt::red);

        // set new position
        doCollision();
    }

    painter->fillRect(rec, brush);
    painter->drawRect(rec);
}

void MyItem::advance(int phase)
{
    if(!phase) return;

    QPointF location = this->pos();

    setPos(mapToParent(0, speed));

}

void MyItem::doCollision()
{
    //get new position

    //change the new angle with a little randomness
    int dev = 10;
    int spinDev = qrand() % (dev*2 + 1) - dev;
    setRotation(rotation() + (180 + spinDev));

    //see if the new position in bounds
    QPointF newPoint = mapToParent((boundingRect().width()),-(boundingRect().width() + 2));

    if(!scene()->sceneRect().contains((newPoint)))
    {
        //move back
        newPoint = mapToParent(0, 0);
    }
    else
    {
        //set new postion
        setPos(newPoint);
    }
}
