/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:39:25 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/04 22:04:41 by jvacaris         ###   ########.fr       */
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
		//TODO Assignation operator overload??
		Fixed & operator = (Fixed &toequalize);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
	private:
		int _fpv;
		static const int _frac_bits = 8;
	
};

#endif