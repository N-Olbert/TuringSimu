#ifndef ABSTRACTTURINGSIMUQTUI_H
#define ABSTRACTTURINGSIMUQTUI_H
#include <string>
/**
 * \brief Interface for the main Qt form containing all required methods.
 * Note that all methods are guaranteed to be executed synchronous within the UI thread, so some sort of
 * weak thread safety is guaranteed (anyways: you can still easily create dead locks - for example by 
 * blocking the UI thread so that no message pumping can occur anymore)
 */
class AbstractTuringSimuQtForm
{
    //Methods
    public:
        virtual std::string GetFilePath() = 0;
		virtual size_t GetAmountOfDisplayedTapeLetters() = 0;
		virtual std::string GetInitialTapeContent() = 0;
		virtual void DisplayTapeSequence(const std::string& toDisplay) = 0;
		virtual void SetTapeHeaderVisibleAt(size_t pos) = 0;
		virtual void DisplayCurrentState(const std::string& currentState) = 0;
		virtual void DisplayCurrentChar(char toDisplay) = 0;
		virtual void SetEnableMachineExecutionControls(bool enable) = 0;
		virtual void SetEnableRunButton(bool enable) = 0;
		virtual void SetEnableResetButton(bool enable) = 0;
		virtual void SetEnableStepButton(bool enable) = 0;
		virtual void SetEnableInitialTapeContentInput(bool enable) = 0;

    //Signals
    public:
        virtual ~AbstractTuringSimuQtForm() = default;
        virtual void LoadFileButtonClicked() = 0;
		virtual void RunButtonClicked() = 0;
		virtual void StepButtonClicked() = 0;
		virtual void ResetButtonClicked() = 0;
		virtual void InitialTapeContentChanged() = 0;
};

#endif // ABSTRACTTURINGSIMUQTUI_H
