/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 20:14:02 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/16 20:31:59 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap("Mario");

	clap.attack("Goomba");
	clap.takeDamage(3);
	clap.beRepaired(1);
	clap.attack("Bowser");
	clap.takeDamage(11);
	clap.attack("Bowser");
}