#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
		srandom(std::time(NULL));
	else if (argc == 2)
		srandom(atoi(argv[1]));
	else
		std::cout << "Error: only 0-1 argumments are allowed." << std::endl;

//*		Creating an array of RANDOM_GENS pointers and setting them to a random Class.
	Base *pointers[RANDOM_GENS];

	for (int i = 0; i < RANDOM_GENS; i++)
	{
		pointers[i] = generate();
	}
	std::cout << std::endl;

//*		Identifying classes by address.
	for (int i = 0; i < RANDOM_GENS; i++)
	{
		std::cout << i << ": ";
		identify(pointers[i]);
	}
	std::cout << std::endl;

//*		Identifying classes by reference.
	for (int i = 0; i < RANDOM_GENS; i++)
	{
		std::cout << i << ": ";
		identify(*pointers[i]);
	}
	std::cout << std::endl;

	for (int i = 0; i < RANDOM_GENS; i++)
	{
		delete pointers[i];
	}
}