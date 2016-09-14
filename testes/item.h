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

    void on_comboBox_currentIndexChanged(int index);

signals:
    void removeItem(int index);
    void deleteItem(Item *item);

private:
    Ui::Item *ui;
    QString name;
    int index;
    bool isDestroyable;
    QWidget *currentDisplay;

};

#endif // ITEM_H
