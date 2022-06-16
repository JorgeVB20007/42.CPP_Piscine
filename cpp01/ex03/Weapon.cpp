/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:58:36 by jvacaris          #+#    #+#             */
/*   Updated: 2022/06/16 19:03:39 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

void Weapon::setType(const std::string newType)
{
	_type = newType;
}

//// Might be wrong, as it's asking for a reference to the string
const std::string Weapon::getType(void)
{
	return (_type);
}

Weapon::Weapon()
{
	return ;
}

Weapon::Weapon(std::string type)
{
	_type = type;
	return ;
}

Weapon::~Weapon()
{
	return ;
}
