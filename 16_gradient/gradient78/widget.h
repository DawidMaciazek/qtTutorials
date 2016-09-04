#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QtCore>
#include <QtGui>

#include <QLinearGradient>
#include <QRadialGradient>
#include <QConicalGradient>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

protected:
    void paintEvent(QPaintEvent *event);

};

#endif // WIDGET_H
