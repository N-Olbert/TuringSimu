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

    public:
        explicit TuringSimuQtPresenter(AbstractTuringSimuQtForm* view, QObject *parent = nullptr);
		void DisplayTapeSequence(std::string toDisplay);
		void SetTapeHeaderVisibleAt(size_t pos);
		std::string GetInitialTapeContent();
		void DisplayCurrentState(const std::string& currentState);
		void DisplayCurrentChar(char toDisplay);

	private slots:
	        void HandleLoadFileButtonClicked();
			void HandleRunButtonClicked();
			void HandleStepButtonClicked();
			void HandleResetButtonClicked();
			void HandleInitialTapeContentChanged();
};
#endif // TURINGSIMUQTPRESENTER_H
