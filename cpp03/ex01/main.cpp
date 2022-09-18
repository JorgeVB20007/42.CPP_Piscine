/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 20:14:02 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/18 21:50:41 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ClapTrap clap("\033[0;31mMario\033[0m");	//? "Mario" & "Luigi", but colorful.
	ScavTrap scav("\033[0;32mLuigi\033[0m");

	clap.attack("Goomba");
	clap.takeDamage(3);
	clap.beRepaired(1);
	clap.attack("Bowser");
	clap.takeDamage(11);
	clap.attack("Bowser");

	scav.attack("Koopa");
	scav.takeDamage(15);
	scav.guardGate();
	scav.takeDamage(95);
	scav.beRepaired(1);
}