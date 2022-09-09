#include "Fixed.hpp"

std::string boolprint(int a)
{
	if (a)
		return ("\033[0;32mTrue\033[0m");
	else
		return ("\033[0;31mFalse\033[0m");
}

int main()
{
	{
		Fixed a(0);
		Fixed b(0);

		std::cout << std::endl << "\033[1ma = " << a << "   b = " << b << "\033[0m" << std::endl;
		
		std::cout << std::endl << "\033[0;33m-- Comparators --\033[0m" << std::endl;
		std::cout << "(a > b) - " << boolprint(a > b) << std::endl;
		std::cout << "(a < b) - " << boolprint(a < b) << std::endl;
		std::cout << "(a >= b) - " << boolprint(a >= b) << std::endl;
		std::cout << "(a <= b) - " << boolprint(a <= b) << std::endl;
		std::cout << "(a == b) - " << boolprint(a == b) << std::endl;
		std::cout << "(a != b) - " << boolprint(a != b) << std::endl;

		std::cout << std::endl << "\033[0;33m--- Operators ---\033[0m" << std::endl;
		std::cout << "(a + b) - " << (a + b) << std::endl;
		std::cout << "(a - b) - " << (a - b) << std::endl;
		std::cout << "(a * b) - " << (a * b) << std::endl;
		std::cout << "(a / b) - " << (a / b) << std::endl;
	}
}