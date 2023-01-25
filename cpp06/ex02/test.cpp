#include <iostream>
//#include <


int main()
{
	for (int a = 0; a < 15; a++)
		std::cout << rand() % 3 + 1 << std::endl;
}