/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:22:24 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/24 20:40:55 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "Ice default constructor called." << std::endl;
}

Ice::Ice(Ice &tocopy)
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
