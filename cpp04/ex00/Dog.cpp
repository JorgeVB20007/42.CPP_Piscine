/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:03:29 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/14 18:34:49 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog  --  Default constructor called." << std::endl;
}

Dog::Dog(Dog &tocopy)
{
	*this = tocopy;
	std::cout << "Dog  --  Copy constructor called." << std::endl;
}

Dog::~Dog()
{
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