/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:39:25 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/06 21:16:22 by jvacaris         ###   ########.fr       */
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

int getexponent(int fourbytes);

#endif