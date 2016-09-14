/********************************************************************************
** Form generated from reading UI file 'functioneditor.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUNCTIONEDITOR_H
#define UI_FUNCTIONEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FunctionEditor
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;

    void setupUi(QWidget *FunctionEditor)
    {
        if (FunctionEditor->objectName().isEmpty())
            FunctionEditor->setObjectName(QStringLiteral("FunctionEditor"));
        FunctionEditor->resize(742, 515);
        verticalLayout = new QVBoxLayout(FunctionEditor);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(FunctionEditor);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(FunctionEditor);

        QMetaObject::connectSlotsByName(FunctionEditor);
    } // setupUi

    void retranslateUi(QWidget *FunctionEditor)
    {
        FunctionEditor->setWindowTitle(QApplication::translate("FunctionEditor", "Form", 0));
        pushButton->setText(QApplication::translate("FunctionEditor", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class FunctionEditor: public Ui_FunctionEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUNCTIONEDITOR_H
