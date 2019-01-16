#ifndef TURINGSIMUQTPRESENTER_H
#define TURINGSIMUQTPRESENTER_H

#include <QObject>
#include <../../TuringSimuCommon/UI/Header/MachineExecutionController.hpp>
#include "AbstractTuringSimuQtForm.hpp"

using namespace ts_ui;
using namespace ts_common;
using namespace ts_ui_business;
class TuringSimuQtPresenter : public QObject
{
	Q_OBJECT
	private:
		AbstractTuringSimuQtForm* view;
		std::unique_ptr<AbstractMachine> currentMachine;
		std::unique_ptr<MachineExecutionController> model;
		std::mutex presenterMutex;
		std::atomic_bool EXECUTING = false;
		std::atomic_bool listeningForStepButtonClick = false;
		std::atomic_bool clickOnStepButtonOccured = false;
		std::atomic_bool autoRunMode = false;
		std::atomic_bool disposing = false;

	public:
		~TuringSimuQtPresenter();
		void AwaitExceutionCompleted();
		explicit TuringSimuQtPresenter(AbstractTuringSimuQtForm* view, QObject *parent = nullptr);
		void DisplayTapeSequence(std::string& toDisplay, size_t pos) const;
		void AdjustTapeSize(std::string& toDisplay, size_t pos) const;
		void SetTapeHeaderVisibleAt(size_t pos, std::string& tape);
		std::string GetInitialTapeContent() const;
		void DisplayCurrentState(const std::string& currentState) const;
		void DisplayCurrentChar(char toDisplay) const;
		void ExitSeparateThreadExecutionMode();
		void AwaitClickOnStepButton();
		bool GetIsAutoRunMode() const;
		void StartMachineExecution(bool autoRun);
		void DisplayCurrentStep(size_t step);
		void HighlightTransition(const BaseTransition& transition);


	private slots:
		void HandleLoadFileButtonClicked();
		void HandleRunButtonClicked();
		void HandleStepButtonClicked();
		void HandleResetButtonClicked();
		void HandleInitialTapeContentChanged();

	private:
		void FireAndForget(const std::function<void()>& lambda);
		void FireAndAwait(const std::function<void()>& lambda);

};
#endif // TURINGSIMUQTPRESENTER_H
