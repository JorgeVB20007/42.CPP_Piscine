/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:20:41 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/15 17:20:41 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	_fpv = roundf((float)fnumber * (float)(1 << _frac_bits));
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
	Fixed result;
	result.setRawBits(_fpv + second.getRawBits());
	return (result);
}

Fixed Fixed::operator - (Fixed const &second)
{
	Fixed result;
	result.setRawBits(_fpv - second.getRawBits());
	return (result);
}

/*
?	^	(a * 2^8  +  b * 2^8) / 2^8  =  a + b
?	|	(a * 2^8  -  b * 2^8) / 2^8  =  a - b
!	|	(a * 2^8  *  b * 2^8) / 2^8  =  a * b / 2^8
!	V	(a * 2^8  /  b * 2^8) / 2^8  =  a / b * 2^8
*/

Fixed Fixed::operator * (Fixed const &second)
{
	Fixed result;
	result.setRawBits(_fpv * second.getRawBits() / (1 << 8));
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
	Fixed result;
	result.setRawBits(_fpv * (1 << 8) / second.getRawBits() );
	return (result);
}

Fixed operator ++ (Fixed &number)
{

	number.setRawBits(number.getRawBits() + /*(1 << 8)*/1);
	return (number);
}

Fixed operator -- (Fixed &number)
{
	number.setRawBits(number.getRawBits() - /*(1 << 8)*/1);
	return (number);
}

Fixed Fixed::operator ++ (int)
{
	Fixed result;

	result.setRawBits(_fpv);
	_fpv = _fpv + /*(1 << 8)*/1;
	return (result);
}

Fixed Fixed::operator -- (int)
{
	Fixed result;

	result.setRawBits(_fpv);
	_fpv = _fpv - /*(1 << 8)*/1;
	return (result);
}

Fixed & Fixed::min(Fixed &first, Fixed &second)
{
	if (first.getRawBits() > second.getRawBits())
		return (second);
	else
		return (first);
}

const Fixed & Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first.getRawBits() > second.getRawBits())
		return (second);
	else
		return (first);
}

Fixed & Fixed::max(Fixed &first, Fixed &second)
{
	if (first.getRawBits() < second.getRawBits())
		return (second);
	else
		return (first);
}

const Fixed & Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first.getRawBits() < second.getRawBits())
		return (second);
	else
		return (first);
}

