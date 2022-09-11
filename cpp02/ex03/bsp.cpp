#include "Point.hpp"

/*
?	Actually, it calculates the area * 2. But saving the last division increases precision.
*/
Fixed calculate_area(Point const a, Point const b, Point const c)
{
	Fixed result;
	result = (a.getX() * (b.getY() - c.getY())  +  b.getX() * (c.getY() - a.getY())  +  c.getX() * (a.getY() - b.getY()));
	if (result < 0.0f)
		result = result * -1.0f;
	std::cout << ">> " << result << std::endl;
	return (result);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed totalarea;
	Fixed area1;
	Fixed area2;
	Fixed area3;
	Fixed sumarea;

	totalarea = calculate_area(a, b, c);

	area1 = calculate_area(a, b, point);
	area2 = calculate_area(a, c, point);
	area3 = calculate_area(b, c, point);

	sumarea = area1 + area2 + area3;

	std::cout << "totalarea = " << totalarea << std::endl;
	std::cout << "sumarea = " << sumarea << std::endl;

	return (sumarea <= totalarea && (bool)(area1 * area2 * area3 * totalarea).toFloat());
}