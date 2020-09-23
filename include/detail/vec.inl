template<typename T, size_t N>
inline constexpr Chaf::vec<T, N> operator+(const Chaf::vec<T, N>& v1, const Chaf::vec<T, N>& v2)
{
	Chaf::vec<T, N> res;
	for (size_t i = 0; i < N; i++)
		res[i] = v1[i] + v2[i];
	return res;
}

template<typename T, size_t N>
inline constexpr Chaf::vec<T, N> operator-(const Chaf::vec<T, N>& v1, const Chaf::vec<T, N>& v2)
{
	Chaf::vec<T, N> res;
	for (size_t i = 0; i < N; i++)
		res[i] = v1[i] - v2[i];
	return res;
}

template<typename T, size_t N, typename F>
inline constexpr Chaf::vec<T, N> operator*(const Chaf::vec<T, N>& v, const F& s)
{
	Chaf::vec<T, N> res;
	for (size_t i = 0; i < N; i++)
		res[i] = v[i] * s;
	return res;
}

template<typename T, size_t N, typename F>
inline constexpr Chaf::vec<T, N> operator*(const F& s, const Chaf::vec<T, N>& v)
{
	return v * s;
}

template<typename T, size_t N, typename F>
inline constexpr Chaf::vec<T, N> operator/(const Chaf::vec<T, N>& v, const F& s)
{
	Chaf::vec<T, N> res;
	for (size_t i = 0; i < N; i++)
		res[i] = v[i] / s;
	return res;
}

template<typename T, size_t N>
inline constexpr T Chaf::vec<T, N>::dot(const Chaf::vec<T, N>& v)
{
	T res = 0;
	for (size_t i = 0; i < N; i++)
		res += (*this)[i] * v[i];
	return res;
}

template<typename T, size_t N>
inline constexpr Chaf::vec<T, N> Chaf::vec<T, N>::cross(const vec<T, N>& v)
{
	CHAF_ASSERT(N == 3, "Only support 3 dimension for now!");
	return Chaf::vec<T, 3>{
		(*this)[1] * v[2] - (*this)[2] * v[1],
		(*this)[2] * v[0] - (*this)[0] * v[2],
		(*this)[0] * v[1] - (*this)[1] * v[0]
	};
}

template<typename T, size_t N>
inline constexpr Chaf::vec<T, N> Chaf::vec<T, N>::hadamardProduct(const vec<T, N>& v)
{
	Chaf::vec<T, N> res;
	for (size_t i = 0; i < N; i++)
		res[i] = v[i] * (*this)[i];
	return res;
}

template<typename T, size_t N>
inline constexpr T Chaf::vec<T, N>::norm2()
{
	T res = 0;
	for (size_t i = 0; i < N; i++)
		res += (*this)[i] * (*this)[i];
	return res;
}

template<typename T, size_t N>
inline constexpr T Chaf::vec<T, N>::norm()
{
	return Sqrt<T>(norm2());
}

template<typename T, size_t N>
inline constexpr Chaf::vec<T, N> Chaf::vec<T, N>::normalize()
{
	T n = norm();
	return *this / n;
}

#include <iostream>
#include <string>

template<typename T, size_t N>
std::ostream& operator<<(std::ostream& os, const Chaf::vec<T, N>& v)
{
	os << "vector<" << typeid(T).name() << ", " << N << ">" << std::endl;
	for (size_t i = 0; i < N; i++)
		os << v[i] << " ";
	os << std::endl;
	return os;
}