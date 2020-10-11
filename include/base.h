#ifndef BASE_H
#define BASE_H

namespace Chaf
{
	template<typename T>
	constexpr auto PI = static_cast<T>(3.1415926535);

	template<typename T>
	constexpr auto EPSILON = static_cast<T>(0.00001);

	template<typename T>
	constexpr auto ZERO = static_cast<T>(0);

	template<typename T>
	constexpr auto ONE = static_cast<T>(1);

	template<typename T>
	constexpr T Sqrt(const T val) { return static_cast<T>(std::sqrt(static_cast<double>(val))); }

	template<typename T>
	constexpr T Abs(const T val) { return (val > 0 ? val : -val); }

	template<typename T>
	constexpr T Cos(const T val) { return static_cast<T>(std::cos(static_cast<double>(val))); }

	template<typename T>
	constexpr T Sin(const T val) { return static_cast<T>(std::sin(static_cast<double>(val))); }

	template<typename T>
	constexpr T Tan(const T val) { return static_cast<T>(std::tan(static_cast<double>(val))); }

	template<typename T>
	constexpr T Deg2Rad(const T val) { return static_cast<T>((PI<double> / 180.0) * static_cast<double>(val)); }

	template<typename T>
	constexpr T Rad2Deg(const T val) { return static_cast<T>((180.0 / PI<double>) * static_cast<double>(val)); }
}
#include <iostream>
#ifndef NDEBUG
#define CHAF_ASSERT(x,...) {if(!(x)) {std::cout<<"Assertion Failed: "<<__VA_ARGS__;__debugbreak();}}
#else
#define CHAF_ASSERT(x,...)
#endif
#endif // !BASE_H