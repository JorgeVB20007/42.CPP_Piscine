/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:20:50 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/15 17:20:50 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0)
{
	if (SHOWLOG)
		std::cout << "Constructor called. X & Y set to 0." << std::endl;
}

Point::Point(Point &tocopy): x(tocopy.x), y(tocopy.y)
{
	if (SHOWLOG)
		std::cout << "Copy constructor called." << std::endl;
}

Point::Point(const Point &tocopy): x(tocopy.x), y(tocopy.y)
{
	if (SHOWLOG)
		std::cout << "Copy constructor called." << std::endl;
}

Point::Point(const float nx, const float ny): x(nx), y(ny)
{
	if (SHOWLOG)
		std::cout << "Constructor called. X & Y set to " << nx << " & " << ny << std::endl;
}

Point::~Point()
{
	if (SHOWLOG)
		std::cout << "Destructor called." << std::endl;
}

Fixed Point::getX() const
{
	return (x);
}

Fixed Point::getY() const
{
	return (y);
}

Point & Point::operator = (Point const &toequalize)
{
	(Fixed)x = toequalize.getX();
	(Fixed)y = toequalize.getY();
	return *this;
}
