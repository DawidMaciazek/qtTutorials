#ifndef ITEM_H
#define ITEM_H

#include <QWidget>
#include <QLineEdit>

namespace Ui {
class Item;
}

class Item : public QWidget
{
    Q_OBJECT

public:
    explicit Item(QString name, QWidget *parent = 0);
    ~Item();

    QLineEdit *left;

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_editingFinished();

    void on_lineEdit_2_editingFinished();

private:
    Ui::Item *ui;
    QString name;

};

#endif // ITEM_H
