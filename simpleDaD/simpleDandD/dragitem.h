#ifndef DRAGITEM_H
#define DRAGITEM_H

#include <QLabel>

class DragItem : public QLabel
{
    Q_OBJECT

public:
    DragItem(int i, QWidget *parent = 0);
    ~DragItem();

    int number;

    static QString dragItemMimeType() { return QStringLiteral("dragitem/spectrum") ;};

protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

};

#endif // DRAGITEM_H
