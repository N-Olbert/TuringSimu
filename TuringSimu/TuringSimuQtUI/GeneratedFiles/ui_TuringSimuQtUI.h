/********************************************************************************
** Form generated from reading UI file 'TuringSimuQtUI.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TURINGSIMUQTUI_H
#define UI_TURINGSIMUQTUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TuringSimuQtUIClass
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TuringSimuQtUIClass)
    {
        if (TuringSimuQtUIClass->objectName().isEmpty())
            TuringSimuQtUIClass->setObjectName(QString::fromUtf8("TuringSimuQtUIClass"));
        TuringSimuQtUIClass->resize(600, 400);
        centralWidget = new QWidget(TuringSimuQtUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(-1, -1, 591, 351));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        TuringSimuQtUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TuringSimuQtUIClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        TuringSimuQtUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TuringSimuQtUIClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TuringSimuQtUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TuringSimuQtUIClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TuringSimuQtUIClass->setStatusBar(statusBar);

        retranslateUi(TuringSimuQtUIClass);

        QMetaObject::connectSlotsByName(TuringSimuQtUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *TuringSimuQtUIClass)
    {
        TuringSimuQtUIClass->setWindowTitle(QApplication::translate("TuringSimuQtUIClass", "TuringSimuQtUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TuringSimuQtUIClass: public Ui_TuringSimuQtUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TURINGSIMUQTUI_H
