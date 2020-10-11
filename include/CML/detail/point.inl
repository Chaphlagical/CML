namespace Chaf
{
	namespace cml
	{
		template<typename T, size_t N>
		const vec<T, N>operator-(const point<T, N>& p1, const point<T, N>& p2)
		{
			vec<T, N> v;
			for (size_t i = 0; i < N; i++)v[i] = p1[i] - p2[i];
			return v;
		}
		template<typename T, size_t N>
		const point<T, N>operator+(const point<T, N>& p, const vec<T, N>& v)
		{
			point<T, N> res;
			for (size_t i = 0; i < N; i++)res[i] = p[i] + v[i];
			return res;
		}
		template<typename T, size_t N>
		const T point<T, N>::distance2(const point<T, N>& p) const
		{
			return (*this - p).norm2();
		}
		template<typename T, size_t N>
		const T point<T, N>::distance(const point<T, N>& p) const
		{
			return (*this - p).norm();
		}
	}
}