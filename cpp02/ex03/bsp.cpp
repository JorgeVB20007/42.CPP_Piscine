/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:20:38 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/15 17:20:38 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
?	Actually, it calculates the area * 2. But saving the last division increases precision.
*/
Fixed calculate_area(Point const a, Point const b, Point const c)
{
	Fixed result;
	result = (a.getX() * (b.getY() - c.getY())  +  b.getX() * (c.getY() - a.getY())  +  c.getX() * (a.getY() - b.getY()));
	if (result < 0.0f)
		result = result * -1.0f;
	return (result);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed totalarea;
	Fixed area1;
	Fixed area2;
	Fixed area3;
	Fixed sumarea;

	totalarea = calculate_area(a, b, c);

	area1 = calculate_area(a, b, point);
	area2 = calculate_area(a, c, point);
	area3 = calculate_area(b, c, point);

	sumarea = area1 + area2 + area3;

	return (sumarea <= totalarea && (bool)(area1 * area2 * area3 * totalarea).toFloat());
}