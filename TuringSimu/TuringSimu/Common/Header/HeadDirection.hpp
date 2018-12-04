#pragma once
#ifndef TS_HEADDIRECTION
namespace ts_common
{
	/*
	 * Enumeration of possible head movement directions.
	 */
	enum HeadDirection
	{
		/*
		 * Move head left.
		 */
		Left,

		/*
		 * Move head right.
		 */
		Right,

		/**
		 * Let head stay at position.
		 */
		Stay
	};
}
#define TS_HEADDIRECTION
#endif