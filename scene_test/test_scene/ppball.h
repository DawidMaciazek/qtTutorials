#ifndef PPBALL_H
#define PPBALL_H

#include <QGraphicsItem>
#include <QPainter>


class PPball : public QGraphicsItem
{
public:
    PPball(double xStart, double yStart, double xSize, double ySize);

    QRectF boundingRect() const Q_DECL_OVERRIDE;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;
    void flipVelo(bool direction);
    void keyPressEvent(QKeyEvent *event);

protected:
    void advance(int step) Q_DECL_OVERRIDE;

private:
    double xVel;
    double yVel;

    double xStart;
    double yStart;

    double xSize;
    double ySize;
};

#endif // PPBALL_H
