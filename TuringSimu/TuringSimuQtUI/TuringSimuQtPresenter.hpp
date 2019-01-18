#ifndef TURINGSIMUQTPRESENTER_H
#define TURINGSIMUQTPRESENTER_H
#include <QObject>
#include <../../TuringSimuCommon/UI/Header/MachineExecutionController.hpp>
#include "AbstractTuringSimuQtForm.hpp"
using namespace ts_ui;
using namespace ts_common;
using namespace ts_ui_business;

/**
 * @brief The presenter class
 */
class TuringSimuQtPresenter : public QObject
{
	Q_OBJECT
	private:

        /**
         * @brief The view.
         */
		AbstractTuringSimuQtForm* view;

        /**
         * @brief The currently loaded (and hopefully displayed) machine
         */
		std::unique_ptr<AbstractMachine> currentMachine;

        /**
         * @brief The model which may execute the currently loaded machine.
         */
		std::unique_ptr<MachineExecutionController> model;

        /**
         * @brief Mutex to avoid multiple execution of the loaded machine.
         */
		std::mutex presenterMutex;

        /**
         * @brief A thread save boolean indicating whether the model currently
         * executes the loaded machine (within a separate thread)
         */
		std::atomic_bool EXECUTING = false;

        /**
         * @brief A thread save boolean indicating whether we are currently awaiting a click onto the step button or not.
         */
		std::atomic_bool listeningForStepButtonClick = false;

        /**
         * @brief A thread save boolean indicating a click onto the step button has occurred.
         */
		std::atomic_bool clickOnStepButtonOccured = false;

        /**
         * @brief A thread save boolean indicating whether the user wants the
         * machine execution to happen automatically or not.
         */
		std::atomic_bool autoRunMode = false;

        /**
         * @brief A thread save boolean indicating whether the current instance is about to be disposed (-> destructor has been called)
         */
		std::atomic_bool disposing = false;

	public:
		~TuringSimuQtPresenter();
		explicit TuringSimuQtPresenter(AbstractTuringSimuQtForm* view, QObject *parent = nullptr);

        /**
         * @brief Displays the given sequence on the tape.
         * @param toDisplay The sequence to display on the tape.
         */
		void DisplayTapeSequence(std::string& toDisplay, size_t pos) const;

        /**
         * @brief Makes the header visible above the tape content on the specified postion.
         * @param pos The position where to make the tape header visible. Must be
         * within a range of 0 till GetAmountOfDisplayedTapeLetters() -1
         */
		void SetTapeHeaderVisibleAt(size_t pos, std::string& tape);

        /**
         * @brief Gets the initial tape content which has been entered by the user.
         * @return The initial tape content.
         */
		std::string GetInitialTapeContent() const;

        /**
         * @brief Displays the given state as current state of the machine.
         * @param currentState The current state of the machine to display.
         */
		void DisplayCurrentState(const std::string& currentState) const;

        /**
         * @brief Displays the given char as the char which is currently read by the machine.
         * @param currentState The char which is currently read by the machine.
         */
		void DisplayCurrentChar(char toDisplay) const;

        /**
         * @brief Callback method. When this method is called the model notifes the presenter
         * that the machine execution (which has happened in a different thread) is finished.
         */
		void ExitSeparateThreadExecutionMode();

        /**
         * @brief Blocks the calling thread till a click onto the "Step"-button occured.
         */
		void AwaitClickOnStepButton();

        /**
         * @brief Retruns a value indicating whether the user wants to execute the machine automatically or not.
         * @return A value indicating whether the user wants to execute the machine automatically or not
         */
		bool GetIsAutoRunMode() const;

        /**
         * @brief Display the given step.
         * @param currentState The current step.
         */
		void DisplayCurrentStep(size_t step);

        /**
         * @brief Highlights a given transion within the transition table.
         * @param transition The transiton to highlight
         */
		void HighlightTransition(const BaseTransition& transition);

    // Signals which may be raised by the view when certain actions occur -> Handle them in presenter
	private slots:
		void HandleLoadFileButtonClicked();
		void HandleRunButtonClicked();
		void HandleStepButtonClicked();
		void HandleResetButtonClicked();
		void HandleInitialTapeContentChanged();

	private:

        /**
         * @brief Stats the machine execution (within the model)
         * @param A value indicating whether the execution should happen automatically or manually.
         */
        void StartMachineExecution(bool autoRun);

        /**
         * @brief Requests a cancellation of the current machine execution and blocks the calling thread till the
         * model finished the execution.
         */
        void AwaitExceutionCompleted();

        /**
         * @brief Adjusts the tape we get from the model so that it fits the current view perfectly.
         * @param tape The raw tape data.
         * @param pos The raw position of the head.
         */
        void AdjustTapeForView(std::string& tape, size_t pos) const;

        /**
         * @brief Executes the given lamda in a spearate thread.
         * @param lambda The lambda to execute.
         */
		void FireAndForget(const std::function<void()>& lambda);

        /**
         * @brief Executes the given lamda in a spearate thread and blocks the calling thread till the execution has finished.
         * @param lambda The lambda to execute.
         */
		void FireAndAwait(const std::function<void()>& lambda);

};
#endif // TURINGSIMUQTPRESENTER_H
