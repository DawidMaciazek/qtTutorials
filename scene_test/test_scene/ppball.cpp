#include "ppball.h"

#include <QDebug>
#include <QKeyEvent>

PPball::PPball(double xStart, double yStart, double xSize, double ySize):
    xStart(xStart),
    yStart(yStart),
    xSize(xSize),
    ySize(ySize),
    xVel(2),
    yVel(1){;}

QRectF PPball::boundingRect() const
{
    return QRectF(xStart, yStart, xSize, ySize);
}

void PPball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();

    QBrush brush = QBrush(Qt::red);
    painter->fillRect(rec, brush);
}

void PPball::flipVelo(bool direction)
{
   if(direction)
       xVel = -xVel;
   else
       yVel = -yVel;
}

void PPball::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
        flipVelo(true);
    else
        flipVelo(false);

}

void PPball::advance(int step)
{
    if (!step)
    {
        return;
    }
    setPos(mapToParent(xVel, yVel));
}
