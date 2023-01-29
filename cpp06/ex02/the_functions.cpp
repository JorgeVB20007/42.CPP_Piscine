#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	int chosen = random() % 3;

	if (chosen == 0)
	{
		std::cout << "\033[0;33m" << "Class A created." << "\033[0m" << std::endl;
		return (new A);
	}
	else if (chosen == 1)
	{
		std::cout << "\033[0;35m" << "Class B created." << "\033[0m" << std::endl;
		return (new B);
	}
	else
	{
		std::cout << "\033[0;36m" << "Class C created." << "\033[0m" << std::endl;
		return (new C);
	}
}

void identify(Base *p)
{

	{
		A	*ptr;
		ptr = dynamic_cast<A *>(p);
		if (ptr)
			std::cout << "\033[0;33m" << "A (from ptr)" << "\033[0m" << std::endl;
	}

	{
		B	*ptr;
		ptr = dynamic_cast<B *>(p);
		if (ptr)
			std::cout << "\033[0;35m" << "B (from ptr)" << "\033[0m" << std::endl;
	}

	{
		C	*ptr;
		ptr = dynamic_cast<C *>(p);
		if (ptr)
			std::cout << "\033[0;36m" << "C (from ptr)" << "\033[0m" << std::endl;
	}
}

void identify(Base &p)
{
	try 
	{
		A	ptr;
		ptr = dynamic_cast<A &>(p);
		std::cout << "\033[0;33m" << "A (from ref)" << "\033[0m" << std::endl;
	}
	catch (std::exception & e)
	{
	}
	try 
	{
		B	ptr;
		ptr = dynamic_cast<B &>(p);
		std::cout << "\033[0;35m" << "B (from ref)" << "\033[0m" << std::endl;
	}
	catch (std::exception & e)
	{
	}
	try 
	{
		C	ptr;
		ptr = dynamic_cast<C &>(p);
		std::cout << "\033[0;36m" << "C (from ref)" << "\033[0m" << std::endl;
	}
	catch (std::exception & e)
	{
	}
}
