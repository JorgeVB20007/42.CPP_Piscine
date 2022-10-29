/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:53:20 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/29 19:38:10 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

void MateriaSource::learnMateria(AMateria *tolearn)
{
	int a = 0;

	while (a < 4)
	{
		if (!materias[a])
		{
			materias[a] = tolearn;
			std::cout << tolearn->getType() << " learned and equipped on slot " << a << std::endl;
			a = 41;
		}
		a++;
	}
	if (a != 42)
		std::cout << "Inventory is full!" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type_search)
{
	int a = 0;
	AMateria *res = NULL;

	while (a < 4)
	{
		if (materias[a] && type_search == materias[a]->getType())
		{
			res = materias[a]->clone();
			return (res);
		}
		a++;
	}
	std::cout << "Error: Materia " << type_search << " was not found." << std::endl;
	return (NULL);
}

MateriaSource::MateriaSource()
{
	if (NOTIFS)
		std::cout << "MateriaSource default constructor called." << std::endl;
	int a = 0;
	while (a < 4)
		materias[a++] = NULL;
}

MateriaSource::MateriaSource(MateriaSource &tocopy)
{
	if (NOTIFS)
		std::cout << "MateriaSource copy constructor called." << std::endl;
	int a = 0;
	while (a < 4)
	{
		materias[a] = tocopy.materias[a];
		a++;
	}
}

MateriaSource::~MateriaSource()
{
	if (NOTIFS)
		std::cout << "MateriaSource default destructor called." << std::endl;
}

MateriaSource & MateriaSource::operator = (MateriaSource &toequalize)
{
	if (NOTIFS)
		std::cout << "MateriaSource assignation operator called." << std::endl;
	int a = 0;

	while (a < 4)
	{
		materias[a] = toequalize.materias[a];
		a++;
	}
	return (*this);
}
