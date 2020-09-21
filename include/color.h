#pragma
#include "array1D.h"

namespace Chaf
{
	template<typename T, size_t N>
	struct color : public array1D<T, N>
	{
	public:
		using array1D::array1D;
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

#include "./detail/color.inl"