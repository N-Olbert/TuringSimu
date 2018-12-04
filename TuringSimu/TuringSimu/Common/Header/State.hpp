#pragma once
#ifndef TS_STATE
#include<string>
namespace ts_common
{
	class State
	{
		private:
		//The identifier
		std::string identifier;

		public:
		/**
		 * \brief Returns the identifier of the state.
		 * \return The identifier of the state.
		 */
		std::string GetIdentifier();

		/*
		 * Destructor.
		 */
		virtual ~State(){};
	};
}
#define TS_STATE
#endif