#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TuringSimuQtUI.h"

class TuringSimuQtUI : public QMainWindow
{
	Q_OBJECT

public:
	TuringSimuQtUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::TuringSimuQtUIClass ui;
};
