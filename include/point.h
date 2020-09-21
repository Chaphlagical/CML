#pragma
#include "array1D.h"

namespace Chaf
{
	template<typename T, const size_t N>
	struct point : public array1D<T, N>
	{
	public:
		using array1D::array1D;

		inline const T distance2(const point<T, N>& p);
		inline const T distance(const point<T, N>& p);
	};

	template<size_t N>
	using pointf = point<float, N>;
	template<size_t N>
	using pointu = point<uint8_t, N>;
	template<size_t N>
	using pointi = point<int, N>;
	template<size_t N>
	using pointb = point<bool, N>;

	using pointf2 = pointf<2>;
	using pointf3 = pointf<3>;
	using pointf4 = pointf<4>;

	using pointu2 = pointu<2>;

	using pointi2 = pointf<2>;
	using pointi3 = pointf<3>;
	using pointi4 = pointf<4>;

	using pointb2 = pointf<2>;
	using pointb3 = pointf<3>;
	using pointb4 = pointf<4>;
}

#include "./detail/point.inl"