#ifndef ARRAY1D_H
#define ARRAY1D_H

#include <array>
#include "base.h"
#include <initializer_list>

template<typename T, size_t N>
struct array1D
{
public:
	array1D() { reset(); };
	array1D(std::array<T, N> arr) :data(arr) {}
	array1D(std::initializer_list<T> il)
	{
		CHAF_ASSERT(il.size() == N, "Too many or too few parameters!");
		auto& p = data.begin();
		for (auto ptr = il.begin(); ptr != il.end(); ptr++)
		{
			*p = *ptr;
			p++;
		}
	}

	inline void reset() { for (auto& x : data)x = ZERO<T>; }

	template<typename F>
	inline F cast() { return *(static_cast<F*>(this)); }

	virtual inline const T& operator[](const size_t index) const { return data[index]; }
	virtual inline T& operator[](const size_t index) { return data[index]; }

private:
	std::array<T, N> data;
};

#endif // !ARRAY1D_H
