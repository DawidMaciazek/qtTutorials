#ifndef FUNCTIONEDITOR_H
#define FUNCTIONEDITOR_H

#include <QWidget>

namespace Ui {
class FunctionEditor;
}

class FunctionEditor : public QWidget
{
    Q_OBJECT

public:
    explicit FunctionEditor(QWidget *parent = 0);
    ~FunctionEditor();

private:
    Ui::FunctionEditor *ui;
};

#endif // FUNCTIONEDITOR_H
