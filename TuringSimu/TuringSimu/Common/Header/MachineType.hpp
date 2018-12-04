#pragma once
#ifndef TS_MACHINETYPE
namespace ts_common
{
	/*
	 * Enumeration of possible machine types.
	 */
	enum MachineType
	{
		/*
		 * Deterministic turing machine.
		 */
		DTM,

		/*
		 * Non-deterministic turing machine
		 */
		NTM
	};
}
#define TS_MACHINETYPE
#endif