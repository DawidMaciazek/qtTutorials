#ifndef PPBALL_H
#define PPBALL_H

#include <QGraphicsItem>
#include <QPainter>

class PPBall : public QGraphicsItem
{
public:
    PPBall(double xStart, double yStart, double ballSize, double xVel, double yVel);

    QRectF boundingRect() const Q_DECL_OVERRIDE;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

protected:
    void advance(int step) Q_DECL_OVERRIDE;

private:
    double xStart;
    double yStart;
    double ballSize;

    double xVel;
    double yVel;

};

#endif // PPBALL_H
