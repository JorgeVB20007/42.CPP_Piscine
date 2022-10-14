/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:03:29 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/14 18:57:54 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	mind = new Brain();
	type = "Dog";
	std::cout << "Dog  --  Default constructor called." << std::endl;
}

Dog::Dog(Dog &tocopy)
{
	*this = tocopy;
	mind = new Brain(*tocopy.mind);
	std::cout << "Dog  --  Copy constructor called." << std::endl;
}

Dog::~Dog()
{
	delete mind;
	std::cout << "Dog  --  Default destructor called." << std::endl;
}

Dog & Dog::operator = (Dog &toequalize)
{
	type = toequalize.type;
	return(*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}