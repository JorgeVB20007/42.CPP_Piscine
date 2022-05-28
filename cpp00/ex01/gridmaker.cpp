#include "contact.hpp"

void grid_printHeader(void)
{
	std::cout << " __________ __________ __________ __________" << std::endl;
//	std::cout << std::endl;
	std::cout << "|     INDEX|  1ST NAME| LAST NAME|  NICKNAME|" << std::endl;
//	std::cout << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
//	std::cout << std::endl;
}

void grid_printFooter(void)
{
	std::cout << "'----------'----------'----------'----------'" << std::endl;
}

void grid_printSpaces(int a)
{
	while (a)
	{
		std::cout << " ";
		a--;
	}
}

void grid_printItem(std::string item)
{
	int len;

	len = item.length();
	if (len > 10)
	{
		std::cout << item.substr(0, 9) << ".|";
	}
	else 
	{
		if (len < 10)
			grid_printSpaces (10 - len);
		std::cout << item << "|";
	}
}
