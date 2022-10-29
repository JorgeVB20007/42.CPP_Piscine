/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rage.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:22:24 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/26 23:15:50 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rage.hpp"

Rage::Rage(): AMateria("rage")
{
	if (NOTIFS)
		std::cout << "Rage default constructor called." << std::endl;
}

Rage::Rage(Rage &tocopy): AMateria("rage")
{
	if (NOTIFS)
		std::cout << "Rage copy constructor called." << std::endl;
	*this = tocopy;
}

Rage::~Rage()
{
	if (NOTIFS)
		std::cout << "Rage default destructor called." << std::endl;
}

Rage & Rage::operator = (Rage &toequalize)
{
	if (NOTIFS)
		std::cout << "Rage assignation operator called." << std::endl;
	(void)toequalize;
	return (*this);
}

AMateria* Rage::clone() const
{
	AMateria* ret = new Rage;
	return (ret);
}

void Rage::use(ICharacter& target)
{
	std::cout << "* uses a rage spell against " << target.getName() << " *" << std::endl;
}
