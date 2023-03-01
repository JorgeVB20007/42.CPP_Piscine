/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:29:01 by jvacaris          #+#    #+#             */
/*   Updated: 2023/03/01 21:52:57 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool is_valid_char(char a)
{
	if (isdigit(a) || a == '+' || a == '-' || a == '*' || a == '/' || a == ' ')
		return (true);
	return (false);
}

bool valid_input(std::string inpt)
{
	int i = 0;

	while (inpt[i])
	{
		if (!is_valid_char(inpt[i]))
			return (false);
		else if (isdigit(inpt[i]) && isdigit(inpt[i + 1]) && isdigit(inpt[i + 2]))
			return (false);
		else if (inpt[i] == ' ' && inpt[i + 1] == ' ')
			return (false);
		i++;
	}
	return (true);
}

//?   Use a LIST.
//?   Once you find a symbol, operate the previous two numbers

int RPN(std::string inpt)
{
	int idx = 0;
	if (!valid_input(inpt))
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	std::deque<char> the_queue;

	while (inpt[idx])
	{
		the_queue.push_back(inpt[idx++]);
		if (inpt[idx] == ' ')
			idx++;
	}


	return (0);
}