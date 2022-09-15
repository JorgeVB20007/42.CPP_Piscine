/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:20:45 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/15 17:20:46 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

std::string boolprint(int a)
{
	if (a)
		return ("\033[1;32mTrue\033[0m");
	else
		return ("\033[1;31mFalse\033[0m");
}

static void announcepoint(Point const pt, std::string name)
{
	std::cout << "Point " << name << " (" << pt.getX().toFloat() << " , " << pt.getY().toFloat() << ") " << std::endl;
}

int	main( void )
{
	Point const	ap;
	Point const	bp(4.9f, -0.1f);
	Point const	cp(-0.1f, 4.9f);

	Point const	pp(2.1f, 1.9f);
	bool	result;

	announcepoint(ap, "A");
	announcepoint(bp, "B");
	announcepoint(cp, "C");
	announcepoint(pp, "P");
	std::cout << std::endl;
	result = bsp(ap, bp, cp, pp);
	std::cout << "Point is inside the triangle? " << boolprint(result) << std::endl;
}