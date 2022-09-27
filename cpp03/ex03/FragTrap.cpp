/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 22:50:12 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/27 21:28:54 by jvacaris         ###   ########.fr       */
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
	ClapTrap::set_hp(toequalize.get_hp());
	ClapTrap::set_egypts(toequalize.get_egypts());
	ClapTrap::set_atkdmg(toequalize.get_atkdmg());
	return(*this);
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
