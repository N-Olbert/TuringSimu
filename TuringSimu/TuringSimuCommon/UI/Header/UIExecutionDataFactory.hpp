#ifndef TMS_UIEXECUTIONDATAFACTORY
#define TMS_UIEXECUTIONDATAFACTORY
#include "MachineUIExecutionData.hpp"
#include "../../Common/Header/AbstractMachine.hpp"
namespace ts_ui
{
	class UIExecutionDataFactory
	{
		public:
			static std::unique_ptr<MachineUIExecutionData> GetUIExecutionData(AbstractMachine* machine);
	};
}
#endif // TMS_UIEXECUTIONDATAFACTORY
