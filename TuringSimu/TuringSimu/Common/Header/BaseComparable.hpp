#pragma once
#ifndef TM_BASECOMPARABLE
#define TM_BASECOMPARABLE
template<class T> class BaseComparable
{
	public:
		virtual ~BaseComparable() = default;
		virtual bool operator == (const T& other) const noexcept = 0;
	    virtual bool operator != (const T& other) const noexcept = 0;
		virtual bool operator < (const T& other) const noexcept = 0;
		virtual bool operator > (const T& other) const noexcept = 0;
		virtual size_t GetHashCode() const noexcept = 0;
};
#endif 
