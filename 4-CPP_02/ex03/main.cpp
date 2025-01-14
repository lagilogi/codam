#include "header.hpp"

int main()
{
	Point a(0, 0);
	Point b(0, 5);
	Point c(5, 0);
	
	Point d(3.1, 3.1);
	Point e(1, 1);
	Point f(6, 100);
	Point g(0, 0);
	Point h(2.5, 1);

	std::cout << "Point d: " << bsp(a, b, c, d) << std::endl;
	std::cout << "Point e: " << bsp(a, b, c, e) << std::endl;
	std::cout << "Point f: " << bsp(a, b, c, f) << std::endl;
	std::cout << "Point g: " << bsp(a, b, c, g) << std::endl;
	std::cout << "Point h: " << bsp(a, b, c, h) << std::endl;
}
