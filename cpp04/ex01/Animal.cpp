/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:03:14 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/11 21:24:32 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	type = "???";
	std::cout << "Animal - Default constructor called." << std::endl;
}

Animal::Animal(std::string _type)
{
	type = _type;
	std::cout << "Animal - Specific constructor called." << std::endl;
}

Animal::Animal(const Animal &tocopy)
{
	type = tocopy.type;
	*this = tocopy;
	std::cout << "Animal - Copy constructor called." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal - Default destructor called." << std::endl;
}

Animal & Animal::operator = (const Animal &toequalize)
{
	type = toequalize.type;
	return(*this);
}

void Animal::makeSound() const
{
	std::cout << "Umm... What was I supposed to say here?" << std::endl;
}

const std::string Animal::getType() const
{
	return(type);
}
