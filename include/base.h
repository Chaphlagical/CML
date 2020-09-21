#ifndef BASE_H
#define BASE_H

namespace Chaf
{
	template<typename T>
	constexpr auto PI = static_cast<T>(3.1415926535);

	template<typename T>
	constexpr auto EPSILON = static_cast<T>(0.001);

	template<typename T>
	constexpr auto ZERO = static_cast<T>(0);

	template<typename T>
	constexpr auto ONE = static_cast<T>(1);

	template<typename T>
	constexpr T sqrt(const T val) { return static_cast<T>(std::sqrt(static_cast<double>(val))); }

}

#include <iostream>
#ifdef CHAF_DEBUG
#define CHAF_ASSERT(x,...) {if(!(x)) {std::cout<<"Assertion Failed: "<<__VA_ARGS__;__debugbreak();}}
#else
#define CHAF_ASSERT(x,...)
#endif

#endif // !BASE_H