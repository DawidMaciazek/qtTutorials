#ifndef FUNCTIONDELTA_H
#define FUNCTIONDELTA_H

#include <QWidget>

namespace Ui {
class FunctionDelta;
}

class FunctionDelta : public QWidget
{
    Q_OBJECT

public:
    explicit FunctionDelta(QWidget *parent = 0);
    ~FunctionDelta();

private:
    Ui::FunctionDelta *ui;
};

#endif // FUNCTIONDELTA_H
