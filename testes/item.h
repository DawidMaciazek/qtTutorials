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
    void on_comboBox_currentIndexChanged(int index);

    void on_toolButton_clicked();

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
