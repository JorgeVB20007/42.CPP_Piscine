/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 22:50:12 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/24 21:09:14 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string _name): ClapTrap(_name, 100, 100, 30)
{
	std::cout << "FragTrap constructor called." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap High-five anyone? :D" << std::endl;
}

void FragTrap::attack(std::string const & target)
{
	if (get_hp() > 0 && get_egypts() > 0)
		std::cout << "FragTrap " << get_name() << " attacked " << target << ", causing " << get_atkdmg() << " points of damage!" << std::endl;
	set_egypts(get_egypts() - 1);
}


void FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "FragTrap " << get_name() << " took " << amount << " points of damage" << std::endl;
	set_hp(get_hp() - amount);
	if (get_hp() <= 0)
		std::cout << "         " << get_name() << " died." << std::endl;
	else
		std::cout << "         " << get_name() << " has " << get_hp() << " HP left." << std::endl;
	set_hp(0);
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (get_hp() > 0)
		std::cout << "FragTrap " << get_name() << " got healed by " << amount << " HP" << std::endl;
	else
		std::cout << "FragTrap " << get_name() << " revived with " << amount << " HP" << std::endl;
	set_hp(get_hp() + amount);
	std::cout << "         " << get_name() << " has " << get_hp() << " HP left." << std::endl;
}
