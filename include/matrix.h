#ifndef MATRIX_H
#define MATRIX_H

#include "array2D.h"

namespace Chaf
{
	template<typename T, size_t M, size_t N>
	struct matrix : array2D<T, M, N>
	{
	public:
		using array2D::array2D;
		using array2D::reset;

		inline const T sum()
		{
			T res = 0;
			for (size_t i = 0; i < M; i++)
				for (size_t j = 0; j < N; j++)
					res += (*this)(i, j);
			return res;
		}

		inline const matrix<T, M, N> hadamardProduct(const matrix<T, M, N>& mat);
		inline const matrix<T, M, N> normalize() { return (*this) / sum(); }
		inline const T det() noexcept;
		inline const matrix<T, M, N> transpose();
		inline const matrix<T, M, N> inverse();

		inline static const matrix<T, M, N> unit()
		{
			CHAF_ASSERT(M == N, "only support square matrix!");
			matrix<T, M, N> res;
			for (size_t i = 0; i < N; i++)res(i, i) = 1;
			return res;
		}
	};

	template<typename T>
	struct matrix<T, 0, 0> : array2D<T, 0, 0>
	{
	public:
		inline const T det() noexcept;
	};

	template<size_t M, size_t N>
	using matrixf = matrix<float, M, N>;

	using matrixf2 = matrixf<2, 2>;
	using matrixf3 = matrixf<3, 3>;
	using matrixf4 = matrixf<4, 4>;
	using matrixf34 = matrixf<3, 4>;
	using matrixf43 = matrixf<4, 3>;


	template<size_t M, size_t N>
	using matrixu = matrix<uint8_t, M, N>;

	using matrixu2 = matrixu<2, 2>;
	using matrixu3 = matrixu<3, 3>;
	using matrixu4 = matrixu<4, 4>;
	using matrixu34 = matrixu<3, 4>;
	using matrixu43 = matrixu<4, 3>;

	template<size_t M, size_t N>
	using matrixi = matrix<int, M, N>;

	using matrixi2 = matrixi<2, 2>;
	using matrixi3 = matrixi<3, 3>;
	using matrixi4 = matrixi<4, 4>;
	using matrixi34 = matrixi<3, 4>;
	using matrixi43 = matrixi<4, 3>;


	template<size_t M, size_t N>
	using matrixb = matrix<bool, M, N>;

	using matrixb2 = matrixb<2, 2>;
	using matrixb3 = matrixb<3, 3>;
	using matrixb4 = matrixb<4, 4>;
	using matrixb34 = matrixb<3, 4>;
	using matrixb43 = matrixb<4, 3>;
}

#include "./detail/matrix.inl"

#endif // !MATRIX_H
