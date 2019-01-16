#pragma once
#ifndef TSM_MACHINEEXECUTIONCONTROLLERFACTORY
#define TSM_MACHINEEXECUTIONCONTROLLERFACTORY
#include "../Header/MachineExecutionController.hpp"
#include "../../../TuringSimuCommon/Common/Header/MachineType.hpp"

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
			static std::unique_ptr<MachineExecutionController> GetExecutionController(UI ui, AbstractMachine* machine);
	};
}
#endif // TSM_MACHINEEXECUTIONCONTROLLERFACTORY
