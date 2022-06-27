/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:39:13 by jvacaris          #+#    #+#             */
/*   Updated: 2022/06/27 21:21:40 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen()
{
	return ;
}

Karen::~Karen()
{
	return ;
}

void Karen::debug( void )
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl << std::endl;
	return ;
}

void Karen::info( void )
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl << std::endl;
	return ;
}

void Karen::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl << std::endl;
	return ;
}

void Karen::error( void )
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl << std::endl;
	return ;
}

void Karen::complain( std::string level )
{
	std::string lvl_list[4] = 
	{
		"debug",
		"info",
		"warning",
		"error"
	};
	int a = 0;
	while (a < 4)
	{
		if (level == lvl_list[a])
		{
			switch (a)
			{
				case(0):
				{
					std::cout << "[ DEBUG ]" << std::endl;
					this->debug();
				}
				case(1):
				{
					std::cout << "[ INFO ]" << std::endl;
					this->info();
				}
				case(2):
				{
					std::cout << "[ WARNING ]" << std::endl;
					this->warning();
				}
				case(3):
				{
					std::cout << "[ ERROR ]" << std::endl;
					this->error();
					a = 41;
					break;
				}
			}
		}
		a++;
	}
	if (a != 42)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	return ;
}
