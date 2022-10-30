/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:03:34 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/30 19:40:21 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	std::cout << std::endl << "-- Creating a Dog on the Stack --" << std::endl;
	Dog puppy;
	(void)puppy;

	std::cout << std::endl << "-- Creating a Cat on the Heap --" << std::endl;
	Cat* kitten = new Cat;
	(void)kitten;
/*
	std::cout << std::endl << "-- Creating an Animal on the Stack (should not compile) --" << std::endl;
	Animal animal1;
	(void)animal1;

	std::cout << std::endl << "-- Creating an Animal on the Heap (should not compile) --" << std::endl;
	Animal* animal2 = new Animal;
	(void)animal2;
*/
	std::cout << std::endl << "-- Freeing the allocated Cat --" << std::endl;
	delete kitten;
/*
	std::cout << "-- Freeing the allocated Animal (should not compile) --" << std::endl;
	delete animal2;
*/
	std::cout << std::endl << "-- Done. Stack objects will be deleted now. --" << std::endl;
}
 