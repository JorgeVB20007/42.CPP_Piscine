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

Fixed::Fixed( const float fnumber )
{
	std::cout << "Float constructor called" << std::endl;
	_fpv = fnumber;
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

int getexponent(int fourbytes)
{
	int a = 0;

	fourbytes << 1;
	fourbytes >> 24;
	return (-127 + fourbytes);
}
