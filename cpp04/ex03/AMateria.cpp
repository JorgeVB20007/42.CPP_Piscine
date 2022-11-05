/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:27:12 by jvacaris          #+#    #+#             */
/*   Updated: 2022/11/05 18:45:03 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	_type = "???";
}

AMateria::AMateria(std::string const & type)
{
	if (NOTIFS)
		std::cout << "AMateria constructor called." << std::endl;
	_type = type;
}

AMateria::AMateria(AMateria &tocopy)
{
	if (NOTIFS)
		std::cout << "AMateria copy constructor called." << std::endl;
	*this = tocopy;
}

AMateria::~AMateria()
{
	if (NOTIFS)
		std::cout << "AMateria default destructor called." << std::endl;
}

AMateria & AMateria::operator = (AMateria &toequalize)
{
	if (NOTIFS)
		std::cout << "AMateria assignation operator called." << std::endl;
	_type = toequalize._type;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* confuses " << target.getName() << " *" << std::endl;
}
