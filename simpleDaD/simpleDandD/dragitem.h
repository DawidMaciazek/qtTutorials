#ifndef DRAGITEM_H
#define DRAGITEM_H

#include <QLabel>

class DragItem : public QLabel
{
    Q_OBJECT

public:
    DragItem(QWidget *parent = 0);
    ~DragItem();

protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

};

#endif // DRAGITEM_H
