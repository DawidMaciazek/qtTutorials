/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *equalSign;
    QTextEdit *lvalueText;
    QTextEdit *resultText;
    QTextEdit *rvalueText;
    QVBoxLayout *verticalLayout;
    QPushButton *plusButton;
    QPushButton *minusButton;
    QPushButton *multiplyButton;
    QPushButton *devideButton;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(897, 347);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        equalSign = new QLabel(centralWidget);
        equalSign->setObjectName(QStringLiteral("equalSign"));

        gridLayout->addWidget(equalSign, 0, 9, 1, 1);

        lvalueText = new QTextEdit(centralWidget);
        lvalueText->setObjectName(QStringLiteral("lvalueText"));

        gridLayout->addWidget(lvalueText, 0, 0, 1, 1);

        resultText = new QTextEdit(centralWidget);
        resultText->setObjectName(QStringLiteral("resultText"));

        gridLayout->addWidget(resultText, 0, 10, 1, 1);

        rvalueText = new QTextEdit(centralWidget);
        rvalueText->setObjectName(QStringLiteral("rvalueText"));

        gridLayout->addWidget(rvalueText, 0, 8, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        plusButton = new QPushButton(centralWidget);
        plusButton->setObjectName(QStringLiteral("plusButton"));

        verticalLayout->addWidget(plusButton);

        minusButton = new QPushButton(centralWidget);
        minusButton->setObjectName(QStringLiteral("minusButton"));

        verticalLayout->addWidget(minusButton);

        multiplyButton = new QPushButton(centralWidget);
        multiplyButton->setObjectName(QStringLiteral("multiplyButton"));

        verticalLayout->addWidget(multiplyButton);

        devideButton = new QPushButton(centralWidget);
        devideButton->setObjectName(QStringLiteral("devideButton"));

        verticalLayout->addWidget(devideButton);


        gridLayout->addLayout(verticalLayout, 0, 7, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 897, 20));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        equalSign->setText(QApplication::translate("MainWindow", "=", 0));
        plusButton->setText(QApplication::translate("MainWindow", "+", 0));
        minusButton->setText(QApplication::translate("MainWindow", "-", 0));
        multiplyButton->setText(QApplication::translate("MainWindow", "*", 0));
        devideButton->setText(QApplication::translate("MainWindow", "/", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
