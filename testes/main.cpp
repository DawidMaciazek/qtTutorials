#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QLocale::setDefault(QLocale("en_EN"));
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    return a.exec();
}
