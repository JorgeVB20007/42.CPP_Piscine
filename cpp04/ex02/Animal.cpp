/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:03:14 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/17 21:54:33 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	if (INFOS)
		std::cout << "Animal - Default constructor called." << std::endl;
	type = "???";
}

Animal::Animal(std::string _type)
{
	if (INFOS)
		std::cout << "Animal - Specific constructor called." << std::endl;
	type = _type;
}

Animal::Animal(const Animal &tocopy)
{
	if (INFOS)
		std::cout << "Animal - Copy constructor called." << std::endl;
	type = tocopy.type;
	*this = tocopy;
}

Animal::~Animal()
{
	if (INFOS)
		std::cout << "Animal - Default destructor called." << std::endl;
}

Animal & Animal::operator = (const Animal &toequalize)
{
	if (INFOS)
		std::cout << "Animal - Assignation operator called." << std::endl;
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
