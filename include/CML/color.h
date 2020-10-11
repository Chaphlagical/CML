#ifndef COLOR_H
#define COLOR_H

#include "array1D.h"
#include "vec.h"

namespace Chaf
{
	namespace cml
	{
		template<typename T, size_t N>
		struct color :
			public array1D<T, N>,
			public Operate1D<color<T, N>, T, N>,
			public Stream1D<vec<T, N>, T, N>
		{
		public:
			using array1D::array1D;
			using array1D::cast;

			const color<T, N>& operator+=(const color<T, N>& v);
			const color<T, N>& operator-=(const color<T, N>& v);
			const color<T, N>& operator*=(const T& t);
			const color<T, N>& operator/=(const T& t);
			const color<T, N> operator+();
			const color<T, N> operator-();
		};
		template<typename T>
		using rgb = color<T, 3>;

		using rgbi = rgb<int>;
		using rgbf = rgb<float>;
		using rgbu = rgb<unsigned>;

		template<typename T>
		using rgba = color<T, 4>;

		using rgbai = rgba<int>;
		using rgbaf = rgba<float>;
		using rgbau = rgba<unsigned>;
	}
}
#include "detail/color.inl"
#endif // !COLOR_H
