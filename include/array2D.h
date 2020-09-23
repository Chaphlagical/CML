#ifndef ARRAY2D_H
#define ARRAY2D_H

#include <array>
#include "base.h"
#include <initializer_list>

namespace Chaf
{
	template<typename T, size_t N, size_t M>
	struct array2D
	{
	public:
		array2D() { reset(); };
		array2D(std::array<std::array<T, M>, N> arr) :data(arr) {}
		array2D(std::initializer_list<std::initializer_list<T>> il)
		{
			CHAF_ASSERT(il.size() == N, "Too many or too few parameters!");
			auto& p = data.begin();
			for (auto ptr = il.begin(); ptr != il.end(); ptr++)
			{
				CHAF_ASSERT(ptr->size() == M, "Too many or too few parameters!");
				auto& subp = p->begin();
				for (auto ptr_ = ptr->begin(); ptr_ != ptr->end(); ptr_++)
				{
					*subp = *ptr_;
					subp++;
				}
				p++;
			}
		}

		inline void reset()
		{
			for (auto& x : data)
				for (auto& y : x)
					y = ZERO<T>;
		}

		template<typename F>
		inline const F cast() const { return *(static_cast<const F*>(this)); }

		inline const T& operator()(const size_t m, const size_t n)const { return data[m][n]; }
		inline T& operator()(const size_t m, const size_t n) { return data[m][n]; }

	private:
		std::array<std::array<T, M>, N> data;
	};
}

#endif // !ARRAY1D_H
