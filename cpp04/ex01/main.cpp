/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:03:34 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/17 22:04:49 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

static void print_brains(Dog *one, Dog *two, Dog *three)
{
	std::cout << "  .-main-.-copy-.-cpy2-." << std::endl;
	std::cout << " 1| " << one->dog_recall(0) << " | " << two->dog_recall(0) << " | " << three->dog_recall(0) << " | " << std::endl;
	std::cout << " 2| " << one->dog_recall(1) << " | " << two->dog_recall(1) << " | " << three->dog_recall(1) << " | " << std::endl;
	std::cout << " 3| " << one->dog_recall(2) << " | " << two->dog_recall(2) << " | " << three->dog_recall(2) << " | " << std::endl;
	std::cout << "  '------'------'------'" << std::endl;
}

int main()
{
	std::cout << std::endl << "-- Subject's test --" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	delete j;//should not create a leak
    delete i;

	const Animal* zoo[10];
	int a = 0;

	std::cout << std::endl << "-- Array of Animals test --" << std::endl;
	std::cout << "- Constructors -" << std::endl;
	while (a < 5)
	{
		std::cout << "\033[0;3" << a+1 << "m"; //? Just some colors for the constructors. Can be removed.
		zoo[a++] = new Cat();
	}
	while (a < 10)
	{
		std::cout << "\033[0;9" << a-4 << "m"; //? Just some colors for the constructors. Can be removed.
		zoo[a++] = new Dog();
	}
	std::cout << "\033[0m"; //? Just some colors for the constructors. Can be removed.
	std::cout << std::endl << "- Destructors -" << std::endl;
	while (--a >= 0)
	{
		if (a > 4) //? Removable
			std::cout << "\033[0;9" << a-4 << "m"; //? Just some colors for the constructors. Can be removed.
		else //? Removable
			std::cout << "\033[0;3" << a+1 << "m"; //? Just some colors for the constructors. Can be removed.
		delete zoo[a];
	}
	std::cout << "\033[0m"; //? Just some colors for the constructors. Can be removed.

	std::cout << std::endl << "-- Deep copies proof --" << std::endl;
	Dog main;
	main.dog_think(0, "Bone");
	main.dog_think(1, "Ball");
	main.dog_think(2, "Bark");
	Dog copy(main);
	Dog cpy2;
	cpy2 = main;

	std::cout << "\033[0;33mMain dog with ideas \"Bone\", \"Ball\" and \"Bark\" and its 2 copies:\033[0m" << std::endl;
	print_brains(&main, &copy, &cpy2);
	main.dog_think(0, "Walk");
	main.dog_think(2, "Run!");
	std::cout << "\033[0;33mChanged main dog's 1st and 3rd ideas to \"Walk\" and \"Run!\":\033[0m" << std::endl;
	print_brains(&main, &copy, &cpy2);
	copy.dog_think(1, "Roll");
	cpy2.dog_think(1, "Snif");
	std::cout << "\033[0;33mChanged copy and cpy2's 2nd ideas to \"Roll\" and \"Snif\":\033[0m" << std::endl;
	print_brains(&main, &copy, &cpy2);

//	system("leaks fauna");
}
 