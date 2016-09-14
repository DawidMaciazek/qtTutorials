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
    explicit Item(QString name, int index, QWidget *parent = 0);
    ~Item();

    QLineEdit *left;
    int getIndex();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_editingFinished();

    void on_lineEdit_2_editingFinished();

signals:
    void removeItem(int index);
    void deleteItem(Item *item);

private:
    Ui::Item *ui;
    QString name;
    int index;

};

#endif // ITEM_H
