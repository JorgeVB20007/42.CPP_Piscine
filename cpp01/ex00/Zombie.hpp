/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:56:13 by jvacaris          #+#    #+#             */
/*   Updated: 2022/06/11 21:05:37 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie(std::string name);
		~Zombie(void);
		void announce(void);

};

Zombie* newZombie(std::string name);
void randomChump( std::string name );

#endif