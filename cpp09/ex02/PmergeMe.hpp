/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:28:59 by jvacaris          #+#    #+#             */
/*   Updated: 2023/03/12 20:13:40 by jvacaris         ###   ########.fr       */
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

void PmergeMe_vector(std::vector<int> the_vector);
void the_printer(std::vector<int> the_vector, std::deque<int> the_deque);

#endif
