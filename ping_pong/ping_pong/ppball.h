#ifndef PPBALL_H
#define PPBALL_H

#include "pppaddle.h"
#include <QGraphicsItem>
#include <QPainter>

class Dialog;

class PPBall : public QGraphicsItem
{
public:
    PPBall(Dialog *dparent, double xStart, double yStart, double ballSize, double xVel, double yVel);

    QRectF boundingRect() const Q_DECL_OVERRIDE;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

    int distanceToPaddle(PPpaddle *item);

    void restart();

protected:
    void advance(int step) Q_DECL_OVERRIDE;

private:
    double xStart;
    double yStart;
    double ballSize;

    double xVel;
    double yVel;

    Dialog *parent;
};

#endif // PPBALL_H
