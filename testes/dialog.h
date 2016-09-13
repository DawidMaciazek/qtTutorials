#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

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
    void childrenEdited(QString str);

private:
    Ui::Dialog *ui;

    int deletedItems;
    int counter;
    int namesNum;
    QVector<QString> names;
};

#endif // DIALOG_H
