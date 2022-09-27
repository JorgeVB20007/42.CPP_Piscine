/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:04:45 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/27 21:40:55 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap()
{
	name = "";
	hp = 10;
	egypts = 10;
	atkdmg = 0;
	std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string _name)
{
	name = _name;
	hp = 10;
	egypts = 10;
	atkdmg = 0;
	std::cout << "ClapTrap constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string _name, int _hp, int _egypts, int _atkdmg)
{
	name = _name;
	hp = _hp;
	egypts = _egypts;
	atkdmg = _atkdmg;
	std::cout << "ClapTrap other constructor called." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called." << std::endl;
}

ClapTrap & ClapTrap::operator = (ClapTrap &toequalize)
{
	hp = toequalize.get_hp();
	egypts = toequalize.get_egypts();
	atkdmg = toequalize.get_atkdmg();
	return(*this);
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
	hp = 0;
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

std::string ClapTrap::get_name()
{
	return (name);
}

int ClapTrap::get_hp()
{
	return (hp);
}

int ClapTrap::get_egypts()
{
	return (egypts);
}

int ClapTrap::get_atkdmg()
{
	return (atkdmg);
}

void ClapTrap::set_hp(int value)
{
	hp = value;
}

void ClapTrap::set_egypts(int value)
{
	egypts = value;
}

void ClapTrap::set_atkdmg(int value)
{
	atkdmg = value;
}
