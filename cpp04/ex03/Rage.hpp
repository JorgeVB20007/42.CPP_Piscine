/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rage.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:22:47 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/26 23:14:30 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAGE_HPP
# define RAGE_HPP

#include "AMateria.hpp"

class Rage: public AMateria
{
	public:
		Rage();
		Rage(Rage &tocopy);
		~Rage();
		Rage & operator = (Rage &toequalize);
		virtual AMateria* clone() const;

		virtual void use(ICharacter& target);
};

#endif