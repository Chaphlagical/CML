#pragma once
#include <iostream>
namespace Chaf
{
	template<class F, typename T, size_t N >
	struct Operate1D
	{
		friend const F operator+(const F& a, const F& b)
		{
			F tmp;
			for (size_t i = 0; i < N; i++)tmp[i] = a[i] + b[i];
			return tmp;
		}
		friend const F operator-(const F& a, const F& b)
		{
			F tmp;
			for (size_t i = 0; i < N; i++)tmp[i] = a[i] - b[i];
			return tmp;
		}
		friend const F operator*(const F& a, const T& t)
		{
			F tmp;
			for (size_t i = 0; i < N; i++)tmp[i] = a[i] * t;
			return tmp;
		}
		friend const F operator*(const T& t, const F& a)
		{
			return a * t;
		}
		friend const F operator/(const F& a, const T& t)
		{
			return a * (1 / t);
		}
	};

	template<class F, typename T, size_t M, size_t N >
	struct Operate2D
	{
		friend const F operator+(const F& a, const F& b)
		{
			F tmp;
			for (size_t i = 0; i < N; i++)
				for (size_t j = 0; j < M; j++)
					tmp(i, j) = a(i, j) + b(i, j);
			return tmp;
		}
		friend const F operator-(const F& a, const F& b)
		{
			F tmp;
			for (size_t i = 0; i < N; i++)
				for (size_t j = 0; j < M; j++)
					tmp(i, j) = a(i, j) - b(i, j);
			return tmp;
		}
		friend const F operator*(const F& a, const T& t)
		{
			F tmp;
			for (size_t i = 0; i < N; i++)
				for (size_t j = 0; j < M; j++)
					tmp(i, j) = a(i, j) * t;
			return tmp;
		}
		friend const F operator*(const T& t, const F& a)
		{
			return a * t;
		}
		friend const F operator/(const F& a, const T& t)
		{
			return a * (1 / t);
		}
	};

	template<class F, typename T, size_t N >
	struct Stream1D
	{
		friend std::ostream& operator<<(std::ostream& os, const F& a)
		{
			os << "Type: " << typeid(F).name() << std::endl << "Data:" << std::endl;
			for (size_t i = 0; i < N; i++)
				os << a[i] << " ";
			os << std::endl;
			return os;
		}
	};
	template<class F, typename T, size_t M, size_t N >
	struct Stream2D
	{
		friend std::ostream& operator<<(std::ostream& os, const F& a)
		{
			os << "Type: " << typeid(F).name() << std::endl << "Data:" << std::endl;
			for (size_t i = 0; i < M; i++)
			{
				for (size_t j = 0; j < N; j++)
					os << a(i, j) << " ";
				os << std::endl;
			}
			return os;
		}
	};
}
