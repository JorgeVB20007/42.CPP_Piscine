/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:22:23 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/24 19:31:13 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*
DiamondTrap(): ClapTrap()
{

}*/

DiamondTrap::DiamondTrap(std::string _name): ClapTrap(_name + "_clap_name", 100, 100, 30)
{
	name = _name;
	std::cout << "DiamondTrap constructor called." << std::endl;
}
/*
DiamondTrap::DiamondTrap(std::string _name, int _hp, int _egypts, int _atkdmg)
{

}
*/
DiamondTrap::~DiamondTrap()
{
	
}
/*
void attack(std::string const & target)
{
	if (ClapTrap::get_hp() > 0 && ClapTrap::get_egypts() > 0)
		std::cout << "FragTrap " << get_name() << " attacked " << target << ", causing " << get_atkdmg() << " points of damage!" << std::endl;
	set_egypts(get_egypts() - 1);
}
*/