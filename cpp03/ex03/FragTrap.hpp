/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 22:50:09 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/09 17:16:38 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(std::string);
		FragTrap();
		FragTrap(const FragTrap &tocopy);
		~FragTrap();
		FragTrap & operator = (const FragTrap &toequalize);
		void highFivesGuys(void);
		void attack(std::string const & target);
};



#endif
