/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:04:45 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/28 15:20:24 by jvacaris         ###   ########.fr       */
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

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called." << std::endl;
}

ScavTrap & ScavTrap::operator = (ScavTrap &toequalize)
{
	ClapTrap::set_hp(toequalize.get_hp());
	ClapTrap::set_egypts(toequalize.get_egypts());
	ClapTrap::set_atkdmg(toequalize.get_atkdmg());
	return(*this);
}

void ScavTrap::attack(std::string const & target)
{
	if (get_hp() > 0 && get_egypts() > 0)
		std::cout << "ScavTrap " << get_name() << " attacked " << target << ", causing " << get_atkdmg() << " points of damage!" << std::endl;
	set_egypts(get_egypts() - 1);
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << get_name() << " has entered Gate keeper mode." << std::endl;
}


