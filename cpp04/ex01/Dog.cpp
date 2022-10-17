/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:03:29 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/17 21:55:31 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	if (INFOS)
		std::cout << "Dog  --  Default constructor called." << std::endl;
	mind = new Brain();
	type = "Dog";
}

Dog::Dog(Dog &tocopy)
{
	if (INFOS)
		std::cout << "Dog  --  Copy constructor called." << std::endl;
	*this = tocopy;
}

Dog::~Dog()
{
	if (INFOS)
		std::cout << "Dog  --  Default destructor called." << std::endl;
	delete mind;
}

Dog & Dog::operator = (Dog &toequalize)
{
	if (INFOS)
		std::cout << "Dog  --  Assignation operator called." << std::endl;
	type = toequalize.type;
	mind = new Brain(*toequalize.mind);
	return(*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

void Dog::dog_think(int index, std::string newidea)
{
	mind->think(index, newidea);
}

std::string Dog::dog_recall(int index)
{
	return(mind->recall(index));
}
