#pragma once
#ifndef TS_STATE
#include "BaseComparable.hpp"
#include "StringRepresentable.hpp"
#include <string>
namespace ts_common
{
	class State : public BaseComparable<State>, public StringRepresentable 
	{
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
			const std::string& GetIdentifier() const;

			/*
			 * Destructor.
			 */
			virtual ~State() = default;
			const bool operator==(const State& other) const noexcept override;
			const bool operator!=(const State& other) const noexcept override;
			const bool operator<(const State& other) const noexcept override;
			const bool operator>(const State& other) const noexcept override;
			const size_t GetHashCode() const noexcept override;
			std::string ToString() const noexcept override;
	};
}
#define TS_STATE
#endif