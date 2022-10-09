/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 22:50:09 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/09 21:59:00 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap();
		FragTrap(const FragTrap &tocopy);
		~FragTrap();
		FragTrap & operator = (const FragTrap &toequalize);
		void highFivesGuys(void);
		void attack(std::string const & target);
};



#endif
