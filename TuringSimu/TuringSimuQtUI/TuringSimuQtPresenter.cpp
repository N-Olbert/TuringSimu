#include "../../TuringSimuCommon/Common/Header/AbstractMachine.hpp"
#include "../../TuringSimu/Business/Header/MachineFactory.hpp"
#include "TuringSimuQtPresenter.hpp"


TuringSimuQtPresenter::TuringSimuQtPresenter(AbstractTuringSimuQtForm* view, QObject *parent)
    : QObject(parent), model(nullptr), view(view)
{
	const auto view_obj = dynamic_cast<QObject*>(view);
    connect(view_obj, SIGNAL(ReadInFileButtonClicked()), this, SLOT(HandleReadInFileButtonClicked()));
}

void TuringSimuQtPresenter::HandleReadInFileButtonClicked() const
{
    auto path = this->view->GetPathTextBoxInput();
    std::unique_ptr<AbstractMachine> machine;
    machine = ts_business::MachineFactory::CreateMachineFromFile(MachineType::DTM, path);
}
