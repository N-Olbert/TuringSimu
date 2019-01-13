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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "tapeletter.hpp"

QT_BEGIN_NAMESPACE

class Ui_TuringSimuQtUIClass
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *MachineExecutionTab;
    QPushButton *LoadFileButton;
    QLineEdit *PathTextBox;
    QGroupBox *MachineExecutionGroupBox;
    QGroupBox *groupBox_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *TapeLetterContainer;
    TapeLetter *plainTextEdit_4;
    TapeLetter *plainTextEdit_11;
    TapeLetter *plainTextEdit_12;
    TapeLetter *plainTextEdit_6;
    TapeLetter *plainTextEdit_7;
    TapeLetter *plainTextEdit_9;
    TapeLetter *plainTextEdit_17;
    TapeLetter *plainTextEdit_15;
    TapeLetter *plainTextEdit_16;
    TapeLetter *plainTextEdit_14;
    TapeLetter *plainTextEdit_13;
    TapeLetter *plainTextEdit_10;
    TapeLetter *plainTextEdit_8;
    TapeLetter *plainTextEdit_5;
    QLineEdit *InitialTapeContentInput;
    QLabel *label;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *TapeHeaderContainer;
    TapeLetter *plainTextEdit_20;
    TapeLetter *plainTextEdit_18;
    TapeLetter *plainTextEdit_29;
    TapeLetter *plainTextEdit_23;
    TapeLetter *plainTextEdit_22;
    TapeLetter *plainTextEdit_24;
    TapeLetter *plainTextEdit_30;
    TapeLetter *plainTextEdit_21;
    TapeLetter *plainTextEdit_31;
    TapeLetter *plainTextEdit_26;
    TapeLetter *plainTextEdit_32;
    TapeLetter *plainTextEdit_19;
    TapeLetter *plainTextEdit_33;
    TapeLetter *plainTextEdit_28;
    QPushButton *RunButton;
    QPushButton *StepButton;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *StateLabel;
    QLabel *CharLabel;
    QPushButton *ResetButton;
    QLabel *label_2;
    QWidget *MachineGenerationTab;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TuringSimuQtUIClass)
    {
        if (TuringSimuQtUIClass->objectName().isEmpty())
            TuringSimuQtUIClass->setObjectName(QString::fromUtf8("TuringSimuQtUIClass"));
        TuringSimuQtUIClass->resize(600, 600);
        TuringSimuQtUIClass->setMinimumSize(QSize(600, 600));
        TuringSimuQtUIClass->setMaximumSize(QSize(600, 600));
        centralWidget = new QWidget(TuringSimuQtUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(-1, -1, 591, 551));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(gridLayoutWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        MachineExecutionTab = new QWidget();
        MachineExecutionTab->setObjectName(QString::fromUtf8("MachineExecutionTab"));
        LoadFileButton = new QPushButton(MachineExecutionTab);
        LoadFileButton->setObjectName(QString::fromUtf8("LoadFileButton"));
        LoadFileButton->setGeometry(QRect(500, 10, 75, 23));
        PathTextBox = new QLineEdit(MachineExecutionTab);
        PathTextBox->setObjectName(QString::fromUtf8("PathTextBox"));
        PathTextBox->setGeometry(QRect(162, 10, 331, 20));
        MachineExecutionGroupBox = new QGroupBox(MachineExecutionTab);
        MachineExecutionGroupBox->setObjectName(QString::fromUtf8("MachineExecutionGroupBox"));
        MachineExecutionGroupBox->setGeometry(QRect(0, 40, 581, 481));
        groupBox_2 = new QGroupBox(MachineExecutionGroupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 250, 561, 151));
        horizontalLayoutWidget = new QWidget(groupBox_2);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 80, 546, 61));
        TapeLetterContainer = new QHBoxLayout(horizontalLayoutWidget);
        TapeLetterContainer->setSpacing(6);
        TapeLetterContainer->setContentsMargins(11, 11, 11, 11);
        TapeLetterContainer->setObjectName(QString::fromUtf8("TapeLetterContainer"));
        TapeLetterContainer->setContentsMargins(10, 10, 10, 10);
        plainTextEdit_4 = new TapeLetter(horizontalLayoutWidget);
        plainTextEdit_4->setObjectName(QString::fromUtf8("plainTextEdit_4"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plainTextEdit_4->sizePolicy().hasHeightForWidth());
        plainTextEdit_4->setSizePolicy(sizePolicy);
        plainTextEdit_4->setMaximumSize(QSize(32, 32));

        TapeLetterContainer->addWidget(plainTextEdit_4);

        plainTextEdit_11 = new TapeLetter(horizontalLayoutWidget);
        plainTextEdit_11->setObjectName(QString::fromUtf8("plainTextEdit_11"));
        sizePolicy.setHeightForWidth(plainTextEdit_11->sizePolicy().hasHeightForWidth());
        plainTextEdit_11->setSizePolicy(sizePolicy);
        plainTextEdit_11->setMaximumSize(QSize(32, 32));

        TapeLetterContainer->addWidget(plainTextEdit_11);

        plainTextEdit_12 = new TapeLetter(horizontalLayoutWidget);
        plainTextEdit_12->setObjectName(QString::fromUtf8("plainTextEdit_12"));
        sizePolicy.setHeightForWidth(plainTextEdit_12->sizePolicy().hasHeightForWidth());
        plainTextEdit_12->setSizePolicy(sizePolicy);
        plainTextEdit_12->setMaximumSize(QSize(32, 32));

        TapeLetterContainer->addWidget(plainTextEdit_12);

        plainTextEdit_6 = new TapeLetter(horizontalLayoutWidget);
        plainTextEdit_6->setObjectName(QString::fromUtf8("plainTextEdit_6"));
        sizePolicy.setHeightForWidth(plainTextEdit_6->sizePolicy().hasHeightForWidth());
        plainTextEdit_6->setSizePolicy(sizePolicy);
        plainTextEdit_6->setMaximumSize(QSize(32, 32));

        TapeLetterContainer->addWidget(plainTextEdit_6);

        plainTextEdit_7 = new TapeLetter(horizontalLayoutWidget);
        plainTextEdit_7->setObjectName(QString::fromUtf8("plainTextEdit_7"));
        sizePolicy.setHeightForWidth(plainTextEdit_7->sizePolicy().hasHeightForWidth());
        plainTextEdit_7->setSizePolicy(sizePolicy);
        plainTextEdit_7->setMaximumSize(QSize(32, 32));

        TapeLetterContainer->addWidget(plainTextEdit_7);

        plainTextEdit_9 = new TapeLetter(horizontalLayoutWidget);
        plainTextEdit_9->setObjectName(QString::fromUtf8("plainTextEdit_9"));
        sizePolicy.setHeightForWidth(plainTextEdit_9->sizePolicy().hasHeightForWidth());
        plainTextEdit_9->setSizePolicy(sizePolicy);
        plainTextEdit_9->setMaximumSize(QSize(32, 32));

        TapeLetterContainer->addWidget(plainTextEdit_9);

        plainTextEdit_17 = new TapeLetter(horizontalLayoutWidget);
        plainTextEdit_17->setObjectName(QString::fromUtf8("plainTextEdit_17"));
        sizePolicy.setHeightForWidth(plainTextEdit_17->sizePolicy().hasHeightForWidth());
        plainTextEdit_17->setSizePolicy(sizePolicy);
        plainTextEdit_17->setMaximumSize(QSize(32, 32));

        TapeLetterContainer->addWidget(plainTextEdit_17);

        plainTextEdit_15 = new TapeLetter(horizontalLayoutWidget);
        plainTextEdit_15->setObjectName(QString::fromUtf8("plainTextEdit_15"));
        sizePolicy.setHeightForWidth(plainTextEdit_15->sizePolicy().hasHeightForWidth());
        plainTextEdit_15->setSizePolicy(sizePolicy);
        plainTextEdit_15->setMaximumSize(QSize(32, 32));

        TapeLetterContainer->addWidget(plainTextEdit_15);

        plainTextEdit_16 = new TapeLetter(horizontalLayoutWidget);
        plainTextEdit_16->setObjectName(QString::fromUtf8("plainTextEdit_16"));
        sizePolicy.setHeightForWidth(plainTextEdit_16->sizePolicy().hasHeightForWidth());
        plainTextEdit_16->setSizePolicy(sizePolicy);
        plainTextEdit_16->setMaximumSize(QSize(32, 32));

        TapeLetterContainer->addWidget(plainTextEdit_16);

        plainTextEdit_14 = new TapeLetter(horizontalLayoutWidget);
        plainTextEdit_14->setObjectName(QString::fromUtf8("plainTextEdit_14"));
        sizePolicy.setHeightForWidth(plainTextEdit_14->sizePolicy().hasHeightForWidth());
        plainTextEdit_14->setSizePolicy(sizePolicy);
        plainTextEdit_14->setMaximumSize(QSize(32, 32));

        TapeLetterContainer->addWidget(plainTextEdit_14);

        plainTextEdit_13 = new TapeLetter(horizontalLayoutWidget);
        plainTextEdit_13->setObjectName(QString::fromUtf8("plainTextEdit_13"));
        sizePolicy.setHeightForWidth(plainTextEdit_13->sizePolicy().hasHeightForWidth());
        plainTextEdit_13->setSizePolicy(sizePolicy);
        plainTextEdit_13->setMaximumSize(QSize(32, 32));

        TapeLetterContainer->addWidget(plainTextEdit_13);

        plainTextEdit_10 = new TapeLetter(horizontalLayoutWidget);
        plainTextEdit_10->setObjectName(QString::fromUtf8("plainTextEdit_10"));
        sizePolicy.setHeightForWidth(plainTextEdit_10->sizePolicy().hasHeightForWidth());
        plainTextEdit_10->setSizePolicy(sizePolicy);
        plainTextEdit_10->setMaximumSize(QSize(32, 32));

        TapeLetterContainer->addWidget(plainTextEdit_10);

        plainTextEdit_8 = new TapeLetter(horizontalLayoutWidget);
        plainTextEdit_8->setObjectName(QString::fromUtf8("plainTextEdit_8"));
        sizePolicy.setHeightForWidth(plainTextEdit_8->sizePolicy().hasHeightForWidth());
        plainTextEdit_8->setSizePolicy(sizePolicy);
        plainTextEdit_8->setMaximumSize(QSize(32, 32));

        TapeLetterContainer->addWidget(plainTextEdit_8);

        plainTextEdit_5 = new TapeLetter(horizontalLayoutWidget);
        plainTextEdit_5->setObjectName(QString::fromUtf8("plainTextEdit_5"));
        sizePolicy.setHeightForWidth(plainTextEdit_5->sizePolicy().hasHeightForWidth());
        plainTextEdit_5->setSizePolicy(sizePolicy);
        plainTextEdit_5->setMaximumSize(QSize(32, 32));

        TapeLetterContainer->addWidget(plainTextEdit_5);

        InitialTapeContentInput = new QLineEdit(groupBox_2);
        InitialTapeContentInput->setObjectName(QString::fromUtf8("InitialTapeContentInput"));
        InitialTapeContentInput->setGeometry(QRect(120, 20, 431, 20));
        QFont font;
        font.setPointSize(12);
        InitialTapeContentInput->setFont(font);
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 151, 16));
        label->setFont(font);
        horizontalLayoutWidget_2 = new QWidget(groupBox_2);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 52, 546, 51));
        TapeHeaderContainer = new QHBoxLayout(horizontalLayoutWidget_2);
        TapeHeaderContainer->setSpacing(6);
        TapeHeaderContainer->setContentsMargins(11, 11, 11, 11);
        TapeHeaderContainer->setObjectName(QString::fromUtf8("TapeHeaderContainer"));
        TapeHeaderContainer->setContentsMargins(10, 0, 10, 0);
        plainTextEdit_20 = new TapeLetter(horizontalLayoutWidget_2);
        plainTextEdit_20->setObjectName(QString::fromUtf8("plainTextEdit_20"));
        sizePolicy.setHeightForWidth(plainTextEdit_20->sizePolicy().hasHeightForWidth());
        plainTextEdit_20->setSizePolicy(sizePolicy);
        plainTextEdit_20->setMaximumSize(QSize(32, 32));
        plainTextEdit_20->setFrameShape(QFrame::NoFrame);
        plainTextEdit_20->setFrameShadow(QFrame::Sunken);

        TapeHeaderContainer->addWidget(plainTextEdit_20);

        plainTextEdit_18 = new TapeLetter(horizontalLayoutWidget_2);
        plainTextEdit_18->setObjectName(QString::fromUtf8("plainTextEdit_18"));
        sizePolicy.setHeightForWidth(plainTextEdit_18->sizePolicy().hasHeightForWidth());
        plainTextEdit_18->setSizePolicy(sizePolicy);
        plainTextEdit_18->setMaximumSize(QSize(32, 32));
        plainTextEdit_18->setFrameShape(QFrame::NoFrame);
        plainTextEdit_18->setFrameShadow(QFrame::Sunken);

        TapeHeaderContainer->addWidget(plainTextEdit_18);

        plainTextEdit_29 = new TapeLetter(horizontalLayoutWidget_2);
        plainTextEdit_29->setObjectName(QString::fromUtf8("plainTextEdit_29"));
        sizePolicy.setHeightForWidth(plainTextEdit_29->sizePolicy().hasHeightForWidth());
        plainTextEdit_29->setSizePolicy(sizePolicy);
        plainTextEdit_29->setMaximumSize(QSize(32, 32));
        plainTextEdit_29->setFrameShape(QFrame::NoFrame);
        plainTextEdit_29->setFrameShadow(QFrame::Sunken);

        TapeHeaderContainer->addWidget(plainTextEdit_29);

        plainTextEdit_23 = new TapeLetter(horizontalLayoutWidget_2);
        plainTextEdit_23->setObjectName(QString::fromUtf8("plainTextEdit_23"));
        sizePolicy.setHeightForWidth(plainTextEdit_23->sizePolicy().hasHeightForWidth());
        plainTextEdit_23->setSizePolicy(sizePolicy);
        plainTextEdit_23->setMaximumSize(QSize(32, 32));
        plainTextEdit_23->setFrameShape(QFrame::NoFrame);
        plainTextEdit_23->setFrameShadow(QFrame::Sunken);

        TapeHeaderContainer->addWidget(plainTextEdit_23);

        plainTextEdit_22 = new TapeLetter(horizontalLayoutWidget_2);
        plainTextEdit_22->setObjectName(QString::fromUtf8("plainTextEdit_22"));
        sizePolicy.setHeightForWidth(plainTextEdit_22->sizePolicy().hasHeightForWidth());
        plainTextEdit_22->setSizePolicy(sizePolicy);
        plainTextEdit_22->setMaximumSize(QSize(32, 32));
        plainTextEdit_22->setFrameShape(QFrame::NoFrame);
        plainTextEdit_22->setFrameShadow(QFrame::Sunken);

        TapeHeaderContainer->addWidget(plainTextEdit_22);

        plainTextEdit_24 = new TapeLetter(horizontalLayoutWidget_2);
        plainTextEdit_24->setObjectName(QString::fromUtf8("plainTextEdit_24"));
        sizePolicy.setHeightForWidth(plainTextEdit_24->sizePolicy().hasHeightForWidth());
        plainTextEdit_24->setSizePolicy(sizePolicy);
        plainTextEdit_24->setMaximumSize(QSize(32, 32));
        plainTextEdit_24->setFrameShape(QFrame::NoFrame);

        TapeHeaderContainer->addWidget(plainTextEdit_24);

        plainTextEdit_30 = new TapeLetter(horizontalLayoutWidget_2);
        plainTextEdit_30->setObjectName(QString::fromUtf8("plainTextEdit_30"));
        sizePolicy.setHeightForWidth(plainTextEdit_30->sizePolicy().hasHeightForWidth());
        plainTextEdit_30->setSizePolicy(sizePolicy);
        plainTextEdit_30->setMaximumSize(QSize(32, 32));
        plainTextEdit_30->setFrameShape(QFrame::NoFrame);
        plainTextEdit_30->setFrameShadow(QFrame::Sunken);

        TapeHeaderContainer->addWidget(plainTextEdit_30);

        plainTextEdit_21 = new TapeLetter(horizontalLayoutWidget_2);
        plainTextEdit_21->setObjectName(QString::fromUtf8("plainTextEdit_21"));
        sizePolicy.setHeightForWidth(plainTextEdit_21->sizePolicy().hasHeightForWidth());
        plainTextEdit_21->setSizePolicy(sizePolicy);
        plainTextEdit_21->setMaximumSize(QSize(32, 32));
        plainTextEdit_21->setAutoFillBackground(false);
        plainTextEdit_21->setFrameShape(QFrame::NoFrame);
        plainTextEdit_21->setFrameShadow(QFrame::Sunken);

        TapeHeaderContainer->addWidget(plainTextEdit_21);

        plainTextEdit_31 = new TapeLetter(horizontalLayoutWidget_2);
        plainTextEdit_31->setObjectName(QString::fromUtf8("plainTextEdit_31"));
        sizePolicy.setHeightForWidth(plainTextEdit_31->sizePolicy().hasHeightForWidth());
        plainTextEdit_31->setSizePolicy(sizePolicy);
        plainTextEdit_31->setMaximumSize(QSize(32, 32));
        plainTextEdit_31->setFrameShape(QFrame::NoFrame);
        plainTextEdit_31->setFrameShadow(QFrame::Sunken);
        plainTextEdit_31->setProperty("Tag", QVariant(1));
        plainTextEdit_31->setProperty("Displayed", QVariant(QChar(0)));

        TapeHeaderContainer->addWidget(plainTextEdit_31);

        plainTextEdit_26 = new TapeLetter(horizontalLayoutWidget_2);
        plainTextEdit_26->setObjectName(QString::fromUtf8("plainTextEdit_26"));
        sizePolicy.setHeightForWidth(plainTextEdit_26->sizePolicy().hasHeightForWidth());
        plainTextEdit_26->setSizePolicy(sizePolicy);
        plainTextEdit_26->setMaximumSize(QSize(32, 32));
        plainTextEdit_26->setFrameShape(QFrame::NoFrame);
        plainTextEdit_26->setFrameShadow(QFrame::Sunken);

        TapeHeaderContainer->addWidget(plainTextEdit_26);

        plainTextEdit_32 = new TapeLetter(horizontalLayoutWidget_2);
        plainTextEdit_32->setObjectName(QString::fromUtf8("plainTextEdit_32"));
        sizePolicy.setHeightForWidth(plainTextEdit_32->sizePolicy().hasHeightForWidth());
        plainTextEdit_32->setSizePolicy(sizePolicy);
        plainTextEdit_32->setMaximumSize(QSize(32, 32));
        plainTextEdit_32->setFrameShape(QFrame::NoFrame);
        plainTextEdit_32->setFrameShadow(QFrame::Sunken);

        TapeHeaderContainer->addWidget(plainTextEdit_32);

        plainTextEdit_19 = new TapeLetter(horizontalLayoutWidget_2);
        plainTextEdit_19->setObjectName(QString::fromUtf8("plainTextEdit_19"));
        sizePolicy.setHeightForWidth(plainTextEdit_19->sizePolicy().hasHeightForWidth());
        plainTextEdit_19->setSizePolicy(sizePolicy);
        plainTextEdit_19->setMaximumSize(QSize(32, 32));
        plainTextEdit_19->setFrameShape(QFrame::NoFrame);
        plainTextEdit_19->setFrameShadow(QFrame::Sunken);

        TapeHeaderContainer->addWidget(plainTextEdit_19);

        plainTextEdit_33 = new TapeLetter(horizontalLayoutWidget_2);
        plainTextEdit_33->setObjectName(QString::fromUtf8("plainTextEdit_33"));
        sizePolicy.setHeightForWidth(plainTextEdit_33->sizePolicy().hasHeightForWidth());
        plainTextEdit_33->setSizePolicy(sizePolicy);
        plainTextEdit_33->setMaximumSize(QSize(32, 32));
        plainTextEdit_33->setFrameShape(QFrame::NoFrame);
        plainTextEdit_33->setFrameShadow(QFrame::Sunken);

        TapeHeaderContainer->addWidget(plainTextEdit_33);

        plainTextEdit_28 = new TapeLetter(horizontalLayoutWidget_2);
        plainTextEdit_28->setObjectName(QString::fromUtf8("plainTextEdit_28"));
        sizePolicy.setHeightForWidth(plainTextEdit_28->sizePolicy().hasHeightForWidth());
        plainTextEdit_28->setSizePolicy(sizePolicy);
        plainTextEdit_28->setMaximumSize(QSize(32, 32));
        plainTextEdit_28->setFrameShape(QFrame::NoFrame);
        plainTextEdit_28->setFrameShadow(QFrame::Sunken);

        TapeHeaderContainer->addWidget(plainTextEdit_28);

        RunButton = new QPushButton(MachineExecutionGroupBox);
        RunButton->setObjectName(QString::fromUtf8("RunButton"));
        RunButton->setGeometry(QRect(360, 420, 61, 51));
        StepButton = new QPushButton(MachineExecutionGroupBox);
        StepButton->setObjectName(QString::fromUtf8("StepButton"));
        StepButton->setGeometry(QRect(430, 420, 61, 51));
        label_3 = new QLabel(MachineExecutionGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 410, 151, 31));
        QFont font1;
        font1.setPointSize(18);
        label_3->setFont(font1);
        label_4 = new QLabel(MachineExecutionGroupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 440, 151, 31));
        label_4->setFont(font1);
        StateLabel = new QLabel(MachineExecutionGroupBox);
        StateLabel->setObjectName(QString::fromUtf8("StateLabel"));
        StateLabel->setGeometry(QRect(170, 410, 191, 31));
        StateLabel->setFont(font1);
        CharLabel = new QLabel(MachineExecutionGroupBox);
        CharLabel->setObjectName(QString::fromUtf8("CharLabel"));
        CharLabel->setGeometry(QRect(170, 440, 151, 31));
        CharLabel->setFont(font1);
        ResetButton = new QPushButton(MachineExecutionGroupBox);
        ResetButton->setObjectName(QString::fromUtf8("ResetButton"));
        ResetButton->setGeometry(QRect(500, 420, 61, 51));
        label_2 = new QLabel(MachineExecutionTab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 151, 16));
        tabWidget->addTab(MachineExecutionTab, QString());
        MachineGenerationTab = new QWidget();
        MachineGenerationTab->setObjectName(QString::fromUtf8("MachineGenerationTab"));
        MachineGenerationTab->setEnabled(false);
        tabWidget->addTab(MachineGenerationTab, QString());

        gridLayout->addWidget(tabWidget, 0, 1, 1, 1);

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

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TuringSimuQtUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *TuringSimuQtUIClass)
    {
        TuringSimuQtUIClass->setWindowTitle(QApplication::translate("TuringSimuQtUIClass", "TuringSimuQtUI", nullptr));
        LoadFileButton->setText(QApplication::translate("TuringSimuQtUIClass", "Load", nullptr));
        MachineExecutionGroupBox->setTitle(QApplication::translate("TuringSimuQtUIClass", "Machine", nullptr));
        groupBox_2->setTitle(QApplication::translate("TuringSimuQtUIClass", "Tape", nullptr));
        label->setText(QApplication::translate("TuringSimuQtUIClass", "Initial content:", nullptr));
        RunButton->setText(QApplication::translate("TuringSimuQtUIClass", "Run", nullptr));
        StepButton->setText(QApplication::translate("TuringSimuQtUIClass", "Step", nullptr));
        label_3->setText(QApplication::translate("TuringSimuQtUIClass", "Current state:", nullptr));
        label_4->setText(QApplication::translate("TuringSimuQtUIClass", "Current char:", nullptr));
        StateLabel->setText(QApplication::translate("TuringSimuQtUIClass", "State", nullptr));
        CharLabel->setText(QApplication::translate("TuringSimuQtUIClass", "#", nullptr));
        ResetButton->setText(QApplication::translate("TuringSimuQtUIClass", "Reset", nullptr));
        label_2->setText(QApplication::translate("TuringSimuQtUIClass", "Path of machine defintion file:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(MachineExecutionTab), QApplication::translate("TuringSimuQtUIClass", "Machine execution", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(MachineGenerationTab), QApplication::translate("TuringSimuQtUIClass", "Machine generation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TuringSimuQtUIClass: public Ui_TuringSimuQtUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TURINGSIMUQTUI_H
