#pragma once
#ifndef CPP_BASECOMPARABLEHASHER
#define CPP_BASECOMPARABLEHASHER
#include "BaseComparable.hpp"
#include <functional>
#include <vector>

namespace ts_common
{
	/**
	 * \brief A template class which defines an ()-operator.
	 *		  The ()-operator of this class may be used to retrieve the hash code of the given instance.
	 *		  NOTE: This is nothing more than a wrapper around the \code [GetHashCode()]-method
	 *		  of the \class BaseComparable-class
	 * \tparam T The type of the objects of which the hash code should be returned.
	 *			 Must be a derivation of BaseComparable<T>
	 */
	template<class T> class Hasher {
	public:
		/**
		 * \brief Returns the hash code of the given object.
		 * \param obj The object to determine its hash code.
		 * \return The hash code of the object.
		 */
		size_t operator()(const BaseComparable<T>& obj) const {
			return obj.GetHashCode();
		};

		/**
		 * \brief Returns the hash code of the given object.
		 * \param obj The object to determine its hash code.
		 * \return The hash code of the object.
		 */
		size_t operator()(const char& obj) const {
			return std::hash<char>()(obj);
		}
	};

	/**
	 * \brief A template class which defines an ()-operator.
	 *		  The ()-operator may be used to retrieve a value which indicates whether the given
	 *		  objects are equal or not.
	 * \tparam T The type of the objects of which the equality should be determined.
	 */
	template<class T> class Comparator {
	public:
		/**
		 * \brief Returns a value indicating whether the given objects are equal or not.
		 * \param obj1 The first object to check.
		 * \param obj2 The second object to check.
		 * \return \code true if both objects are equal; \code false otherwise.
		 */
		bool operator()(const T& obj1, const T& obj2) const {
			return obj1 == obj2;
		}
	};

	
}
#endif
