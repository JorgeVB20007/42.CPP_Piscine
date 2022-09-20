/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:22:23 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/20 21:59:44 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*
DiamondTrap(): ClapTrap()
{

}*/

DiamondTrap(std::string _name): ClapTrap(_name, 100, 100, 30)
{
	std::cout << "DiamondTrap constructor called." << std::endl;
}

DiamondTrap(std::string _name, int _hp, int _egypts, int _atkdmg)
{

}

~DiamondTrap()
{
	
}

void attack(std::string const & target)
{
	if (get_hp() > 0 && get_egypts() > 0)
		std::cout << "FragTrap " << get_name() << " attacked " << target << ", causing " << get_atkdmg() << " points of damage!" << std::endl;
	set_egypts(get_egypts() - 1);
}
