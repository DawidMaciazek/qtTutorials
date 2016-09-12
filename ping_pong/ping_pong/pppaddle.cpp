#include "pppaddle.h"
#include <QDebug>


PPpaddle::PPpaddle(double xStart, double xWidth, double yWidth, double yMin, double yMax, int vel):
    xStart(xStart),
    xWidth(xWidth),
    yWidth(yWidth),
    yMin(yMin),
    yMax(yMax-yWidth),
    vel(vel)
{
    yStart=0.5*(yMax-yMin-yWidth);
    nextMove = 0;
}

QRectF PPpaddle::boundingRect() const
{
    return QRectF(xStart, yStart, xWidth, yWidth);
}

void PPpaddle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QBrush brush = QBrush(Qt::white);
    painter->fillRect(rect, brush);
}

void PPpaddle::advance(int step)
{
    if(!step)
        return;

    if(!nextMove)
        return;

    setPos(mapToParent(0,nextMove * vel));
    nextMove = 0;
}

void PPpaddle::move(int value)
{
    if(nextMove)
        return;

    nextMove = value;
}

