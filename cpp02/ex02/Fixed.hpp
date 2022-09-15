/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:39:25 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/13 14:18:53 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# define SHOWLOG 0
# define ARROW "\033[0;36m--->\033[0m "

# include <iostream>
# include <cmath>

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
		Fixed operator ++ (int);
		Fixed operator -- (int);
		static Fixed & min(Fixed &first, Fixed &second);
		static const Fixed & min(const Fixed &first, const Fixed &second);
		static Fixed & max(Fixed &first, Fixed &second);
		static const Fixed & max(const Fixed &first, const Fixed &second);

	private:
		int _fpv;
		static const int _frac_bits = 8;
	
};

Fixed &operator ++ (Fixed &number);
Fixed &operator -- (Fixed &number);

std::ostream & operator << (std::ostream &output, Fixed const &toequalize);

#endif
