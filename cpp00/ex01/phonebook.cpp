/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:44:04 by jvacaris          #+#    #+#             */
/*   Updated: 2022/05/19 21:33:55 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	curr_capacity = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}


static int ft_strlen(std::string str)
{
	int a = 0;

	while (str[a])
		a++;
	return (a);
}

void PhoneBook::add_contact()
{
	std::cin >> PhoneBook::pages[curr_capacity].name;
}

void PhoneBook::search_contact()
{
	std::cout << "Hello";
}

int main()
{
	PhoneBook	book;
	std::string	command;
	int			num_items = 0;
	while (42)
	{
		std::cin >> command;
		if (!command.compare("EXIT"))
			return(0);
		else if (!command.compare("SEARCH"))
			PhoneBook::search_contact();
		else if (!command.compare("ADD"))
			PhoneBook::add_contact();
	}
}
