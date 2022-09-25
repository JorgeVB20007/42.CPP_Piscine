/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 20:14:02 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/26 00:31:17 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	// ClapTrap clap("\033[0;31mMario\033[0m");
	// ScavTrap scav("\033[0;32mLuigi\033[0m");	//? "Mario", "Luigi" & "Wario", but colorful.
	// FragTrap frag("\033[0;33mWario\033[0m");
	DiamondTrap diamond("\033[0;95mPeach\033[0m");

	// clap.attack("Goomba");
	// clap.takeDamage(3);
	// clap.beRepaired(1);
	// clap.attack("Bowser");
	// clap.takeDamage(11);
	// clap.attack("Bowser");

	// scav.attack("Koopa");
	// scav.takeDamage(15);
	// scav.guardGate();
	// scav.takeDamage(95);
	// scav.beRepaired(1);

	// frag.attack("Bob-omb");
	// frag.takeDamage(40);
	// frag.beRepaired(5);
	// frag.highFivesGuys();
	
	diamond.attack("Cheep-Cheep");
	diamond.takeDamage(20);
	diamond.beRepaired(5);
	diamond.whoAmI();
	diamond.guardGate();
	diamond.highFivesGuys();
	diamond.attack("Bowsy");
}