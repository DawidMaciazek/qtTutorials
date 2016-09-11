#include "ppball.h"
#include <QDebug>

PPBall::PPBall(double xStart, double yStart, double ballSize, double xVel, double yVel) :
    xStart(xStart),
    yStart(yStart),
    ballSize(ballSize),
    xVel(xVel),
    yVel(yVel)
{
    ;
}

QRectF PPBall::boundingRect() const
{
    return QRectF(xStart, yStart, ballSize, ballSize);
}

void PPBall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();

    QBrush brush = QBrush(Qt::white);

    painter->fillRect(rect, brush);
}

void PPBall::advance(int step)
{
    if (!step)
    {
        return;
    }
    if(this->collidesWithItem(this))
        qDebug() << "COLIDING";
    setPos(mapToParent(xVel, yVel));
}

