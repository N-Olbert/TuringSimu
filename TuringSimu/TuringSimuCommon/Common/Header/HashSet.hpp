#ifndef TM_HASHSET
#define TM_HASHSET
#include "ComparableHelpers.hpp"
#include "unordered_set"
#include "BaseComparable.hpp"

namespace ts_common
{
	/**
	 * \brief A simple HashSet.
	 */
	template<class T> class HashSet : public std::unordered_set<T, Hasher<T>, Comparator<T>> 
	{
		public:
			/**
			 * \brief Adopts all elements within the given vector.
			 * \param toUnion The vector to adopt its elements
			 * \return true if all values have been adopted; false if at least one value was already present 
			 */
			bool UnionWith(const std::vector<T>& toUnion) 
			{
				bool flag = true;
				for (auto& value : toUnion) 
				{
					auto result = this->insert(value);
					if (!result.second) 
					{
						flag = false;
					}
				}

				return flag;
			};

			/**
			 * \brief Returns a copy of the current instance as vector.
			 * \return A copy of the current instance as vector.
			 */
			std::vector<T> asVector() const
			{
				std::vector<T> toReturn;
				for (auto &value : *(this)) 
				{
					toReturn.push_back(value);
				}

				return toReturn;
			}

			/**
			 * \brief Gets a value indicating whether the current set contains the requested value.
			 * \param item The item to check.
			 * \return True if item was found; false otherwise.
			 */
			bool Contains(const T& item) const
			{
				return this->count(item) != 0;
			}
	};

}
#endif // TM_HASHSET
