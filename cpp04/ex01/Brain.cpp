/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:38:48 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/14 19:21:39 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain -- Default constructor called." << std::endl;
}

Brain::Brain(Brain &tocopy)
{
	*this = tocopy;
	std::cout << "Brain -- Copy constructor called." << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain -- Default destructor called." << std::endl;
}

Brain & Brain::operator = (Brain &toequalize)
{
	int a = 0;

	while (a < 100)
	{
		ideas[a] = toequalize.ideas[a];
		a++;
	}


//	ideas = toequalize.ideas;
	return(*this);
}


