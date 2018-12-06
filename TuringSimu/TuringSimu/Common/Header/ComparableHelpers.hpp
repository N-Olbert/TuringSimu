#pragma once
#ifndef CPP_BASECOMPARABLEHASHER
#define CPP_BASECOMPARABLEHASHER
template<class T>struct Hasher
{
  size_t operator()(const BaseComparable<T>& obj) const
  {
      return obj.GetHashCode();
  }
};
 
template<class T> struct Comparator
{
  bool operator()(const T& obj1, const T& obj2) const
  {
    return obj1 == obj2;
  }
};
#endif
