#include "dialog.h"
#include "ui_dialog.h"
#include "tinyexpr.h"
enum dupa {jas, i, malgosia};

dupa[0];

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    char texp[] = "1+2+exp(11)";

    int parseErr;
    double x;

    te_variable vars[] = {{"x", &x}};
    te_expr *epar = te_compile(texp, vars, 1, &parseErr);

    te_free(epar);
}

Dialog::~Dialog()
{
    delete ui;
}
