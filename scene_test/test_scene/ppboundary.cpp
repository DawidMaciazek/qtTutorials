#include "ppboundary.h"

PPBoundary::PPBoundary(double start, double end, double width):
    start(start),
    end(end),
    width(width){;}

QRectF PPBoundary::boundingRect() const
{
    return QRectF(start, end, start+1, end+1)
}

void PPBoundary::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRect rec = boundingRect();
}
