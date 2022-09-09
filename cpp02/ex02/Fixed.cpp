#include "Fixed.hpp"

Fixed::Fixed(void)
{
	if (SHOWLOG)
		std::cout << "Default constructor called" << std::endl;
	_fpv = 0;
}

Fixed::Fixed( Fixed const &tocopy )
{
	if (SHOWLOG)
		std::cout << "Copy constructor called" << std::endl;
	_fpv = tocopy.getRawBits();
}

Fixed::Fixed( const float fnumber )
{
	if (SHOWLOG)
		std::cout << "Float constructor called" << std::endl;
	_fpv = (float)fnumber * (float)(1 << _frac_bits);
}

Fixed::Fixed( const int inumber )
{
	if (SHOWLOG)
		std::cout << "Int constructor called" << std::endl;
	_fpv = (inumber << _frac_bits);
	
}

Fixed::~Fixed(void)
{
	if (SHOWLOG)
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
	if (SHOWLOG)
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


bool Fixed::operator > (Fixed const &second)
{
	return (_fpv > second.getRawBits());
}

bool Fixed::operator < (Fixed const &second)
{
	return (_fpv < second.getRawBits());
}

bool Fixed::operator >= (Fixed const &second)
{
	return (_fpv >= second.getRawBits());
}

bool Fixed::operator <= (Fixed const &second)
{
	return (_fpv <= second.getRawBits());
}

bool Fixed::operator == (Fixed const &second)
{
	return (_fpv == second.getRawBits());
}

bool Fixed::operator != (Fixed const &second)
{
	return (_fpv != second.getRawBits());
}

Fixed Fixed::operator + (Fixed const &second)
{
	Fixed result((_fpv + second.getRawBits()) / (1 << 8));
	return (result);
}

Fixed Fixed::operator - (Fixed const &second)
{
	Fixed result((_fpv - second.getRawBits()) / (1 << 8));
	return (result);
}

Fixed Fixed::operator * (Fixed const &second)
{
	Fixed result(_fpv * second.getRawBits() / (float)(1 << 16));
	return (result);
}

Fixed Fixed::operator / (Fixed const &second)
{
	if (!second.getRawBits())
	{
		Fixed fakeresult(0);
		std::cerr << " (Trying to divide by zero. Result has been replaced by a 0) ";
		return (fakeresult);
	}
		
	Fixed result(_fpv / second.getRawBits()/* * (float)(1 << 8)*/);
	return (result);
}
