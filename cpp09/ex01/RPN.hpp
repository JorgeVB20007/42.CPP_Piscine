/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:28:59 by jvacaris          #+#    #+#             */
/*   Updated: 2023/03/08 19:37:41 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <algorithm>
#include <list>

#define NOTIFS 0

//*	Shows errors with a more specific message instead of the subject's example.
#define SPECIFIC_ERRORS 0

//*	Allows negative numbers to be given as input (char '-' followed by a digit).
//!		Might break cases such as "42-3+" if there's no clarifying spaces ' '.
#define ALLOW_NEGATIVE_INPUT 0

class ft_item
{
	private:
		int value;
		bool is_sign;
	public:
		ft_item();
		ft_item(char c);
		ft_item(int n);
		ft_item(const ft_item &tocopy);
		ft_item & operator = (const ft_item &toequalize);
		~ft_item();
		bool &get_is_sign();
		int &get_value();

		class GenericError: public std::exception
		{
			public:
				const char *what() const throw()
				{
					if (SPECIFIC_ERRORS)
						return("Error: Attempted to operate between less than 2 digits.");
					else
						return("Error");
				}
		};
};

int RPN(std::string inpt);


#endif
