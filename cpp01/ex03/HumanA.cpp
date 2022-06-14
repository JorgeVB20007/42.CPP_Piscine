/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:11:14 by jvacaris          #+#    #+#             */
/*   Updated: 2022/06/14 22:31:25 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void HumanA::attack()
{
	std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
	return ;
}

HumanA::HumanA(const std::string name, Weapon weapon)
{
	_name = name;
	_weapon = weapon;
}

HumanA::~HumanA()
{
	return ;
}
