#pragma once
#ifndef TSM_MACHINEEXECUTIONCONTROLLERFACTORY
#define TSM_MACHINEEXECUTIONCONTROLLERFACTORY
#include "../Header/MachineExecutionController.hpp"
#include "../../../TuringSimuCommon/Common/Header/MachineType.hpp"
#include "../Header/TuringMachineConsoleOutputController.hpp"
#include "../Header/TuringMachineLogfileOutputController.hpp"
namespace ts_ui
{
	enum class UI { Console, LogFile, QtGui };
}

namespace ts_ui_business
{
	using namespace ts_ui;
	class MachineExecutionControllerFactory
	{
		public:
			static std::unique_ptr<MachineExecutionController> GetExecutionController(UI ui, AbstractMachine* machine)
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
									break;
								case UI::QtGui: break;
							}

						default:
							break;
					}
				}

				return nullptr;
			}
	};
}
#endif // TSM_MACHINEEXECUTIONCONTROLLERFACTORY
