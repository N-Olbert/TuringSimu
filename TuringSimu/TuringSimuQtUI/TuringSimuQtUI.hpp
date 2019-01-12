#pragma once
#ifndef TURINGSIMUQTUI_HPP
#define TURINGSIMUQTUI_HPP
#include <QtWidgets/QMainWindow>
#include "ui_TuringSimuQtUI.h"
#include "AbstractTuringSimuQtForm.hpp"

class TuringSimuQtUI : public QMainWindow, public AbstractTuringSimuQtForm
{
	Q_OBJECT

	public:
		TuringSimuQtUI(QWidget *parent = Q_NULLPTR);
		~TuringSimuQtUI() override = default;
		std::string GetPathTextBoxInput() override;

	//"Events" for Presenter
	signals:
		void ReadInFileButtonClicked() override;

    //Private signal handlers - they only raise the events for the presenter
	private slots:
		void on_ReadInFileButton_clicked();

	private:
		Ui::TuringSimuQtUIClass ui{};
};
#endif // TURINGSIMUQTUI_HPP
