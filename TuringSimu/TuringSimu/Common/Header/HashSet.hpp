#ifndef TM_HASHSET
#define TM_HASHSET
#include "ComparableHelpers.hpp"
#include "unordered_set"

namespace ts_common
{
	template<class T> class HashSet : public std::unordered_set<T, Hasher<T>, Comparator<T>>
	{
	};
}
#endif // TM_HASHSET
