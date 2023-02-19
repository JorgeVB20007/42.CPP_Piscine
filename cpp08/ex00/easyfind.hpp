/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:36:16 by jvacaris          #+#    #+#             */
/*   Updated: 2023/02/16 12:21:22 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <list>

#define NOTIFS 0

template<class T>
bool easyfind(T cont, int tofind)
{
	typename T::iterator iter;
	iter = std::find(cont.begin(), cont.end(), tofind);
	if (iter == cont.end())
		return (false);
//		std::cout << "False" << std::endl;
	else
		return (true);
//		std::cout << "True" << std::endl;
}

#endif
