#ifndef MATRIX_H
#define MATRIX_H

#include "array2D.h"
#include "operate.h"

namespace Chaf
{
	namespace cml
	{
		template<typename T, size_t M, size_t N>
		struct mat :
			public array2D<T, M, N>,
			public Stream2D<mat<T, M, N>, T, M, N>,
			public Operate2D<mat<T, M, N>, T, M, N>
		{
		public:
			using array2D::array2D;
			using array2D::reset;

			const T sum() const;
			const mat<T, M, N> hadamardProduct(const mat<T, M, N>& mat) const;
			const mat<T, M, N> normalize() const;
			const T det() const;
			const mat<T, M, N> transpose() const;
			const mat<T, M, N> inverse() const;

			static mat<T, M, N> ones() { return mat<T, M, N>(1); }
			static mat<T, M, N> zros() { return mat<T, M, N>(0); }
			static mat<T, M, M> unit()
			{
				mat<T, M, N>m(0);
				for (size_t i = 0; i < M; i++)m(i, i) = 1;
				return m;
			}
		};

		template<typename T>
		struct mat<T, 1, 1> :public array2D<T, 1, 1>
		{
		public:
			const T det() const
			{
				return (*this)(0, 0);
			}
		};

		template<size_t M, size_t N>
		using matf = mat<float, M, N>;

		using matf2 = matf<2, 2>;
		using matf3 = matf<3, 3>;
		using matf4 = matf<4, 4>;
		using matf34 = matf<3, 4>;
		using matf43 = matf<4, 3>;


		template<size_t M, size_t N>
		using matu = mat<uint8_t, M, N>;

		using matu2 = matu<2, 2>;
		using matu3 = matu<3, 3>;
		using matu4 = matu<4, 4>;
		using matu3x4 = matu<3, 4>;
		using matu4x3 = matu<4, 3>;

		template<size_t M, size_t N>
		using mati = mat<int, M, N>;

		using mati2 = mati<2, 2>;
		using mati3 = mati<3, 3>;
		using mati4 = mati<4, 4>;
		using mati3x4 = mati<3, 4>;
		using mati4x3 = mati<4, 3>;


		template<size_t M, size_t N>
		using matb = mat<bool, M, N>;

		using matb2 = matb<2, 2>;
		using matb3 = matb<3, 3>;
		using matb4 = matb<4, 4>;
		using matb3x4 = matb<3, 4>;
		using matb4x3 = matb<4, 3>;
	}
}
#include "detail/matrix.inl"
#endif // !MATRIX_H
