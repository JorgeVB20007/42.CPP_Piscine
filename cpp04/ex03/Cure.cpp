/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:22:28 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/29 19:34:16 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	if (NOTIFS)
		std::cout << "Cure default constructor called." << std::endl;
}

Cure::Cure(Cure &tocopy): AMateria("cure")
{
	if (NOTIFS)
		std::cout << "Cure copy constructor called." << std::endl;
	*this = tocopy;
}

Cure::~Cure()
{
	if (NOTIFS)
		std::cout << "Cure default destructor called." << std::endl;
}

Cure & Cure::operator = (Cure &toequalize)
{
	if (NOTIFS)
		std::cout << "Cure assignation operator called." << std::endl;
	(void)toequalize;
	return (*this);
}

AMateria* Cure::clone() const
{
	AMateria* ret = new Cure;
	return (ret);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
