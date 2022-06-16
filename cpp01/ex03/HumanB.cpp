/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:11:19 by jvacaris          #+#    #+#             */
/*   Updated: 2022/06/15 20:44:48 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

void HumanB::attack()
{
	if (_weapon->getType().length() > 0)
		std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " attacks with the power of speech" << std::endl;
	return ;
}

void HumanB::setWeapon(Weapon &newweapon)
{
	_weapon = &newweapon;
}

HumanB::HumanB(std::string name)
{
	_name = name;
	return ;
}

HumanB::~HumanB()
{
	return ;
}
