/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:20:31 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/15 17:20:32 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

std::string boolprint(int a)
{
	if (a)
		return ("\033[0;32mTrue\033[0m");
	else
		return ("\033[0;31mFalse\033[0m");
}

int main()
{
	{
		Fixed a(2.5f);
		Fixed b(1.75f);
		const Fixed c(4);
		const Fixed d(4.01f);

		std::cout << std::endl << "\033[1ma = " << a << "   b = " << b << "\033[0m" << std::endl;
		
		std::cout << std::endl << "\033[0;33m-- Comparators --\033[0m" << std::endl;
		std::cout << "(a > b) " << ARROW << boolprint(a > b) << std::endl;
		std::cout << "(a < b) " << ARROW << boolprint(a < b) << std::endl;
		std::cout << "(a >= b) " << ARROW << boolprint(a >= b) << std::endl;
		std::cout << "(a <= b) " << ARROW << boolprint(a <= b) << std::endl;
		std::cout << "(a == b) " << ARROW << boolprint(a == b) << std::endl;
		std::cout << "(a != b) " << ARROW << boolprint(a != b) << std::endl;

		std::cout << std::endl << "\033[0;33m--- Operators ---\033[0m" << std::endl;
		std::cout << "(a + b) " << ARROW << (a + b) << std::endl;
		std::cout << "(a - b) " << ARROW << (a - b) << std::endl;
		std::cout << "(a * b) " << ARROW << (a * b) << std::endl;
		std::cout << "(a / b) " << ARROW << (a / b) << std::endl;


		std::cout << std::endl << "\033[0;33m--- ++s & --s ---\033[0m" << std::endl;
		std::cout << "a | a++ | a " << ARROW << a << " | " << a++ << " | " << a << std::endl;
		std::cout << "a | a-- | a " << ARROW << a << " | " << a-- << " | " << a << std::endl;
		std::cout << "a | ++a | a " << ARROW << a << " | " << ++a << " | " << a << std::endl;
		std::cout << "a | --a | a " << ARROW << a << " | " << --a << " | " << a << std::endl;

		std::cout << std::endl << "\033[0;33m-- Maxs & Mins --\033[0m" << std::endl;
		std::cout << "Min a,b " << ARROW << Fixed::min(a, b) << std::endl;
		std::cout << "Max a,b " << ARROW << Fixed::max(a, b) << std::endl;
		std::cout << "Min c,d " << ARROW << Fixed::min(c, d) << std::endl;
		std::cout << "Max c,d " << ARROW << Fixed::max(c, d) << std::endl;
	}
}