/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:48:12 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/24 19:38:10 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private:
/*		std::string name;
		int hp;
		int egypts;
		int atkdmg;*/
	public:
		ScavTrap(std::string _name);
		virtual ~ScavTrap();
		void attack(std::string const & target);
		void guardGate();
};




#endif