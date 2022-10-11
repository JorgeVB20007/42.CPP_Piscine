/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:03:17 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/11 20:37:05 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat - Default constructor called.";
}

Cat::~Cat()
{
	std::cout << "Cat - Default destructor called.";
}

Cat & Cat::operator = (Cat &toequalize)
{
	type = toequalize.type;
	return(*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
/*
const std::string Cat::getType()
{
	return("Cat");
}
*/