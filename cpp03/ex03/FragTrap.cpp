/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 22:50:12 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/28 20:17:17 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("", 100, 100, 30)
{
	std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string _name): ClapTrap(_name, 100, 100, 30)
{
	std::cout << "FragTrap constructor called." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called." << std::endl;
}

FragTrap & FragTrap::operator = (FragTrap &toequalize)
{
	ClapTrap::hp = toequalize.hp;
	ClapTrap::egypts = toequalize.egypts;
	ClapTrap::atkdmg = toequalize.atkdmg;
	return(*this);
}
	
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap High-five anyone? :D" << std::endl;
}

void FragTrap::attack(std::string const & target)
{
	if (hp > 0 && egypts > 0)
		std::cout << "FragTrap " << name << " attacked " << target << ", causing " << atkdmg << " points of damage!" << std::endl;
	egypts--;
}
