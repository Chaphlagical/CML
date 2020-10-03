template<typename T, size_t M, size_t N>
inline constexpr Chaf::matrix<T, M, N> operator+(const Chaf::matrix<T, M, N>& mat1, const Chaf::matrix<T, M, N>& mat2)
{
	Chaf::matrix<T, M, N> res;

	for (size_t i = 0; i < M; i++)
		for (size_t j = 0; j < N; j++)
			res(i, j) = mat1(i, j) + mat2(i, j);
	return res;
}

template<typename T, size_t M, size_t N>
inline constexpr Chaf::matrix<T, M, N> operator-(const Chaf::matrix<T, M, N>& mat1, const Chaf::matrix<T, M, N>& mat2)
{
	Chaf::matrix<T, M, N> res;

	for (size_t i = 0; i < M; i++)
		for (size_t j = 0; j < N; j++)
			res(i, j) = mat1(i, j) - mat2(i, j);
	return res;
}

template<typename T, size_t M, size_t N>
inline constexpr Chaf::matrix<T, M, N> operator/(const Chaf::matrix<T, M, N>& mat, const T& s)
{
	Chaf::matrix<T, M, N> res;

	for (size_t i = 0; i < M; i++)
		for (size_t j = 0; j < N; j++)
			res(i, j) = mat(i, j) / s;
	return res;
}

template<typename T, size_t M, size_t N>
inline constexpr Chaf::matrix<T, M, N> operator^(const Chaf::matrix<T, M, N>& mat, const size_t& s)
{
	Chaf::matrix<T, M, N> res = Chaf::matrix<T, M, N>::unit();

	for (size_t i = 0; i < s; i++)
		res = res * mat;
	return res;
}

template<typename T, size_t M, size_t N, size_t K>
inline constexpr Chaf::matrix<T, M, K> operator*(const Chaf::matrix<T, M, N>& mat1, const Chaf::matrix<T, N, K>& mat2)
{
	Chaf::matrix<T, M, K> res;

	for (size_t i = 0; i < M; i++)
		for (size_t k = 0; k < K; k++)
			for (size_t j = 0; j < N; j++)		
				res(i, k) += mat1(i, j) * mat2(j, k);
	return res;
}

template<typename T, size_t M, size_t N>
inline constexpr Chaf::matrix<T, M, N> operator*(const T& s, const Chaf::matrix<T, M, N>& mat)
{
	Chaf::matrix<T, M, N> res;

	for (size_t i = 0; i < M; i++)
		for (size_t j = 0; j < N; j++)
				res(i, j) = mat(i, j) * s;
	return res;
}

template<typename T, size_t M, size_t N>
inline constexpr Chaf::matrix<T, M, N> operator*(const Chaf::matrix<T, M, N>& mat, const T& s)
{
	return s * mat;
}

template<typename T, size_t M, size_t N>
inline const Chaf::matrix<T, M, N> hadamardProduct(const Chaf::matrix<T, M, N>& mat)
{
	Chaf::matrix<T, M, N> res;
	for (size_t i = 0; i < M; i++)
		for (size_t j = 0; j < N; j++)
			res(i, j) = (*this)[i][j] * mat[i][j];
	return res;
}

template<typename T>
inline const T Chaf::matrix<T, 0, 0>::det() noexcept
{
	return ONE<T>;
}

template<typename T, size_t M, size_t N>
inline const T Chaf::matrix<T, M, N>::det() noexcept
{
	static_assert(M == N && M >= 1, "not support!");

	if (N == 1)return (*this)(0, 0);
	else if (N == 2)return (*this)(0, 0) * (*this)(1, 1) - (*this)(0, 1) * (*this)(1, 0);
	else
	{
		int flag = 1;
		T res = 0;
		Chaf::matrix<T, M - 1, N - 1> submatrix;
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < M - 1; j++)
				for (size_t k = 0; k < N-1; k++)
					submatrix(j, k) = (*this)(j + 1, (k < i ? k : k + 1));
			res += submatrix.det() * flag * (*this)(0, i);
			flag *= -1;
		}
		return res;
	}
}

template<typename T, size_t M, size_t N>
inline const Chaf::matrix<T, M, N> Chaf::matrix<T, M, N>::transpose()
{
	Chaf::matrix<T, N, M> res;
	for (size_t i = 0; i < N; i++)
		for (size_t j = 0; j < M; j++)
			res(i, j) = (*this)(j, i);
	return res;
}


template<typename T, size_t M, size_t N>
inline const Chaf::matrix<T, M, N> Chaf::matrix<T, M, N>::inverse()
{
	CHAF_ASSERT(M == N, "It's not a square matrix!");
	Chaf::matrix<T, N, M> res;
	if (M == 2)
	{
		res = { {(*this)(1,1),-(*this)(0,1)},{-(*this)(1,0),(*this)(0,0)} };
		return res / (det());
	}
	else
	{
		Chaf::matrix<T, M, N> adjmat;
		Chaf::matrix<T, M - 1, N - 1> help;
		for(size_t i=0;i<M;i++)
			for (size_t j = 0; j < N; j++)
			{
				for(size_t x=0;x<M-1;x++)
					for (size_t y = 0; y < N - 1; y++)
					{
						help(x, y) = (*this)((x >= i ? x + 1 : x) , (y >= j ? y + 1 : y));
					}
				adjmat(j, i) = static_cast<T>(std::pow(-1, i + j)) * help.det();
			}
		res = adjmat / det();
	}
	return res;
}

template<typename T, size_t M, size_t N>
std::ostream& operator<<(std::ostream& os, const Chaf::matrix<T, M, N>& mat)
{
	os << "matrix<" << typeid(T).name() << ", " << M << ", " << N << ">" << std::endl;
	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < N; j++)
			os << mat(i, j) << " ";
		os << std::endl;
	}
	return os;
}