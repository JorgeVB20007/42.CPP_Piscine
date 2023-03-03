/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:28:59 by jvacaris          #+#    #+#             */
/*   Updated: 2023/03/03 23:02:37 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <list>

#define NOTIFS 0

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
};

bool valid_input(std::string inpt);
int RPN(std::string inpt);


