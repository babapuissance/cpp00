#include <iostream>
#include "Point.hpp"

bool bsp(Point const& a, Point const& b, Point const& c, Point const& point);

int main(void)
{
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(5.0f, 10.0f);

	std::cout << "Triangle: A(0,0), B(10,0), C(5,10)\n";

	Point p1(5.0f, 5.0f);
	std::cout << "Point (5, 5): " << (bsp(a, b, c, p1) ? "Inside" : "Outside") << '\n';

	Point p2(15.0f, 5.0f);
	std::cout << "Point (15, 5): " << (bsp(a, b, c, p2) ? "Inside" : "Outside") << '\n';

	Point p3(0.0f, 0.0f);
	std::cout << "Point (0, 0) [vertex]: " << (bsp(a, b, c, p3) ? "Inside" : "Outside") << '\n';

	Point p4(5.0f, 0.0f);
	std::cout << "Point (5, 0) [edge]: " << (bsp(a, b, c, p4) ? "Inside" : "Outside") << '\n';

	Point a2(0.0f, 0.0f), b2(5.0f, 10.0f), c2(10.0f, 0.0f);
	std::cout << "Inverted order: " << (bsp(a2, b2, c2, p1) ? "Inside" : "Outside") << '\n';

	Point d1(0.0f, 0.0f), d2(5.0f, 0.0f), d3(10.0f, 0.0f);
	std::cout << "Degenerate triangle: " << (bsp(d1, d2, d3, p1) ? "Inside" : "Outside") << '\n';

	return 0;
}
