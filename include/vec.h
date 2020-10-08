#ifndef VEC_H
#define VEC_H

#include "operate.h"
#include "array1D.h"

namespace Chaf
{
	namespace cml
	{
		template<typename T, const size_t N>
		struct vec :
			public array1D<T, N>,
			public Operate1D<vec<T, N>, T, N>,
			public Stream1D<vec<T, N>, T, N>
		{
		public:
			using array1D::array1D;
			using array1D::cast;
			vec(const array1D& arr) : array1D(arr) {}

			const T dot(const vec<T, N>& v) const;
			const vec<T, 3> cross(const vec<T, 3>& v) const;
			const T cross(const vec<T, 2>& v) const;
			const vec<T, N> hadamardProduct(const vec<T, N>& v) const;
			const T norm() const;
			const T norm2() const;
			const vec<T, N> normalize() const;
			
			const bool isParallel(const vec<T, N>& v) const;
			const bool isVertical(const vec<T, N>& v) const;

			const vec<T, N>& operator+=(const vec<T, N>& v);
			const vec<T, N>& operator-=(const vec<T, N>& v);
			const vec<T, N>& operator*=(const T& t);
			const vec<T, N>& operator/=(const T& t);
			const bool operator==(const vec<T, N>& v);
			const bool operator!=(const vec<T, N>& v);
			const vec<T, N> operator+();
			const vec<T, N> operator-();

			static const vec<T, N> ones() { return vec<T, N>(1); }
			static const vec<T, N> zeros() { return vec<T, N>(0); }
		};

		template<size_t N>
		using vecf = vec<float, N>;
		template<size_t N>
		using vecu = vec<uint8_t, N>;
		template<size_t N>
		using veci = vec<int, N>;
		template<size_t N>
		using vecb = vec<bool, N>;

		template<typename T>
		using vec2 = vec<T, 2>;
		template<typename T>
		using vec3 = vec<T, 3>;
		template<typename T>
		using vec4 = vec<T, 4>;

		using vecf2 = vecf<2>;
		using vecf3 = vecf<3>;
		using vecf4 = vecf<4>;

		using vecu2 = vecu<2>;

		using veci2 = vecf<2>;
		using veci3 = vecf<3>;
		using veci4 = vecf<4>;

		using vecb2 = vecf<2>;
		using vecb3 = vecf<3>;
		using vecb4 = vecf<4>;
	}
}

#include "detail/vec.inl"

#endif // !VEC_H