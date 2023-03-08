/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:29:01 by jvacaris          #+#    #+#             */
/*   Updated: 2023/03/04 19:55:36 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

ft_item::ft_item()
{
	if (NOTIFS)
		std::cout << "ft_item Default constructor called." << std::endl;
	value = 0;
	is_sign = false;
}

ft_item::ft_item(char c)
{
	if (NOTIFS)
		std::cout << "ft_item char constructor called." << std::endl;
	value = (int)c;
	is_sign = true;
}

ft_item::ft_item(int n)
{
	if (NOTIFS)
		std::cout << "ft_item int constructor called." << std::endl;
	value = n;
	is_sign = false;
}

ft_item::ft_item(const ft_item &tocopy)
{
	*this = tocopy;
}

ft_item & ft_item::operator = (const ft_item &toequalize)
{
	value = toequalize.value;
	is_sign = toequalize.is_sign;
	return (*this);
}

ft_item::~ft_item()
{
	if (NOTIFS)
		std::cout << "ft_item destructor called." << std::endl;
}

bool &ft_item::get_is_sign()
{
	return (is_sign);
}

int &ft_item::get_value()
{
	return (value);
}

static bool is_valid_char(char a)
{
	if (isdigit(a) || a == '+' || a == '-' || a == '*' || a == '/' || a == ' ')
		return (true);
	return (false);
}

static bool is_operand(char a)
{
	if (a == '+' || a == '-' || a == '*' || a == '/')
		return (true);
	return (false);
}


static bool valid_input(std::string inpt)
{
	int i = 0;

	while (inpt[i])
	{
		if (!is_valid_char(inpt[i]))
		{
			if (SPECIFIC_ERRORS)
			{
				std::cout << "Error: invalid char at position " << i << "." << std::endl;
				std::cout << inpt << std::endl;
				for (int count = 0; count < i; count++)
					std::cout << " ";
				std::cout << "\033[1;33m^\033[0m" << std::endl;
			}
			return (false);
		}
		i++;
	}
	return (true);
}

//? Used for testing and demontrations.
void print_items(std::list<ft_item> &item)
{
	std::list<ft_item>::iterator pos;

    for (pos = item.begin(); pos != item.end(); ++pos)
	{
        if (pos->get_is_sign())
			std::cout << "[" << (char)pos->get_value() << "] ";
        else
			std::cout << "(" << (int)pos->get_value() << ") ";
    }
    std::cout << std::endl;
}

int RPN_operate(std::list<ft_item> the_queue)
{
	std::list<ft_item>::iterator pos = the_queue.begin();
	std::list<int> last_nums;
	int temp_result = 0;

	if (the_queue.size() == 1)
	{
		if (the_queue.begin()->get_is_sign())
			throw ft_item::GenericError();
		else
			return (the_queue.begin()->get_value());
	}
	while (pos != the_queue.end())
	{
		if (!pos->get_is_sign())
		{
			last_nums.push_back(pos->get_value());
			if (last_nums.size() > 2)
				last_nums.pop_front();
			pos++;
		}
		else
		{
			if (last_nums.size() != 2)
				throw ft_item::GenericError();
			if (pos->get_value() == '+')
				temp_result = *(last_nums.begin()) + *(--last_nums.end());
			else if (pos->get_value() == '-')
				temp_result = *(last_nums.begin()) - *(--last_nums.end());
			else if (pos->get_value() == '*')
				temp_result = *(last_nums.begin()) * *(--last_nums.end());
			else if (pos->get_value() == '/')
				temp_result = *(last_nums.begin()) / *(--last_nums.end());

			pos = the_queue.erase(pos);
			pos--;
			pos = the_queue.erase(pos);
			pos--;
			pos = the_queue.erase(pos);
			the_queue.insert(pos, ft_item(temp_result));
			return(RPN_operate(the_queue));
		}


	}
	throw ft_item::GenericError();
	return (-1);
}

int RPN(std::string inpt)
{
	int idx = 0;
	if (!valid_input(inpt))
	{
		if (!SPECIFIC_ERRORS)
			std::cout << "Error" << std::endl;
		return (1);
	}
	std::list<ft_item> the_queue;

	while (inpt[idx])
	{
		if (inpt[idx] == '-' && isdigit(inpt[idx + 1]) && ALLOW_NEGATIVE_INPUT)
		{
			the_queue.push_back(ft_item(((int)inpt[idx + 1] - '0') * -1));
			idx++;
		}
		else if (is_operand(inpt[idx]))
			the_queue.push_back(ft_item((char)inpt[idx]));
		else if (isdigit(inpt[idx]))
			the_queue.push_back(ft_item((int)inpt[idx] - '0'));
		idx++;
	}

	try
	{
		std::cout << RPN_operate(the_queue) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}