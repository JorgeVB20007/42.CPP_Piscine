/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:28:59 by jvacaris          #+#    #+#             */
/*   Updated: 2023/03/13 17:25:23 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <ctime>
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

std::vector<int> PmergeMe_vector(std::vector<int> the_vector);
std::deque<int> PmergeMe_deque(std::deque<int> the_deque);
void the_printer(std::vector<int> the_vector, std::deque<int> the_deque);

#endif
