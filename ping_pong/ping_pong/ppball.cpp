#include "ppball.h"
#include "dialog.h"
#include <QDebug>

#include <cmath>

PPBall::PPBall(Dialog *dparent, double xStart, double yStart, double ballSize, double xVel, double yVel) :
    xStart(xStart),
    yStart(yStart),
    ballSize(ballSize),
    xVel(xVel * (1 - (qrand() % 2)*2)),
    yVel(yVel * (1 - (qrand() % 2)*2))
{
    parent = dparent;
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

int PPBall::distanceToPaddle(PPpaddle *item)
{
    return item->pos().y() - pos().y();
}

void PPBall::restart()
{
    setPos(0, 0);
    xVel *= 1 - (qrand() % 2)*2;
    yVel *= 1 - (qrand() % 2)*2;
}

void PPBall::advance(int step)
{
    if (!step)
    {
        return;
    }
    qDebug() << distanceToPaddle(parent->leftPaddle);

    // GAME END
    if(this->collidesWithItem(parent->rightBoundary))
    {
        qDebug() << "Player 1 score!";
        //xVel = -abs(xVel);
        restart();
    }

    if(this->collidesWithItem(parent->leftBoundary))
    {
        qDebug() << "Player 2 score!";
        //xVel = abs(xVel);
        restart();
    }
    // ---

    if(this->collidesWithItem(parent->bottomBoundary))
    {
        yVel = -abs(yVel);
        qDebug() << "BOTTOM!";
    }

    if(this->collidesWithItem(parent->topBoundary))
    {
        yVel = abs(yVel);
        qDebug() << "TOP!";
    }

    if(this->collidesWithItem(parent->leftPaddle))
    {
        xVel = abs(xVel);
        qDebug() << "HIT!!!!!!!!!!!!";
    }

    if(this->collidesWithItem(parent->rightPaddle))
    {
        xVel = -abs(xVel);
        qDebug() << "HIT!!!!!!!!!!!!";
    }


    setPos(mapToParent(xVel, yVel));
}

