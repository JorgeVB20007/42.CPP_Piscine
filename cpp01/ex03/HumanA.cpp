/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:11:14 by jvacaris          #+#    #+#             */
/*   Updated: 2022/06/29 21:22:37 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void HumanA::attack()
{
	if (_weapon.getType().length() <= 0)
		std::cout << _name << " attacks with the power of speech" << std::endl;
	else
		std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
	return ;
}

HumanA::HumanA(const std::string name, Weapon & weapon) : _name(name), _weapon(weapon)
{
	return;
}

HumanA::~HumanA()
{
	return ;
}
