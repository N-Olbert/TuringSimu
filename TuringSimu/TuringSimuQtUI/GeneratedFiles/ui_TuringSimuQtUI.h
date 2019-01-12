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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TuringSimuQtUIClass
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *ReadInFileButton;
    QLineEdit *PathTextBox;
    QWidget *tab_2;
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
        tabWidget = new QTabWidget(gridLayoutWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        ReadInFileButton = new QPushButton(tab);
        ReadInFileButton->setObjectName(QString::fromUtf8("ReadInFileButton"));
        ReadInFileButton->setGeometry(QRect(420, 10, 75, 23));
        PathTextBox = new QLineEdit(tab);
        PathTextBox->setObjectName(QString::fromUtf8("PathTextBox"));
        PathTextBox->setGeometry(QRect(10, 10, 113, 20));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

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
        ReadInFileButton->setText(QApplication::translate("TuringSimuQtUIClass", "PushButton", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("TuringSimuQtUIClass", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("TuringSimuQtUIClass", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TuringSimuQtUIClass: public Ui_TuringSimuQtUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TURINGSIMUQTUI_H
