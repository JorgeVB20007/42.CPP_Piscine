/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:39:25 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/09 17:23:58 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# define SHOWLOG 0

# include <iostream>

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed( Fixed const &tocopy );
		Fixed( const int inumber );
		Fixed( const float fnumber );
		Fixed & operator = (Fixed const &toequalize);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		bool operator > (Fixed const &second);		//* NEW
		bool operator < (Fixed const &second);		//* NEW
		bool operator >= (Fixed const &second);		//* NEW
		bool operator <= (Fixed const &second);		//* NEW
		bool operator == (Fixed const &second);		//* NEW
		bool operator != (Fixed const &second);		//* NEW
		Fixed operator + (Fixed const &second);	//* NEW
		Fixed operator - (Fixed const &second);	//* NEW
		Fixed operator * (Fixed const &second);	//* NEW
		Fixed operator / (Fixed const &second);	//* NEW
	private:
		int _fpv;
		static const int _frac_bits = 8;
	
};

std::ostream & operator << (std::ostream &output, Fixed const &toequalize);

#endif