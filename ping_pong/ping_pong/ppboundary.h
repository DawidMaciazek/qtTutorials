#ifndef PPBOUNDARY_H
#define PPBOUNDARY_H

#include <QGraphicsItem>
#include <QPainter>

class PPBoundary : public QGraphicsItem
{
public:
    PPBoundary(double xStart, double yStart, double xSize, double ySize, int xFlip, int yFlip);

    QRectF boundingRect() const Q_DECL_OVERRIDE;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

private:
    double xStart;
    double yStart;

    double xSize;
    double ySize;

    int xFlip;
    int yFlip;
};

#endif // PPBOUNDARY_H
