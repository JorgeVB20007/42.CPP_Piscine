/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:26:49 by jvacaris          #+#    #+#             */
/*   Updated: 2022/06/16 20:51:31 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		Weapon *_weapon;
		std::string _name;
	public:
		HumanB(const std::string name);
		~HumanB();
		void setWeapon(Weapon &newweapon);
		void attack();
};

#endif