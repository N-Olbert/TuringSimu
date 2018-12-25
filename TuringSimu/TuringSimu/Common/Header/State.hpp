#pragma once
#include "BaseComparable.hpp"
#ifndef TS_STATE
#include<string>
namespace ts_common
{
	class State : public BaseComparable<State> {
	private:
		//The identifier
		std::string identifier;

	public:
		State() = default;
		State(std::string identifier);


		/**
		 * \brief Returns the identifier of the state.
		 * \return The identifier of the state.
		 */
		std::string& GetIdentifier();

		/*
		 * Destructor.
		 */
		virtual ~State() = default;
		bool operator==(const State& other) const noexcept override;
		bool operator!=(const State& other) const noexcept override;
		bool operator<(const State& other) const noexcept override;
		bool operator>(const State& other) const noexcept override;
		size_t GetHashCode() const noexcept override;
	};
}
#define TS_STATE
#endif