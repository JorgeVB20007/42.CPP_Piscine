/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:03:17 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/14 18:57:48 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	mind = new Brain();
	type = "Cat";
	std::cout << "Cat  --  Default constructor called." << std::endl;
}

Cat::Cat(Cat &tocopy)
{
	*this = tocopy;
	mind = new Brain(*tocopy.mind);
	std::cout << "Cat  --  Copy constructor called." << std::endl;
}

Cat::~Cat()
{
	delete mind;
	std::cout << "Cat  --  Default destructor called." << std::endl;
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