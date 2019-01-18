#pragma once
#ifndef TM_BASECOMPARABLE
#define TM_BASECOMPARABLE
#include <cstddef>
namespace ts_common
{
	/**
	 * \brief An abstract class which defines operators for comparisons.
	 * \tparam T The concrete type of the implementing class. 
	 */
	template<class T> class BaseComparable
	{
		public:
			virtual ~BaseComparable() = default;
			const virtual bool operator == (const T& other) const noexcept = 0;
		    const virtual bool operator != (const T& other) const noexcept = 0;
			const virtual bool operator < (const T& other) const noexcept = 0;
			const virtual bool operator > (const T& other) const noexcept = 0;

			/**
			 * \brief Retrieves the hash code of the current object.
			 */
			const virtual size_t GetHashCode() const noexcept = 0;
	};
}
#endif 
