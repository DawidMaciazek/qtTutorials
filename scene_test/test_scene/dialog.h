#ifndef DIALOG_H
#define DIALOG_H

#include "ppball.h"

#include <QDialog>
#include <QGraphicsScene>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
    QGraphicsScene *scene;
    PPball *ball;
    PPball *ball2;
    QTimer *timer;
};

#endif // DIALOG_H
