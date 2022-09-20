/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:48:12 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/20 22:00:39 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, ScavTrap
{
	private:

	public:
		DiamondTrap();
		DiamondTrap(std::string _name);
		DiamondTrap(std::string _name, int _hp, int _egypts, int _atkdmg);
		~DiamondTrap();
		void attack(std::string const & target);
////		void takeDamage(unsigned int amount);
////		void beRepaired(unsigned int amount);
};




#endif