/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:39:25 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/06 20:50:31 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed( Fixed &tocopy );
		Fixed( const int inumber );		//* NEW
		Fixed( const float fnumber );	//* NEW
		Fixed & operator = (Fixed &toequalize);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;	//* NEW
		int toInt( void ) const;		//* NEW
		Fixed & operator << (Fixed &toequalize);	//* NEW
	private:
		int _fpv;
		static const int _frac_bits = 8;
	
};

int getexponent(int fourbytes)
{
	int a = 0;

	fourbytes << 1;
	fourbytes >> 24;
	return (-127 + fourbytes)
}

#endif