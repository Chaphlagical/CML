#pragma
#include "array1D.h"

namespace Chaf
{
	template<typename T, const size_t N>
	struct vec: public array1D<T,N>
	{
	public:
		using array1D::array1D;

		inline const T dot(const vec<T, N>& v);
		inline const vec<T, N> cross(const vec<T, N>& v);
		inline const vec<T, N> hadamardProduct(const vec<T, N>& v);
		inline const T norm();
		inline const T norm2();

		inline const vec<T, N> normalize();
	};

	template<size_t N>
	using vecf = vec<float, N>;
	template<size_t N>
	using vecu = vec<uint8_t, N>;
	template<size_t N>
	using veci = vec<int, N>;
	template<size_t N>
	using vecb = vec<bool, N>;

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

#include "./detail/vec.inl"