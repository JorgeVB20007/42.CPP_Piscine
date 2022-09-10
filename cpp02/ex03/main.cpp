#include "Point.hpp"

std::string boolprint(int a)
{
	if (a)
		return ("\033[1;32mTrue\033[0m");
	else
		return ("\033[1;31mFalse\033[0m");
}

void announcepoint(Point pt, std::string name)
{
	std::cout << "Point " << name << " (" << pt.getX() << " , " << pt.getY() << ") " << std::endl;
}

int	main( void )
{
	Point	ap;
	Point	bp(5.0f, 1.5f);
	Point	cp(2.5f, 6.0f);

	Point	pp(2.0f, 2.0f);
	bool	result;

	announcepoint(ap, "A");
	announcepoint(bp, "B");
	announcepoint(cp, "C");
	announcepoint(pp, "P");
	std::cout << std::endl;
	result = bsp(ap, bp, cp, pp);
	std::cout << "Point is inside the triangle? " << boolprint(result) << std::endl;
}