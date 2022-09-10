#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	_fpv = 0;
}

Fixed::Fixed( Fixed const &tocopy )
{
	std::cout << "Copy constructor called" << std::endl;
	_fpv = tocopy.getRawBits();
}

Fixed::Fixed( const float fnumber )
{
	std::cout << "Float constructor called" << std::endl;
	_fpv = roundf((float)fnumber * (float)(1 << _frac_bits));
}

Fixed::Fixed( const int inumber )
{
	std::cout << "Int constructor called" << std::endl;
	_fpv = (inumber << _frac_bits);
	
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int Fixed::getRawBits( void ) const
{
	return (_fpv);
}

void Fixed::setRawBits(int const raw)
{
	_fpv = raw;
	return ;
}

Fixed & Fixed::operator = (Fixed const &toequalize)
{
	std::cout << "Assignation operator called" << std::endl;
	_fpv = toequalize.getRawBits();
	return *this;
}

std::ostream & operator << (std::ostream &output, Fixed const &toequalize)
{
	float result;

	result = toequalize.toFloat();
	output << result;
	return (output);
}

float Fixed::toFloat( void ) const
{
	float	result;

	result = (float)_fpv / (float)(1 << _frac_bits);
	return (result);
}

int Fixed::toInt( void ) const
{
	int	result;

	result = (_fpv >> _frac_bits);
	return (result);
}
