#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	_fpv = 0;
}

Fixed::Fixed( Fixed &tocopy )
{
	std::cout << "Copy constructor called" << std::endl;
	_fpv = tocopy.getRawBits();
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fpv);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fpv = raw;
	return ;
}

Fixed & Fixed::operator = (Fixed &toequalize)
{
	std::cout << "Assignation operator called" << std::endl;
	_fpv = toequalize.getRawBits();
	return *this;
}
