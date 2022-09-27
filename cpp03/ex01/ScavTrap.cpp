/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:04:45 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/27 21:57:39 by jvacaris         ###   ########.fr       */
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


