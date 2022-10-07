/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:22:23 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/28 20:33:30 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap(): ClapTrap("_clap_name", 100, 50, 30), FragTrap("_clap_name"), ScavTrap("_clap_name")
{
	name = "";
	std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string _name): ClapTrap(_name + "_clap_name", 100, 50, 30), FragTrap(_name + "_clap_name"), ScavTrap(_name + "_clap_name")
{
	name = _name;
	std::cout << "DiamondTrap constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string _name, int _hp, int _egypts, int _atkdmg): ClapTrap(_name + "_clap_name", _hp, _egypts, _atkdmg), FragTrap(_name + "_clap_name"), ScavTrap(_name + "_clap_name")
{
	name = _name;
	std::cout << "DiamondTrap specific constructor called." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called." << std::endl;
}

DiamondTrap & DiamondTrap::operator = (DiamondTrap &toequalize)
{
	ClapTrap::hp= toequalize.hp;
	ClapTrap::egypts = toequalize.egypts;
	ClapTrap::atkdmg = toequalize.atkdmg;
	return(*this);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap My name is " << name << std::endl;
	std::cout << "DiamondTrap But my clap_name is " << ClapTrap::name << std::endl;
/*	std::cout << "-- More info --" << std::endl;
	std::cout << "- HP: " << hp << std::endl;
	std::cout << "- EP: " << egypts << std::endl;
	std::cout << "- ATK: " << atkdmg << std::endl;*/
}

