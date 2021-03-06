#ifndef TMS_MACHINEUIEXECUTIONDATA
#define TMS_MACHINEUIEXECUTIONDATA
#include <string>
#include <fstream>
#include "../../Common/Header/HeadDirection.hpp"
#include "../../Common/Header/AbstractMachine.hpp"

using namespace ts_common;

namespace ts_ui
{
	/**
	 * \brief A class which handles events of an observed machine to emulate the visual
	 *  execution state of the observed machine
	 */
	class MachineUIExecutionData
	{
		public:
			virtual ~MachineUIExecutionData() = default;
			virtual void HandleInitialized(AbstractMachine* machine) = 0;
			virtual void HandleTapeWritten(char written) = 0;
			virtual void HandleHeadMoved(HeadDirection direction) = 0;
			virtual void HandleStateChanged(const State& newState) = 0;
	};
}
#endif // TMS_MACHINEUIEXECUTIONDATA
