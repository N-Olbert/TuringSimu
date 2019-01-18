#ifndef ABSTRACTTURINGSIMUQTUI_H
#define ABSTRACTTURINGSIMUQTUI_H
#include <string>
#include "../TuringSimuCommon/Common/Header/BaseTransition.hpp"
#include <vector>


using namespace ts_common;

/**
 * \brief Interface for the main Qt form containing all required methods.
 * Note that all methods are guaranteed to be executed synchronous within the UI thread, so some sort of
 * (weak) thread safety is guaranteed (anyways: you can still easily create dead locks - for example by
 * blocking the UI thread so that no message pumping can occur anymore)
 */
class AbstractTuringSimuQtForm
{
	//Methods
	public:
        /**
         * @brief Retruns the path of the file of the machine definiton which should be loded.
         * @return The file path of the machine defintion to load.
         */
        virtual std::string GetMachineDefintionFilePath() = 0;

        /**
         * @brief Gets the amount of displayed tape letters
         * @return The amount of displayed tape letters.
         */
		virtual size_t GetAmountOfDisplayedTapeLetters() = 0;

        /**
         * @brief Gets the initial tape content which has been entered by the user.
         * @return The initial tape content.
         */
		virtual std::string GetInitialTapeContent() = 0;

        /**
         * @brief Displays the given sequence on the tape.
         * @param toDisplay The sequence to display on the tape.
         */
		virtual void DisplayTapeSequence(const std::string& toDisplay) = 0;

        /**
         * @brief Makes the header visible above the tape content on the specified postion.
         * @param pos The position where to make the tape header visible. Must be
         * within a range of 0 till GetAmountOfDisplayedTapeLetters() -1
         */
		virtual void SetTapeHeaderVisibleAt(size_t pos) = 0;

        /**
         * @brief Displays the given state as current state of the machine.
         * @param currentState The current state of the machine to display.
         */
		virtual void DisplayCurrentState(const std::string& currentState) = 0;

        /**
         * @brief Displays the given char as the char which is currently read by the machine.
         * @param currentState The char which is currently read by the machine.
         */
		virtual void DisplayCurrentChar(char toDisplay) = 0;

        /**
         * @brief Display the given step.
         * @param currentState The current step.
         */
		virtual void DisplayCurrentStep(size_t step) = 0;

        /**
         * @brief Enables or disables all controls which are relevant to interact with a loaded machine
         * @param enable A value indicating whether the controls should be enabled or disabled.
         */
		virtual void SetEnableMachineExecutionControls(bool enable) = 0;

        /**
         * @brief Enables or disables the (auto) run button which starts the automatic machine execution.
         * @param enable  A value indicating whether the button should be enabled or disabled.
         */
		virtual void SetEnableRunButton(bool enable) = 0;

        /**
         * @brief Enables or disables the reset/cancel button.
         * @param enable  A value indicating whether the button should be enabled or disabled.
         */
		virtual void SetEnableResetButton(bool enable) = 0;

        /**
         * @brief Enables or disables the one-step-forward button.
         * @param enable  A value indicating whether the button should be enabled or disabled.
         */
		virtual void SetEnableStepButton(bool enable) = 0;

        /**
         * @brief Enables or disables the input control which can be used to specify the inital tape content.
         * @param enable  A value indicating whether the control should be enabled or disabled.
         */
		virtual void SetEnableInitialTapeContentInput(bool enable) = 0;

        /**
         * @brief Fills the transition table with the given information.
         * @param rows The row identifers (-> the states)
         * @param cols The column identifers (-> the alphabet)
         * @param transitions The table content (-> the transitions)
         */
		virtual void FillTransitionTable(const std::vector<std::string>& rows,
										 const std::vector<std::string>& cols,
										 const std::vector<const BaseTransition*> transitions) = 0;

        /**
         * @brief Highlights a given transion within the transition table.
         * @param transition The transiton to highlight
         */
		virtual void HighlightTransition(const BaseTransition& transition) = 0;

        /**
         * @brief Displays the given machine info text.
         * @param toDisplay The info text to display.
         */
		virtual void DisplayMachineInfo(const std::string& toDisplay) = 0;

	//Signals
	public:
		virtual ~AbstractTuringSimuQtForm() = default;

        /**
         * @brief Raised/Emited immediately after the user has clicked onto the load file button.
         */
		virtual void LoadFileButtonClicked() = 0;

        /**
         * @brief Raised/Emited immediately after the user has clicked onto the run button.
         */
		virtual void RunButtonClicked() = 0;

        /**
         * @brief Raised/Emited immediately after the user has clicked onto the step button.
         */
		virtual void StepButtonClicked() = 0;

        /**
         * @brief Raised/Emited immediately after the user has clicked onto the reset button.
         */
		virtual void ResetButtonClicked() = 0;

        /**
         * @brief Raised/Emited immediately after the inital tape content has changed.
         */
		virtual void InitialTapeContentChanged() = 0;
};

#endif // ABSTRACTTURINGSIMUQTUI_H
