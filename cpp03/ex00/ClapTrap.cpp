/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:04:45 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/16 20:32:20 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string _name)
{
	name = _name;
	hp = 10;
	egypts = 10;
	atkdmg = 0;
	std::cout << "ClapTrap constructor called." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called." << std::endl;
}

void ClapTrap::attack(std::string const & target)
{
	if (hp > 0 && egypts > 0)
		std::cout << "ClapTrap " << name << " attacked " << target << ", causing " << atkdmg << " points of damage!" << std::endl;
	egypts--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " took " << amount << " points of damage" << std::endl;
	hp -= amount;
	if (hp <= 0)
		std::cout << "         " << name << " died." << std::endl;
	else
		std::cout << "         " << name << " has " << hp << " hp left." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	hp += amount;
	std::cout << "ClapTrap " << name << " got healed by " << amount << " hp" << std::endl;
	std::cout << "         " << name << " has " << hp << " hp left." << std::endl;
}
