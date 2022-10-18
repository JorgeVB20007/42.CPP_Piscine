/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:03:19 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/18 18:34:46 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{
	private:
		Brain *mind;
	public:
		Cat();
		Cat(Cat &tocopy);
		virtual ~Cat();
		Cat & operator = (Cat &toequalize);
		virtual void makeSound() const;
		void cat_think(int index, std::string newidea);
		std::string cat_recall(int index);
//		const std::string getType();
};

#endif