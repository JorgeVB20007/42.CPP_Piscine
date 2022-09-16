/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 20:14:02 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/16 21:07:40 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
//	ClapTrap clap("Mario");
	ScavTrap scav("Luigi");
/*
	clap.attack("Goomba");
	clap.takeDamage(3);
	clap.beRepaired(1);
	clap.attack("Bowser");
	clap.takeDamage(11);
	clap.attack("Bowser");
*/
	scav.attack("Koopa");
	scav.takeDamage(15);
}