/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:48:12 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/16 20:44:10 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		std::string name;
		int hp;
		int egypts;
		int atkdmg;
		void guardGate();
	public:
		ScavTrap(std::string _name);
		~ScavTrap();
		void attack(std::string const & target);
};




#endif