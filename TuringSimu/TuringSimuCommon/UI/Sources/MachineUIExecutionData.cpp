#include "../Header/MachineUIExecutionData.hpp"
using namespace ts_ui;

MachineUIExecutionData::MachineUIExecutionData() noexcept
{
	this->logFileStream = nullptr;
}

inline MachineUIExecutionData::~MachineUIExecutionData()
{
	if (this->logFileStream != nullptr)
	{
		this->logFileStream->close();
	}
}
