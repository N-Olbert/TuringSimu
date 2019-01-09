#include "../Header/UIExecutionDataFactory.hpp"
#include "../../Common/Header/MachineType.hpp"
#include "../Header/TuringMachineUIExecutionData.hpp"
#include "../Header/NonDeterministicTuringMachineUIExecutionData.hpp"

using namespace ts_common;
using namespace ts_ui;

std::unique_ptr<MachineUIExecutionData> UIExecutionDataFactory::GetUIExecutionData(AbstractMachine* machine)
{
	if(machine != nullptr)
	{
		auto machineType = machine->GetSpecificValue(SpecificMachineValue::Type);
		switch (machineType->As<MachineType>()) 
		{
			//For NEA and DEA this may change in the future.
			//Currently we convert NEA/DEAs to a turing machine during read in process, but in reality
			//they are own machine types.
			  case NEA:
			  case NTM:
				return std::make_unique<NonDeterministicTuringMachineUIExecutionData>();
			  case DTM: 		  
			  case DEA:
				return std::make_unique<TuringMachineUIExecutionData>();
		  default: ;
		}
	}

	return nullptr;
}
