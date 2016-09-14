#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "tinyexpr.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    te_expr *eParser;
    double x;

private slots:
    void on_lineEdit_editingFinished();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
