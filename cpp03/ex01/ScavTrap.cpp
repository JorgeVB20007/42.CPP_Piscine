/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:04:45 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/09 20:11:58 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("", 100, 50, 20)
{
	std::cout << "ScavTrap default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string _name): ClapTrap(_name, 100, 50, 20)
{
	std::cout << "ScavTrap constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &tocopy)
{
	std::cout << "ScavTrap copy constructor called." << std::endl;
	*this = tocopy;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called." << std::endl;
}

ScavTrap & ScavTrap::operator = (const ScavTrap &toequalize)
{
	ClapTrap::name = toequalize.name;
	ClapTrap::hp = toequalize.hp;
	ClapTrap::egypts = toequalize.egypts;
	ClapTrap::atkdmg = toequalize.atkdmg;
	return(*this);
}

void ScavTrap::attack(std::string const & target)
{
	if (hp > 0 && egypts > 0)
		std::cout << "ScavTrap " << name << " attacked " << target << ", causing " << atkdmg << " points of damage!" << std::endl;
	egypts--;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " has entered Gate keeper mode." << std::endl;
}


