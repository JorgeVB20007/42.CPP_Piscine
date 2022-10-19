/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:03:14 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/19 21:48:30 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "???";
	std::cout << "WrongAnimal - Default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(std::string _type)
{
	type = _type;
	std::cout << "WrongAnimal - Specific constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &tocopy)
{
	type = tocopy.type;
	*this = tocopy;
	std::cout << "WrongAnimal - Copy constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal - Default destructor called." << std::endl;
}

WrongAnimal & WrongAnimal::operator = (const WrongAnimal &toequalize)
{
	type = toequalize.type;
	return(*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "Umm... What was I supposed to wrongly say here?" << std::endl;
}

const std::string WrongAnimal::getType() const
{
	return(type);
}
