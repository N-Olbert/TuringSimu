#pragma once
#ifndef TURINGSIMUQTUI_HPP
#define TURINGSIMUQTUI_HPP
#include "ui_TuringSimuQtUI.h"
#include "AbstractTuringSimuQtForm.hpp"
#include "../TuringSimuCommon/Common/Header/BaseTransition.hpp"
#include <QStandardItemModel>
#include <unordered_map>

using namespace ts_common;
class TuringSimuQtUI final : public QMainWindow, public AbstractTuringSimuQtForm
{
	Q_OBJECT

	private:
			QStandardItemModel tableModel;
			std::unordered_map<std::string, int> charMap;
			std::unordered_map<std::string, int> stateMap;
	public:
		TuringSimuQtUI(QWidget *parent = Q_NULLPTR);
		~TuringSimuQtUI() override;
		std::string GetFilePath() override;
		size_t GetAmountOfDisplayedTapeLetters() override;
		void DisplayTapeSequence(const std::string& toDisplay) override;
		void SetTapeHeaderVisibleAt(size_t pos) override;
		std::string GetInitialTapeContent() override;
		void DisplayCurrentState(const std::string& currentState) override;
		void DisplayCurrentChar(char toDisplay) override;
		void DisplayCurrentStep(size_t step) override;
		void SetEnableMachineExecutionControls(bool enable) override;
		void SetEnableRunButton(bool enable) override;
		void SetEnableResetButton(bool enable) override;
		void SetEnableStepButton(bool enable) override;
		void SetEnableInitialTapeContentInput(bool enable) override;
		void FillTransitionTable(const std::vector<std::string>& rows,
								 const std::vector<std::string>& cols,
								 const std::vector<const BaseTransition*> transitions) override;
		void HighlightTransition(const BaseTransition& transition) override;
		void DisplayMachineInfo(const std::string& toDisplay) override;

	protected:
		void closeEvent(QCloseEvent *event);

	//"Events" for Presenter
	public: signals:
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
