/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:53:20 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/24 20:59:36 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

virtual void learnMateria(AMateria *tolearn)
{
	int a = 0;

	while (a < 4)
	{
		if (!materias[a])
		{
			materias[a] = tolearn;
			std::cout << tolearn.getType() << " equipped on slot " << a << std::endl;
			a = 41;
		}
		a++;
	}
	if (a != 42)
		std::cout << name << "'s inventory is full!" << std::endl;
}

virtual AMateria *createMateria(std::string const &)
{
	/*
?	createMateria(std::string const &) will return a new Materia, which will be a
?	copy of the Materia (previously learned by the Source) which type equals the parameter.
?	Returns 0 if the type is unknown.
	*/
}

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called." << std::endl;
	int a = 0;
	while (a < 4)
		materias[a++] = NULL;
}

MateriaSource::MateriaSource(MateriaSource &tocopy)
{
	std::cout << "MateriaSource copy constructor called." << std::endl;
	int a = 0;
	while (a < 4)
		materias[a] = tocopy.materias[a++];
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource default destructor called." << std::endl;

}

MateriaSource & MateriaSource::operator = (MateriaSource &toequalize)
{
	std::cout << "MateriaSource assignation operator called." << std::endl;

}
