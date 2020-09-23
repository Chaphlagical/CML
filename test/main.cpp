#include "../include/vec.h"
#include "../include/point.h"
#include "../include/color.h"
#include "../include/matrix.h"
#include "../include/transform.h"
#include <array>
#include <iostream>

using namespace Chaf;

int main()
{
	// init
	// vector
	vecf2 v2{ 1,2 };
	std::cout << "v2: " << v2 << std::endl;
	
	vecf3 v3 = { 3,4,5 };
	std::cout << "v3: " << v3 << std::endl;

	// point
	pointf2 p2{ 2,3 };
	std::cout << "p2: " << p2 << std::endl;

	pointf3 p3{ 4,5,6 };
	std::cout << "p3: " << p3 << std::endl;
	// color
	rgbf color_rgb{ 2,3,4 };
	std::cout << "color_rgb: " << color_rgb << std::endl;

	rgbaf color_rgba{ 4,5,2,1 };
	std::cout << "color_rgba: " << color_rgba << std::endl;

	// add
	std::cout << "v3+(2,3,5): " << v3 + vecf3{2,3,5} << std::endl;
	std::cout << "p2+v2: " << p2 + v2 << std::endl;
	std::cout << "color_rgba+(2,3,5,6): " << color_rgba + rgbaf{ 2,3,5,6 } << std::endl;
	

	// sub
	std::cout << "v3-(2,3,5): " << v3 - vecf3{ 2,3,5 } << std::endl;
	std::cout << "p2-(2,3): " << p2 - pointf2{ 2,3 } << std::endl;
	std::cout << "color_rgba-(2,3,5,6): " << color_rgba - rgbaf{ 2,3,5,6 } << std::endl;

	// mul
	std::cout << "3*v3" << 3 * v3 << std::endl;
	std::cout << "3*color_rgb" << 3 * color_rgb << std::endl;

	// dot
	std::cout << "v3 .* (2,3,5)" << v3.dot(vecf3{ 2,3,5 }) << std::endl;

	// cross
	std::cout << "v3 x (2,3,5)" << v3.cross(vecf3{ 2,3,5 }) << std::endl;

	// Hadamard Product
	std::cout << "v3 @ (2,3,5)" << v3.hadamardProduct(vecf3{ 2,3,5 }) << std::endl;

	matrix<float, 2, 3> mat1{ {1,2,3},{2,3,1} };
	matrix<float, 3, 2> mat2{ {2,2},{5,3},{3,5} };
	auto m = mat2 * mat1;
	std::cout << mat1;
	std::cout << mat2;
	std::cout << m;
	m(0, 0) = 100;
	std::cout << m << std::endl;
	Chaf::matrix<float, 5, 5> mm{ {1, 2, 3,4,5},
		{ 2,3,5,1,2 },
		{3,6,4,2,1},
		{4,2,7,9,0},
		{1,2,5,3,4}
	};
	
	std::cout << transformf::transMatrix(transformf::translation({ 1.0f,2.0f,3.0f }), transformf::rotation(30.f, { 0.0f,0.0f,1.0f }), transformf::scale({ 2.0f,4.0f,5.0f }));
	std::cout << transformf::transMatrix({ 1.0f,2.0f,3.0f },
		matrixf3{ {Cos<float>(30.f),-Sin<float>(30.0f),0},{Sin<float>(30.0f),Cos<float>(30.0f),0},{0,0,1} },
		{ 2.0f,4.0f,5.0f });
	std::cout << transformf::translation(v3,2.0f,3.0f,4.0f);
	std::cout << transformf::lookAt({ 1.0f,0.0f,0.0f }, { 0.0f,0.0f,0.0f }, { 0.0f,0.0f,1.0f });

	_CrtDumpMemoryLeaks();
	return 0;
}