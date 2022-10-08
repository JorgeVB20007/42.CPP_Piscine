/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:48:12 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/08 19:57:03 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
		std::string name;
		int hp;
		int egypts;
		int atkdmg;
	public:
		ClapTrap();
		ClapTrap(std::string _name);
		ClapTrap(std::string _name, int _hp, int _egypts, int _atkdmg);
		ClapTrap(const ClapTrap &tocopy);
		~ClapTrap();
		ClapTrap & operator = (ClapTrap &toequalize);
		void attack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};




#endif