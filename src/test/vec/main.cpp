#include <iostream>
#include <CML/cml.h>
using namespace Chaf;
int main()
{
	cml::pointf3 a{ 1,2,3 };
	cml::pointf3 b{ -5,1,1 };
	cml::vecf3 v1{ 1,2,3 };
	cml::vecf3 v2{ 2,4,6 };
	cml::matf4 m1{ {1,2,2,1},{2,3,4,2},{3,4,5,3} };
	cml::matf4 m2{ {1,2,2,1},{2,3,4,2},{3,4,5,3} };
	cml::matf4 m;
	cml::vecf3 v;
	auto& x = a.cast<cml::vecf3>();
	m = m1 * m2;
	std::cout << (a==b);

	_CrtDumpMemoryLeaks();
	return 0;
}