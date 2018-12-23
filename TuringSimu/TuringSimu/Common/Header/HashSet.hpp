#ifndef TM_HASHSET
#define TM_HASHSET
#include "ComparableHelpers.hpp"
#include "unordered_set"
#include "BaseComparable.hpp"

namespace ts_common
{
	template<class T> class HashSet : public std::unordered_set<T, Hasher<T>, Comparator<T>> {
	public:
		bool UnionWith(std::vector<T> toUnion) {
			bool flag = true;
			for (auto value : toUnion) {
				auto result = this->insert(value);
				if (!result.second) {
					flag = false;
				}
			}
			return flag;
		};
		std::vector<T> asVector() {
			std::vector<T> toReturn;
			for (auto &value : *(this)) {
				toReturn.push_back(value);
			}
			return toReturn;
		}
		bool Contains(T item)
		{
			return this->count(item) != 0;
		}

	};

}
#endif // TM_HASHSET
