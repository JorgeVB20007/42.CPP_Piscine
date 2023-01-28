#include "Base.hpp"

Base::~Base()
{
	if (NOTIFS)
		std::cout << "Destructor called" << std::endl;
}
