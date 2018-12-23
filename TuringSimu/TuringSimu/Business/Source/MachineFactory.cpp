#include "../Header/TuringMachine.hpp"
#include "../Header/MachineFactory.hpp"
#include "../../IO/Header/DiskIO.hpp"
using namespace ts_business;
using namespace ts_common;

std::unique_ptr<AbstractMachine> MachineFactory::CreateMachineFromFile(std::string& path,
                                                                       AbstractMachineUserinterface* observingUI)
{
	auto definition = ts_io::DiskIO::GetTuringMachineDefinitionFromFile(path);
	if(IsValidMachineDefinition(definition))
	{
		auto result = std::unique_ptr<AbstractMachine>(new TuringMachine{observingUI, definition});
		return result;
	}

	return std::unique_ptr<AbstractMachine>(nullptr);
}

bool MachineFactory::IsValidMachineDefinition(TuringMachineDefinition & definition)
{
	//TODO
	//AbstractMachineUserinterface::NotifyInvalidMachineDefinition(observingUI, std::string);
	return true;
}
