#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "item.h"

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
    void chlidrenDestroyed();
    void chlidrenDestroyed(int);
    void childrenEdited(QString str);
    void removeIten(Item *item);

private:
    Ui::Dialog *ui;

    int deletedItems;
    int counter;
    int namesNum;
    QVector<QString> names;
};

#endif // DIALOG_H
