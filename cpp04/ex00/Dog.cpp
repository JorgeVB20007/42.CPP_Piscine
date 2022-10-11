/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:03:29 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/11 20:37:10 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog - Default constructor called.";
}

Dog::~Dog()
{
	std::cout << "Dog - Default destructor called.";
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
/*
const std::string Dog::getType()
{
	return("Dog");
}*/
