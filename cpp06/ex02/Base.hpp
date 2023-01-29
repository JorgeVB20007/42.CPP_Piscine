#ifndef BASE_HPP
# define BASE_HPP

#define NOTIFS 0
#define RANDOM_GENS 5

#include <iostream>
#include <ctime>

class Base
{
	public:
		virtual ~Base();
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif