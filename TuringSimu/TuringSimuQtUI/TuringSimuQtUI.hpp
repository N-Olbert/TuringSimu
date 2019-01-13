#pragma once
#ifndef TURINGSIMUQTUI_HPP
#define TURINGSIMUQTUI_HPP
#include <QtWidgets/QMainWindow>
#include "ui_TuringSimuQtUI.h"
#include "AbstractTuringSimuQtForm.hpp"

class TuringSimuQtUI final : public QMainWindow, public AbstractTuringSimuQtForm
{
	Q_OBJECT

	public:
		TuringSimuQtUI(QWidget *parent = Q_NULLPTR);
		~TuringSimuQtUI() override = default;
		std::string GetFilePath() override;
		size_t GetAmountOfDisplayedTapeLetters() override;
		void DisplayTapeSequence(const std::string& toDisplay) override;
		void SetTapeHeaderVisibleAt(size_t pos) override;
		std::string GetInitialTapeContent() override;
		void DisplayCurrentState(const std::string& currentState) override;
		void DisplayCurrentChar(char toDisplay) override;
		void SetEnableMachineExecutionControls(bool enable) override;
		void SetEnableRunButton(bool enable) override;
		void SetEnableResetButton(bool enable) override;
		void SetEnableStepButton(bool enable) override;
		void SetEnableInitialTapeContentInput(bool enable) override;

	//"Events" for Presenter
	signals:
		void LoadFileButtonClicked() override;
		void RunButtonClicked() override;
		void StepButtonClicked() override;
		void ResetButtonClicked() override;
		void InitialTapeContentChanged() override;

    //Private signal handlers - they only raise the events for the presenter
	//Bound by name, so we follow the name conventions of qt here
	private slots:
		void on_LoadFileButton_clicked();
		void on_RunButton_clicked(); 
	    void on_StepButton_clicked(); 
		void on_ResetButton_clicked();
		void on_InitialTapeContentInput_textChanged(const QString& input);

	private:
		Ui::TuringSimuQtUIClass ui{};
		bool EnsureGUIThreadCall(const std::function<void()>& lambda);
};

#endif // TURINGSIMUQTUI_HPP
