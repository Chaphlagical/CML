#include <iostream>
#include <vec.h>
#include <color.h>
#include <point.h>
#include <matrix.h>
using namespace Chaf;
int main()
{
	cml::pointf3 a{ 1,2,3 };
	cml::pointf3 b{ -5,1,1 };
	cml::vecf3 v1{ 1,2,3 };
	cml::vecf3 v2{ 2,4,6 };
	cml::matf3 m1{ {1,2,2},{2,3,4},{3,4,5} };
	cml::matf3 m2{ {1,2,2},{2,3,4},{3,4,5} };
	auto& x = a.cast<cml::vecf3>();
	std::cout << a;
	std::cout << cml::matf3::unit();

	_CrtDumpMemoryLeaks();
	return 0;
}