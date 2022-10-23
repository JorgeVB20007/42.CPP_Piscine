/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:22:47 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/23 18:48:44 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#define NOTIFS 1
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;
		
	public:
		AMateria(std::string const & type);
		AMateria();
		AMateria(AMateria &tocopy);
		~AMateria();
		AMateria & operator = (AMateria &toequalize);

		std::string const & getType() const; //Returns the materia type

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif