#include "../../../TuringSimuCommon/UI/Header/MachineExecutionControllerFactory.hpp"
#include "../../Business/Header/TuringMachineConsoleOutputController.hpp"
#include "../../Business/Header/TuringMachineLogfileOutputController.hpp"
using namespace ts_ui_business;

////Implementation of MachineExecutionControllerFactory::GetExecutionController (defined in common) for this lib

std::unique_ptr<MachineExecutionController> MachineExecutionControllerFactory::GetExecutionController(UI ui, AbstractMachine* machine)
{
	if (machine != nullptr)
	{
		switch (machine->GetSpecificValue(SpecificMachineValue::Type)->As<MachineType>())
		{
			case DTM:
			case NTM:
			case DEA:
			case NEA:
				switch (ui)
				{
					case UI::Console:
						return std::make_unique<TuringMachineConsoleOutputController>(machine);
					case UI::LogFile:
						return std::make_unique<TuringMachineLogfileOutputController>(machine);
					case UI::QtGui: break;
				}

			default:
				break;
		}
	}

	return nullptr;
}