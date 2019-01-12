#include "TuringSimuQtUI.hpp"

TuringSimuQtUI::TuringSimuQtUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

////Methods

std::string TuringSimuQtUI::GetPathTextBoxInput()
{
	return this->ui.PathTextBox->text().toStdString();
}

// Autobindings (and signal forwarders)

void TuringSimuQtUI::on_ReadInFileButton_clicked()
{
	emit ReadInFileButtonClicked(); // raise signal
}
