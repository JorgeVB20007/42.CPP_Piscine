/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:03:17 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/18 18:15:38 by jvacaris         ###   ########.fr       */
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
	mind = NULL;
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
	if (mind != NULL)
		delete mind;
	mind = new Brain(*toequalize.mind);
	return(*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}

void Cat::cat_think(int index, std::string newidea)
{
	mind->think(index, newidea);
}

std::string Cat::cat_recall(int index)
{
	return(mind->recall(index));
}
