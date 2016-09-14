#ifndef FUNCTIONGAUSS_H
#define FUNCTIONGAUSS_H

#include <QWidget>

namespace Ui {
class functionGauss;
}

class functionGauss : public QWidget
{
    Q_OBJECT

public:
    explicit functionGauss(QWidget *parent = 0);
    ~functionGauss();

private:
    Ui::functionGauss *ui;
};

#endif // FUNCTIONGAUSS_H
