/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:08:20 by jvacaris          #+#    #+#             */
/*   Updated: 2022/06/12 20:26:40 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie (std::string name)
{
	Zombie::_name = name;
}

Zombie::~Zombie()
{
	std::cout << _name << " tried to swim in lava." << std::endl;
}

void Zombie::announce( void )
{
	std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
