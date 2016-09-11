#ifndef PPBOUNDARY_H
#define PPBOUNDARY_H

#include <QGraphicsItem>
#include <QPainter>

class PPBoundary : public QGraphicItem
{
public:
    //PPBoundary();

    PPBoundary(double start, double end, double width);

    QRectF boundingRect() const Q_DECL_OVERRIDE;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

protected:
    void advance(int step) Q_DECL_OVERRIDE;

private:
    double start;
    double end;

    double width;
};

#endif // PPBOUNDARY_H
