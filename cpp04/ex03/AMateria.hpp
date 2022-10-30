/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:22:47 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/30 19:11:04 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "ICharacter.hpp"
#include "notifications.hpp"

class AMateria
{
	protected:
		std::string _type;
		
	public:
		explicit AMateria(std::string const & type);
		AMateria(AMateria &tocopy);
		virtual ~AMateria();
		AMateria & operator = (AMateria &toequalize);

		std::string const & getType() const; //Returns the materia type

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif