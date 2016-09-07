#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    loadSettings();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    // save
    saveSettings();
}

void Dialog::saveSettings()
{
    QSettings settings("myOrganisation", "myapp");
    settings.beginGroup("MainWidnow");

    settings.setValue("position", this->geometry());
    settings.endGroup();

    qDebug() << "Settings saved !";
}

void Dialog::on_pushButton_2_clicked()
{
    // load
    loadSettings();
}

void Dialog::loadSettings()
{
    QSettings settings("myOrganisation", "myapp");
    settings.beginGroup("MainWidnow");
    QRect myrect = settings.value("position").toRect();
    setGeometry(myrect);
    settings.endGroup();

    qDebug() << "Settings loaded !";
}
