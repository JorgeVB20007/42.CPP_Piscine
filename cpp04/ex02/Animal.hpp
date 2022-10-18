/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:03:11 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/18 17:55:40 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

#define INFOS 1

class Animal
{
	protected:
		std::string type;
		Animal();
		Animal(std::string _type);
		Animal(const Animal &tocopy);
		virtual ~Animal();
		Animal & operator = (const Animal &toequalize);
		virtual void makeSound() const;
		const std::string getType() const;
};

#endif