template<typename T, size_t N>
inline const Chaf::color<T, N> operator+(const Chaf::color<T, N>& v1, const Chaf::color<T, N>& v2)
{
	Chaf::color<T, N> res;
	for (size_t i = 0; i < N; i++)
		res[i] = v1[i] + v2[i];
	return res;
}

template<typename T, size_t N>
inline const Chaf::color<T, N> operator-(const Chaf::color<T, N>& v1, const Chaf::color<T, N>& v2)
{
	Chaf::color<T, N> res;
	for (size_t i = 0; i < N; i++)
		res[i] = v1[i] - v2[i];
	return res;
}

template<typename T, size_t N, typename F>
inline const Chaf::color<T, N> operator*(const Chaf::color<T, N>& v, const F& s)
{
	Chaf::color<T, N> res;
	for (size_t i = 0; i < N; i++)
		res[i] = v[i] * s;
	return res;
}

template<typename T, size_t N, typename F>
inline const Chaf::color<T, N> operator*(const F& s, const Chaf::color<T, N>& v)
{
	return v * s;
}

template<typename T, size_t N, typename F>
inline const Chaf::color<T, N> operator/(const Chaf::color<T, N>& v, const F& s)
{
	Chaf::color<T, N> res;
	for (size_t i = 0; i < N; i++)
		res[i] = v[i] / s;
	return res;
}

template<typename T, size_t N>
std::ostream& operator<<(std::ostream& os, const Chaf::color<T, N>& v)
{
	CHAF_ASSERT(N == 3 || N == 4, "unavailable color type!");
	if (N == 3)
		os << "rgb" << std::endl << "r=" << v[0] << " g=" << v[1] << " b=" << v[2] << std::endl;
	else if (N == 4)
		os << "rgb" << std::endl << "r=" << v[0] << " g=" << v[1] << " b=" << v[2] << " a=" << v[3] << std::endl;
	return os;
}