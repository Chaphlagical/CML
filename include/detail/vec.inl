namespace Chaf
{
	namespace cml
	{
		template<typename T, size_t N>
		const T vec<T, N>::dot(const vec<T, N>& v) const
		{
			T val = 0;
			for (size_t i = 0; i < N; i++)val += (*this)[i] * v[i];
			return val;
		}

		template<typename T, size_t N>
		const vec<T, 3> vec<T, N>::cross(const vec<T, 3>& v) const
		{
			static_assert(N == 3, "error occurs!");
			return{
				(*this)[1] * v[2] - (*this)[2] * v[1],
				(*this)[2] * v[0] - (*this)[0] * v[2],
				(*this)[0] * v[1] - (*this)[1] * v[0]
			};
		}

		template<typename T, size_t N>
		const T vec<T, N>::cross(const vec<T, 2>& v) const
		{
			static_assert(N == 2, "error occurs!");
			return (*this)[0] * v[1] - (*this)[1] * v[0];
		}

		template<typename T, size_t N>
		const vec<T, N> vec<T, N>::hadamardProduct(const vec<T, N>& v) const
		{
			vec<T, N> tmp(0);
			for (size_t i = 0; i < N; i++)tmp[i] = (*this)[i] * v[i];
			return tmp;
		}

		template<typename T, size_t N>
		const T vec<T, N>::norm() const
		{
			return Sqrt<T>((*this).norm2());
		}

		template<typename T, size_t N>
		const T vec<T, N>::norm2() const
		{
			return (*this).dot(*this);
		}

		template<typename T, size_t N>
		const vec<T, N> vec<T, N>::normalize() const
		{
			return (*this) / (*this).norm();
		}

		template<typename T, size_t N>
		const bool vec<T, N>::isParallel(const vec<T, N>& v) const
		{
			if (Abs<T>(Abs<T>(v.dot(*this)) - v.norm() * (*this).norm()) < EPSILON<T>)return true;
			return false;
		}

		template<typename T, size_t N>
		const bool vec<T, N>::isVertical(const vec<T, N>& v) const
		{
			if (Abs<T>(Abs<T>(v.dot(*this)) < EPSILON<T>))return true;
			return false;
		}

		template<typename T, size_t N>
		const vec<T, N>& vec<T, N>::operator+=(const vec<T, N>& v)
		{
			(*this) = (*this) + v;
			return *this;
		}

		template<typename T, size_t N>
		const vec<T, N>& vec<T, N>::operator-=(const vec<T, N>& v)
		{
			(*this) = (*this) - v;
			return *this;
		}

		template<typename T, size_t N>
		const vec<T, N>& vec<T, N>::operator*=(const T& t)
		{
			(*this) = (*this) * v;
			return *this;
		}

		template<typename T, size_t N>
		const vec<T, N>& vec<T, N>::operator/=(const T& t)
		{
			(*this) = (*this) / t;
			return *this;
		}

		template<typename T, size_t N>
		const bool vec<T, N>::operator==(const vec<T, N>& v)
		{
			for (size_t i = 0; i < N; i++)
				if ((*this)[i] != v[i])return false;
			return true;
		}

		template<typename T, size_t N>
		const bool vec<T, N>::operator!=(const vec<T, N>& v)
		{
			return !((*this) == v);
		}

		template<typename T, size_t N>
		const vec<T, N> vec<T, N>::operator+()
		{
			return *this;
		}

		template<typename T, size_t N>
		const vec<T, N> vec<T, N>::operator-()
		{
			for (size_t i = 0; i < N; i++)
				(*this)[i] = -(*this)[i];
			return true;
		}
	}
}