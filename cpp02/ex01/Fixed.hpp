/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:39:25 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/09 15:32:21 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed( Fixed const &tocopy );
		Fixed( const int inumber );		//* NEW
		Fixed( const float fnumber );	//* NEW
		Fixed & operator = (Fixed const &toequalize);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;	//* NEW
		int toInt( void ) const;		//* NEW
	private:
		int _fpv;
		static const int _frac_bits = 8;
	
};

std::ostream & operator << (std::ostream &output, Fixed const &toequalize);	//* NEW

#endif