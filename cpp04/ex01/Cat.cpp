/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:03:17 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/17 21:55:04 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	if (INFOS)
		std::cout << "Cat  --  Default constructor called." << std::endl;
	mind = new Brain();
	type = "Cat";
}

Cat::Cat(Cat &tocopy)
{
	if (INFOS)
		std::cout << "Cat  --  Copy constructor called." << std::endl;
	*this = tocopy;
}

Cat::~Cat()
{
	if (INFOS)
		std::cout << "Cat  --  Default destructor called." << std::endl;
	delete mind;
}

Cat & Cat::operator = (Cat &toequalize)
{
	if (INFOS)
		std::cout << "Cat  --  Assignation operator called." << std::endl;
	type = toequalize.type;
	mind = new Brain(*toequalize.mind);
	return(*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}