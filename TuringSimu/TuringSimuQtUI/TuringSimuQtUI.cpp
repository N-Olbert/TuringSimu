#include "TuringSimuQtUI.hpp"
#include <QThread>
#include <QStandardItemModel>
#include <QDebug>
#include "../TuringSimuCommon/Common/Header/BaseTransition.hpp"

TuringSimuQtUI::TuringSimuQtUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	SetTapeHeaderVisibleAt(static_cast<size_t>(2));
}

////Methods

TuringSimuQtUI::~TuringSimuQtUI()
{
	QMainWindow::~QMainWindow();
}

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

void TuringSimuQtUI::DisplayCurrentStep(size_t step)
{
	if (EnsureGUIThreadCall([this, step] { DisplayCurrentStep(step); })) return;
	this->ui.StepsLabel->setText(QString::fromStdString(std::to_string(step)));
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

void TuringSimuQtUI::closeEvent(QCloseEvent * event)
{
	//Nice and fancy dead lock avoidance - exactly the way it should be done :)
	//Should be reviewed, but no time atm. Anyways it also isn't that critical, because this is (in thoery) a singleton object and
	//closing it means ending the program. 

	//Problem is the following: If an execution is still in progess and the user clicks the close button the default behaviour of qt is 
	//to stop the event processing and then exit the app.
	//This is kind of a problem if we still have a non-finished machine execution. In this case we need to await the machine execution in 
	//the destructor ~TuringSimuQtPresenter() (because otherwise probably some pointers become invalid). Now the still executing machine
	//thread may reqeust a synchronus invoke within the GUI thread, for example to update the displayed tape.
	//The GUI thread doesnt handle any events anymore and so we have a deadlock...
	//Calling a normal exit solves this, as it isnt calling destructors.

	exit(0);
}

void TuringSimuQtUI::FillTransitionTable(const std::vector<std::string>& states,
										 const std::vector<std::string>& alphabet,
										 const std::vector<const BaseTransition*> transitions)
{
	
	auto table = this->ui.TransitionTable;
	table->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->tableModel.setColumnCount(alphabet.size());
	this->tableModel.setRowCount(states.size());

	this->charMap.clear();
	this->stateMap.clear();
	for (size_t i = 0; i < alphabet.size(); ++i)
	{
		this->tableModel.setHeaderData(i, Qt::Horizontal, QObject::tr(alphabet.at(i).c_str()));
		this->charMap[alphabet.at(i)] = i;
	}

	for (size_t i = 0; i < states.size(); ++i)
	{
		this->tableModel.setHeaderData(i, Qt::Vertical, QObject::tr(states.at(i).c_str()));
		this->stateMap[states.at(i)] = i;
	}

	for (auto transition : transitions)
	{
		auto index = this->tableModel.index(this->stateMap.at(transition->GetCurrentState().ToString()), this->charMap.at(transition->GetToRead()));
		auto str = transition->ToString();
		this->tableModel.setData(index, str.c_str());
	}

	table->setModel(&this->tableModel);
}

void TuringSimuQtUI::HighlightTransition(const BaseTransition& transition)
{
	if (EnsureGUIThreadCall([this, &transition] { HighlightTransition(transition); })) return;
	const QColor hlClr = Qt::red; // highlight color to set
	const QColor txtClr = Qt::white; // highlighted text color to set

	QPalette p = palette();
	p.setColor(QPalette::Highlight, hlClr);
	p.setColor(QPalette::HighlightedText, txtClr);
	this->ui.TransitionTable->setPalette(p);
	auto index = this->tableModel.index(this->stateMap.at(transition.GetCurrentState().ToString()), this->charMap.at(transition.GetToRead()));
	this->ui.TransitionTable->selectionModel()->clearSelection();
	this->ui.TransitionTable->selectionModel()->select(index, QItemSelectionModel::Select);
	this->ui.TransitionTable->scrollTo(index);
}

void TuringSimuQtUI::DisplayMachineInfo(const std::string& toDisplay)
{
	this->ui.MachineInfoLabel->clear();
	this->ui.MachineInfoLabel->append(QString::fromStdString(toDisplay));
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
		if (!QThread::currentThread()->signalsBlocked())
		{
			QMetaObject::invokeMethod(this, lambda, Qt::BlockingQueuedConnection);
		}
		else
		{
			qDebug() << "BAD - Signals blocked - BAD - Undefined things may happen!!!";
		}

		return true;
	}

	return false;
}
