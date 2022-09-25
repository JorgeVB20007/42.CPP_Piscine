/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:22:23 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/26 00:23:47 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*
DiamondTrap(): ClapTrap()
{

}*/

DiamondTrap::DiamondTrap(std::string _name): ClapTrap(_name + "_clap_name", 100, 50, 30), FragTrap(_name + "_clap_name"), ScavTrap(_name + "_clap_name")
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
	std::cout << "DiamondTrap destructor called." << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap My name is " << name << std::endl;
	std::cout << "DiamondTrap But my clap_name is " << get_name() << std::endl;
	std::cout << "-- More info (delete later) --" << std::endl;
	std::cout << "- HP: " << get_hp() << std::endl;
	std::cout << "- EP: " << get_egypts() << std::endl;
	std::cout << "- ATK: " << get_atkdmg() << std::endl;
}

