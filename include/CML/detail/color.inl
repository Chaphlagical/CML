namespace Chaf
{
	namespace cml
	{
		template<typename T, size_t N>
		const color<T, N>& color<T, N>::operator+=(const color<T, N>& v)
		{
			return ((*this).cast<vec<T, N>>() += v.cast<vec<T, N>>()).cast<color<T, N>>();
		}
		template<typename T, size_t N>
		const color<T, N>& color<T, N>::operator-=(const color<T, N>& v)
		{
			return ((*this).cast<vec<T, N>>() -= v.cast<vec<T, N>>()).cast<color<T, N>>();
		}
		template<typename T, size_t N>
		const color<T, N>& color<T, N>::operator*=(const T& t)
		{
			return ((*this).cast<vec<T, N>>() *= t).cast<color<T, N>>();
		}
		template<typename T, size_t N>
		const color<T, N>& color<T, N>::operator/=(const T& t)
		{
			return ((*this).cast<vec<T, N>>() /= t).cast<color<T, N>>();
		}
		template<typename T, size_t N>
		const color<T, N> color<T, N>::operator+()
		{
			return (+(*this).cast<vec<T, N>>()).cast<color<T, N>>();
		}
		template<typename T, size_t N>
		const color<T, N> color<T, N>::operator-()
		{
			return (-(*this).cast<vec<T, N>>()).cast<color<T, N>>();
		}
	}
}