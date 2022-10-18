/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:03:32 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/17 21:05:38 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
	private:
		Brain *mind;
	public:
		Dog();
		Dog(Dog &tocopy);
		virtual ~Dog();
		Dog & operator = (Dog &toequalize);
		virtual void makeSound() const;
		void dog_think(int index, std::string newidea);
		std::string dog_recall(int index);
//		const std::string getType();
};

#endif