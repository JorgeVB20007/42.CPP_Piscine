/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:00:16 by jvacaris          #+#    #+#             */
/*   Updated: 2023/02/06 18:31:12 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <class t_swap>
void swap(t_swap &x, t_swap &y)
{
	t_swap z;

	z = x;
	x = y;
	y = z;
}

template <class t_min>
t_min min(t_min x, t_min y)
{
	if (x < y)
		return (x);
	return (y);
}

template <class t_max>
t_max max(t_max x, t_max y)
{
	if (x > y)
		return (x);
	return (y);
}

#endif