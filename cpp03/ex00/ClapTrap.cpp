/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:04:45 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/18 21:58:18 by jvacaris         ###   ########.fr       */
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
	{	
		std::cout << "ClapTrap " << name << " attacked " << target << ", causing " << atkdmg << " points of damage!" << std::endl;
		egypts--;
	}	
	else if (hp <= 0)
		std::cout << "ClapTrap " << name << " was previously diagnosed with death and is incapable of attacking :/" << std::endl;
	else
		std::cout << "ClapTrap " << name << " is out of energy." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " took " << amount << " points of damage" << std::endl;
	hp -= amount;
	if (hp <= 0)
		std::cout << "         " << name << " died." << std::endl;
	else
		std::cout << "         " << name << " has " << hp << " HP left." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hp > 0)
		std::cout << "ClapTrap " << name << " got healed by " << amount << " HP" << std::endl;
	else
		std::cout << "ClapTrap " << name << " revived with " << amount << " HP" << std::endl;
	hp += amount;
	std::cout << "         " << name << " has " << hp << " HP left." << std::endl;
}
