/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:28:59 by jvacaris          #+#    #+#             */
/*   Updated: 2023/03/08 21:45:02 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>


#define NOTIFS 0

class ExtraneousChars: public std::exception
{
	public:
		const char *what() const throw()
		{
			return("Error: Input contains an invalid character.");
		}
};

#endif
