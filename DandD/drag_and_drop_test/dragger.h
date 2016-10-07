#ifndef DRAGGER_H
#define DRAGGER_H

#include <QWidget>

namespace Ui {
class Dragger;
}

class Dragger : public QWidget
{
    Q_OBJECT

public:
    explicit Dragger(QWidget *parent = 0);
    ~Dragger();

protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

private:
    Ui::Dragger *ui;
};

#endif // DRAGGER_H
