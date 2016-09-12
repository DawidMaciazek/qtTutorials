#ifndef PPPADDLE_H
#define PPPADDLE_H

#include <QGraphicsItem>
#include <QPainter>

class PPpaddle : public QGraphicsItem
{
public:
    PPpaddle(double xStart, double xWidth, double yWidth, double yMin, double yMax, int vel);

    QRectF boundingRect() const Q_DECL_OVERRIDE;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

    double xStart;
    double yStart;
    double xWidth;
    double yWidth;
    double yMin;
    double yMax;

protected:
    void advance(int step) Q_DECL_OVERRIDE;

public slots:
    void move(int value);

private:
    int vel;
    int nextMove;
};

#endif // PPPADDLE_H
