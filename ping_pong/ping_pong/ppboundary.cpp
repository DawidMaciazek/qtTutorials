#include "ppboundary.h"

PPBoundary::PPBoundary(double xStart, double yStart, double xSize, double ySize, int xFlip, int yFlip) :
    xStart(xStart),
    yStart(yStart),
    xSize(xSize),
    ySize(ySize),
    xFlip(xFlip),
    yFlip(yFlip)
{
    ;
}

QRectF PPBoundary::boundingRect() const
{
    return QRectF(xStart, yStart, xSize, ySize);
}

void PPBoundary::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QBrush brush = QBrush(Qt::gray);
    painter->fillRect(rect, brush);
}
