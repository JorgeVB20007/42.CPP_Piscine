/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:36:16 by jvacaris          #+#    #+#             */
/*   Updated: 2023/02/14 21:54:09 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <algorithm>
#include <vector>

#define NOTIFS 0

template<class T>
void easyfind(T cont, int tofind)
{
	typename T::iterator iter;
	iter = std::find(cont.begin(), cont.end(), tofind);
	if (iter == cont.end())
		std::cout << "False" << std::endl;
	else
		std::cout << "True" << std::endl;
}

#endif
