#ifndef MYLOGIN_H
#define MYLOGIN_H

#include <QWidget>

namespace Ui {
class MyLogin;
}

class MyLogin : public QWidget
{
    Q_OBJECT

public:
    explicit MyLogin(QWidget *parent = 0);
    ~MyLogin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MyLogin *ui;
};

#endif // MYLOGIN_H
