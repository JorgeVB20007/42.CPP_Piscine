/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:51:30 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/25 23:05:22 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	if (NOTIFS)
		std::cout << "Character default constructor called." << std::endl;
	name = "???";
	int a = 0;
	while (a < 4)
		slots[a++] = NULL;
}

Character::Character(std::string _name)
{
	if (NOTIFS)
		std::cout << "Character constructor called." << std::endl;
	name = _name;
	int a = 0;
	while (a < 4)
		slots[a++] = NULL;
}

Character::Character(Character &tocopy)
{
	if (NOTIFS)
		std::cout << "Character copy constructor called." << std::endl;
	(*this) = tocopy;
}

Character::~Character()
{
	if (NOTIFS)
		std::cout << "Character default destructor called." << std::endl;
}

Character & Character::operator = (Character &toequalize)
{
	if (NOTIFS)
		std::cout << "Character assignation operator called." << std::endl;
	name = toequalize.getName();
	int a = 0;
	while (a < 4)
	{
		slots[a] = toequalize.slots[a];
		a++;
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (name);
}

void Character::equip(AMateria* m)
{
	int a = 0;

	while (a < 4)
	{
		if (!slots[a])
		{
			slots[a] = m;
			std::cout << m->getType() << " equipped on slot " << a << std::endl;
			a = 41;
		}
		a++;
	}
	if (a != 42)
		std::cout << name << "'s inventory is full!" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 4 || idx < 0)
	{
		std::cout << "Index " << idx << " is not between 0 and 3." << std::endl;
		return ;
	}
	std::cout << slots[idx]->getType() << " unequipped." << std::endl;
	slots[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	slots[idx]->use(target);
}
