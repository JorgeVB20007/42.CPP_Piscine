/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:22:24 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/26 23:15:50 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	std::cout << "Ice default constructor called." << std::endl;
}

Ice::Ice(Ice &tocopy): AMateria("ice")
{
	std::cout << "Ice copy constructor called." << std::endl;
	*this = tocopy;
}

Ice::~Ice()
{
	std::cout << "Ice default destructor called." << std::endl;
}

Ice & Ice::operator = (Ice &toequalize)
{
	std::cout << "Ice assignation operator called." << std::endl;
	(void)toequalize;
	//? Unsure what to do here
	return (*this);
}

AMateria* Ice::clone() const
{
	AMateria* ret = new Ice;
	return (ret);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
