/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:58:36 by jvacaris          #+#    #+#             */
/*   Updated: 2022/06/14 22:11:02 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

void Weapon::setType(const std::string newType)
{
	_type = newType;
}

//// Might be wrong, as it's asking for a reference to the string
const std::string &Weapon::getType(void)
{
	const std::string &typeREF = _type;
	return (typeREF);
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
