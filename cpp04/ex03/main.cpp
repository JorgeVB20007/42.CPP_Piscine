/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:22:15 by jvacaris          #+#    #+#             */
/*   Updated: 2022/11/05 20:55:36 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Ice.hpp"
#include "Rage.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"


int main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		
		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);
		
		delete bob;
		delete me;
		delete src;

	}
	std::cout << std::endl << "  -----------  " << std::endl << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Rage());
		src->learnMateria(new Ice());
		Cure *cureptr = new Cure();
		src->learnMateria(cureptr);

		ICharacter* you = new Character("you");

		AMateria* tmp;
		tmp = src->createMateria("rage");
		you->equip(tmp);
		tmp = src->createMateria("ice");
		you->equip(tmp);
		tmp = src->createMateria("cure");
		you->equip(tmp);

		ICharacter* bob = new Character("bob");

		you->use(0, *bob);
		you->use(1, *bob);
		you->use(1, *bob);
		you->unequip(2);
		you->use(2, *bob);
		
		delete cureptr;
		delete bob;
		delete you;
		delete src;
	}
	return 0;
}