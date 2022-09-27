/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:48:12 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/27 21:40:11 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string name;
		int hp;
		int egypts;
		int atkdmg;
	public:
		ClapTrap();
		ClapTrap(std::string _name);
		ClapTrap(std::string _name, int _hp, int _egypts, int _atkdmg);
		~ClapTrap();
		ClapTrap & operator = (ClapTrap &toequalize);
		void attack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		int get_hp();
		int get_egypts();
		int get_atkdmg();
		std::string get_name();
		void set_hp(int value);
		void set_egypts(int value);
		void set_atkdmg(int value);
};




#endif