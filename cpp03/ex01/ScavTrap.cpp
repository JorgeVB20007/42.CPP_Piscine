/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:04:45 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/16 20:57:34 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string _name)
{
	name = _name;
	hp = 100;
	egypts = 50;
	atkdmg = 20;
	std::cout << "ScavTrap constructor called." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called." << std::endl;
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
