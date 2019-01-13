#include "TuringSimuQtUI.hpp"
#include <QThread>
#include <QTimer>
#include <QDebug>

TuringSimuQtUI::TuringSimuQtUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	SetTapeHeaderVisibleAt(static_cast<size_t>(2));
}

////Methods

std::string TuringSimuQtUI::GetFilePath()
{

	std::string result;
	if (EnsureGUIThreadCall([this, &result] { result = GetFilePath(); })) return result;
	return this->ui.PathTextBox->text().toStdString();
}

size_t TuringSimuQtUI::GetAmountOfDisplayedTapeLetters()
{
	size_t result = 0;
	if (EnsureGUIThreadCall([this, &result] { result = GetAmountOfDisplayedTapeLetters(); })) return result;

	auto container = this->ui.TapeLetterContainer;
	return container->count();
}

void TuringSimuQtUI::DisplayTapeSequence(const std::string& toDisplay)
{
	if(EnsureGUIThreadCall([this, &toDisplay] { DisplayTapeSequence(toDisplay); })) return;

	const auto maxLength = GetAmountOfDisplayedTapeLetters();
	const auto container = this->ui.TapeLetterContainer;
	for(size_t i = 0; i < toDisplay.size() && i < maxLength; i++)
	{
		qobject_cast<TapeLetter*>(container->itemAt(i)->widget())->DisplayLetter(toDisplay[i]);
	}
}

void TuringSimuQtUI::SetTapeHeaderVisibleAt(size_t pos)
{
	if(EnsureGUIThreadCall([this, pos] { SetTapeHeaderVisibleAt(pos); })) return;

	const auto container = this->ui.TapeHeaderContainer;
	const auto childs = container->count();
	for (auto i = 0; i < childs; i++)
	{ 
		auto item = qobject_cast<TapeLetter*>(container->itemAt(i)->widget());
		item->DisplayLetter(static_cast<size_t>(i) == pos ? QString::fromUtf8("\xE2\x96\xBC") : QString{' '});
	}
}

std::string TuringSimuQtUI::GetInitialTapeContent()
{
	std::string result;
	if (EnsureGUIThreadCall([this, &result] { result = GetInitialTapeContent(); })) return result;
	return this->ui.InitialTapeContentInput->text().toStdString();
}

void TuringSimuQtUI::DisplayCurrentState(const std::string& currentState)
{
	if (EnsureGUIThreadCall([this, &currentState] { DisplayCurrentState(currentState); })) return;
	this->ui.StateLabel->setText(QString::fromStdString(currentState));
}

void TuringSimuQtUI::DisplayCurrentChar(char toDisplay)
{
	if (EnsureGUIThreadCall([this, toDisplay] { DisplayCurrentChar(toDisplay); })) return;
	this->ui.CharLabel->setText(QString{ toDisplay });
}

void TuringSimuQtUI::SetEnableMachineExecutionControls(bool enable)
{
	if (EnsureGUIThreadCall([this, enable] { SetEnableMachineExecutionControls(enable); })) return;
	this->ui.MachineExecutionGroupBox->setEnabled(enable);
}

void TuringSimuQtUI::SetEnableRunButton(bool enable)
{
	if (EnsureGUIThreadCall([this, enable] { SetEnableRunButton(enable); })) return;
	this->ui.RunButton->setEnabled(enable);
}

void TuringSimuQtUI::SetEnableResetButton(bool enable)
{
	if (EnsureGUIThreadCall([this, enable] { SetEnableResetButton(enable); })) return;
	this->ui.ResetButton->setEnabled(enable);
}

void TuringSimuQtUI::SetEnableStepButton(bool enable)
{
	if (EnsureGUIThreadCall([this, enable] { SetEnableStepButton(enable); })) return;
	this->ui.StepButton->setEnabled(enable);
}

void TuringSimuQtUI::SetEnableInitialTapeContentInput(bool enable)
{
	if (EnsureGUIThreadCall([this, enable] { SetEnableInitialTapeContentInput(enable); })) return;
	this->ui.InitialTapeContentInput->setEnabled(enable);
}


// Autobindings (and signal forwarders)

void TuringSimuQtUI::on_LoadFileButton_clicked()
{
	emit LoadFileButtonClicked(); // raise signal
}

void TuringSimuQtUI::on_RunButton_clicked()
{
	emit RunButtonClicked();
}

void TuringSimuQtUI::on_StepButton_clicked()
{
	emit StepButtonClicked();
}

void TuringSimuQtUI::on_ResetButton_clicked()
{
	emit ResetButtonClicked();
}

void TuringSimuQtUI::on_InitialTapeContentInput_textChanged(const QString& input)
{
	emit InitialTapeContentChanged();
}

bool TuringSimuQtUI::EnsureGUIThreadCall(const std::function<void()>& lambda)
{
	if (QThread::currentThread() != this->thread())
	{
		QMetaObject::invokeMethod(this, lambda, Qt::BlockingQueuedConnection);
		return true;
	}

	return false;
}
