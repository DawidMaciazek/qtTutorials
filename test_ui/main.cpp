#include "widget.h"
#include <QApplication>

#include "mylogin.h"
#include "mywidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
