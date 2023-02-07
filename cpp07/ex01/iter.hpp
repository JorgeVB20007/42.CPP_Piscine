/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:00:16 by jvacaris          #+#    #+#             */
/*   Updated: 2023/02/06 19:07:25 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#define NOTIFS 0

#include <iostream>

template <class t_iter>
void iter(t_iter *str, size_t len, void (function)(t_iter &))
{
	for (size_t i = 0; i < len; i++)
	{
		function(str[i]);
	}
}

#endif