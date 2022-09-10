#include "Point.hpp"

Point::Point(): x(0), y(0)
{
	if (SHOWLOG)
		std::cout << "Constructor called. X & Y set to 0." << std::endl;
}

Point::Point(Point &tocopy): x(tocopy.x), y(tocopy.y)
{
	if (SHOWLOG)
		std::cout << "Copy constructor called." << std::endl;
}

Point::Point(const float nx, const float ny): x(nx), y(ny)
{
	if (SHOWLOG)
		std::cout << "Constructor called. X & Y set to " << nx << " & " << ny << std::endl;
}

Point::~Point()
{
	if (SHOWLOG)
		std::cout << "Destructor called." << std::endl;
}

float Point::getX()
{
	return (x.toFloat());
}

float Point::getY()
{
	return (y.toFloat());
}
