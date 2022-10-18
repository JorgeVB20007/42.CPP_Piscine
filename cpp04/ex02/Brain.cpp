/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:38:48 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/17 21:56:41 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	if (INFOS)
		std::cout << "Brain -- Default constructor called." << std::endl;
}

Brain::Brain(Brain &tocopy)
{
	if (INFOS)
		std::cout << "Brain -- Copy constructor called." << std::endl;
	int a = 0;

	while (a < 100)
	{
		ideas[a] = tocopy.ideas[a];
		a++;
	}
	*this = tocopy;
}

Brain::~Brain()
{
	if (INFOS)
		std::cout << "Brain -- Default destructor called." << std::endl;
}

Brain & Brain::operator = (Brain &toequalize)
{
	if (INFOS)
		std::cout << "Brain -- Assignation operation called." << std::endl;
	int a = 0;

	while (a < 100)
	{
		ideas[a] = toequalize.ideas[a];
		a++;
	}


//	ideas = toequalize.ideas;
	return(*this);
}

void Brain::think(int index, std::string newidea)
{
	ideas[index] = newidea;
}

std::string Brain::recall(int index)
{
	return(ideas[index]);
}
