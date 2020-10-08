#ifndef ARRAY1D_H
#define ARRAY1D_H

#include <array>
#include <iostream>
#include "operate.h"
#include "base.h"
#include <initializer_list>

namespace Chaf
{
	template<typename T, size_t N>
	struct array1D
	{
	public:
		array1D() { reset(); };
		array1D(std::array<T, N> arr) :data(arr) {}
		array1D(std::initializer_list<T> il)
		{
			CHAF_ASSERT(il.size() == N, "incorrect number of parameters!");
			auto& p = data.begin();
			for (auto ptr = il.begin(); ptr != il.end(); ptr++)
			{
				*p = *ptr;
				p++;
			}
		}
		array1D(const T& val) :data()
		{
			for (size_t i = 0; i < N; i++)data[i] = val;
		}
		virtual ~array1D() = default;
		inline void reset() { for (auto& x : data)x = ZERO<T>; }
		template<typename F>
		inline const F& cast() const { return (const_cast<F&>(*(static_cast<const F*>(this)))); }
		template<typename F>
		inline F& cast() { return (const_cast<F&>(*(static_cast<F*>(this)))); }
		inline const T& operator[](const size_t index) const { return data[index]; }
		inline T& operator[](const size_t index) { return data[index]; }
	private:
		std::array<T, N> data;
	};	
}
#endif // !ARRAY1D_H
