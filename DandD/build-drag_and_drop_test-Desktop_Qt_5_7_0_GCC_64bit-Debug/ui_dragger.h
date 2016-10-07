/********************************************************************************
** Form generated from reading UI file 'dragger.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAGGER_H
#define UI_DRAGGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Dragger
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QCustomPlot *widget;

    void setupUi(QWidget *Dragger)
    {
        if (Dragger->objectName().isEmpty())
            Dragger->setObjectName(QStringLiteral("Dragger"));
        Dragger->resize(455, 239);
        horizontalLayout = new QHBoxLayout(Dragger);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Dragger);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        widget = new QCustomPlot(Dragger);
        widget->setObjectName(QStringLiteral("widget"));

        horizontalLayout->addWidget(widget);


        retranslateUi(Dragger);

        QMetaObject::connectSlotsByName(Dragger);
    } // setupUi

    void retranslateUi(QWidget *Dragger)
    {
        Dragger->setWindowTitle(QApplication::translate("Dragger", "Form", 0));
        label->setText(QApplication::translate("Dragger", "Dragger ....", 0));
    } // retranslateUi

};

namespace Ui {
    class Dragger: public Ui_Dragger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAGGER_H
