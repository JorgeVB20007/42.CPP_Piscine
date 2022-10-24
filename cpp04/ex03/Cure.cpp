/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:22:28 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/24 20:40:00 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	std::cout << "Cure default constructor called." << std::endl;
}

Cure::Cure(Cure &tocopy)
{
	std::cout << "Cure copy constructor called." << std::endl;
	*this = tocopy;
}

Cure::~Cure()
{
	std::cout << "Cure default destructor called." << std::endl;
}

Cure & Cure::operator = (Cure &toequalize)
{
	std::cout << "Cure assignation operator called." << std::endl;
	(void)toequalize;
	//? Unsure what to do here
	return (*this);
}

AMateria* Cure::clone() const
{
	AMateria* ret = new Cure;
	return (ret);
}
