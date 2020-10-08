namespace Chaf
{
	namespace cml
	{
		template<typename T, size_t M, size_t N>
		const T mat<T, M, N>::sum() const
		{
			T res = 0;
			for (size_t i = 0; i < M; i++)
				for (size_t j = 0; j < N; j++)
					res += (*this)(i, j);
			return res;
		}

		template<typename T, size_t M, size_t N>
		const mat<T, M, N> mat<T, M, N>::hadamardProduct(const mat<T, M, N>& m) const
		{
			mat<T, M, N> _m;
			for (size_t i = 0; i < M; i++)
				for (size_t j = 0; i < N; j++)
					_m(i, j) = (*this)(i, j) * m(i, j);
			return _m;
		}

		template<typename T, size_t M, size_t N>
		const mat<T, M, N> mat<T, M, N>::normalize() const
		{ 
			return (*this) / sum();
		}

		template<typename T, size_t M, size_t N>
		const T mat<T, M, N>::det() const
		{
			static_assert(M == N && M > 1, "row should be the same as col!");
			if (N == 2)return (*this)(0, 0) * (*this)(1, 1) - (*this)(0, 1) * (*this)(1, 0);
			else
			{
				int flag = 1;
				T res = 0;
				mat<T, M - 1, N - 1> submatrix;
				for (size_t i = 0; i < N; i++)
				{
					for (size_t j = 0; j < M - 1; j++)
						for (size_t k = 0; k < N - 1; k++)
							submatrix(j, k) = (*this)(j + 1, (k < i ? k : k + 1));
					res += submatrix.det() * flag * (*this)(0, i);
					flag *= -1;
				}
				return res;
			}
		}

		template<typename T, size_t M, size_t N>
		const mat<T, M, N> mat<T, M, N>::transpose() const
		{
			mat<T, N, M> res;
			for (size_t i = 0; i < N; i++)
				for (size_t j = 0; j < M; j++)
					res(i, j) = (*this)(j, i);
			return res;
		}

		template<typename T, size_t M, size_t N>
		const mat<T, M, N> mat<T, M, N>::inverse() const
		{
			static_assert(M == N, "It's not a square matrix!");
			mat<T, M, N> res;
			if (M == 2)
			{
				res = { {(*this)(1,1),-(*this)(0,1)},{-(*this)(1,0),(*this)(0,0)} };
				return res / (det());
			}
			else
			{
				mat<T, M, N> adjmat;
				mat<T, M - 1, N - 1> help;
				for (size_t i = 0; i < M; i++)
					for (size_t j = 0; j < N; j++)
					{
						for (size_t x = 0; x < M - 1; x++)
							for (size_t y = 0; y < N - 1; y++)
							{
								help(x, y) = (*this)((x >= i ? x + 1 : x), (y >= j ? y + 1 : y));
							}
						adjmat(j, i) = static_cast<T>(std::pow(-1, i + j)) * help.det();
					}
				res = adjmat / (det());
			}
			return res;
		}
	}
}

// opertor override

template<typename T, size_t M, size_t N, size_t K>
const Chaf::cml::mat<T, M, N> operator*(const Chaf::cml::mat<T, M, N>& m1, const Chaf::cml::mat<T, N, K>& m2)
{
	Chaf::cml::mat<T, M, K> m;
	for (size_t i = 0; i < M; i++)
		for (size_t k = 0; k < K; k++)
			for (size_t j = 0; j < N; j++)
				m(i, k) += m1(i, j) * m2(j, k);
	return m;
}

