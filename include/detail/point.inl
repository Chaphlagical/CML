template<typename T, size_t N>
inline constexpr Chaf::vec<T, N> operator-(const Chaf::point<T, N>& p1, const Chaf::point<T, N>& p2)
{
	Chaf::vec<T, N> res;
	for (size_t i = 0; i < N; i++)
		res[i] = p1[i] - p2[i];
	return res;
}

template<typename T, size_t N>
inline constexpr Chaf::point<T, N> operator+(const Chaf::point<T, N>& p, const Chaf::vec<T, N>& v)
{
	Chaf::point<T, N> res;
	for (size_t i = 0; i < N; i++)
		res[i] = p[i] + v[i];
	return res;
}

template<typename T, size_t N>
inline const T Chaf::point<T, N>::distance2(const Chaf::point<T, N>& p)
{
	T res = 0;
	for (size_t i = 0; i < N; i++)
		res += ((*this)[i] - p[i]) * ((*this)[i] - p[i]);
	return res;
}

template<typename T, size_t N>
inline const T Chaf::point<T, N>::distance(const Chaf::point<T, N>& p)
{
	return sqrt<T>(distance2(p));
}

#include <iostream>
#include <string>

template<typename T, size_t N>
std::ostream& operator<<(std::ostream& os, const Chaf::point<T, N>& v)
{
	os << "point<" << typeid(T).name() << ", " << N << ">" << std::endl;
	for (size_t i = 0; i < N; i++)
		os << v[i] << " ";
	os << std::endl;
	return os;
}