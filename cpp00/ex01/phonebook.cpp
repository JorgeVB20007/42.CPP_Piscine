/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:44:04 by jvacaris          #+#    #+#             */
/*   Updated: 2022/06/07 21:26:21 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void PhoneBook::preparePage(int curr_capacity)
{
	if (curr_capacity < 8)
	{
		pages[curr_capacity].addContact();
	}
}

void PhoneBook::displayGrid(int curr_capacity)
{
	int a = 0;

	grid_printHeader();
	if (curr_capacity > 0)
	{
		while (a < curr_capacity)
		{
			pages[a].printContactOnGrid(a);
			a++;
		}
	}
	else
	{
		std::cout << "|        The list is currently empty        |" << std::endl;
		std::cout << "|     Add your first contact with \"ADD\"     |" << std::endl;
	}
	grid_printFooter();
}

void PhoneBook::displayContact(int choice, int curr_capacity)
{
	if (choice < 1 || choice > curr_capacity)
		std::cout << "ERROR: Last time I checked, " << choice << " was not a number between 1 and " << curr_capacity << "." << std::endl;
	else
	{
		pages[choice - 1].printContact(choice);
	}
}

void PhoneBook::moveUp()
{
	int a = 0;

	while (a < 7)
	{
		pages[a] = pages[a + 1];
		a++;
	}
}

static int isNumber(std::string str)
{
	int a = 0;

	if (!str[a])
		return (0);
	while (str[a])
	{
		if (str[a] == ' ')
			a++;
		else if ((str[a] == '+' || str[a] == '-') && std::isdigit(str[a + 1]) && (int)str.length() < 8 + a && (int)str.length() < 128)
			return (1);
		else
			return (std::isdigit(str[a]) && (int)str.length() < 8 + a && (int)str.length() < 128);
	}
	return (0);
}

int main()
{
	PhoneBook	book;
	std::string	command;
	int			curr_capacity = 0;
	char		buff[128];

	std::cout << "Select an option (ADD | SEARCH | EXIT): ";
	while (std::getline(std::cin, command))
	{
		if (!command.compare("EXIT"))
			return(0);
		else if (!command.compare("SEARCH"))
		{
			book.displayGrid(curr_capacity);
			if (curr_capacity > 0)
			{
				std::cout << "Select a contact (1 - " << curr_capacity << "): ";
				std::getline(std::cin, command);
				if (isNumber(command))
				{
					strcpy(buff, command.c_str());
					book.displayContact(std::atoi(buff), curr_capacity);
				}
				else
					std::cout << "ERROR: The answer either is not a number or is outside the limits." << std::endl;
			}
		}
		else if (!command.compare("ADD"))
		{
			if (curr_capacity == 8)
			{
				book.moveUp();
				curr_capacity--;
			}
			book.preparePage(curr_capacity);
			curr_capacity++;
		}
		std::cout << "Select an option (ADD | SEARCH | EXIT): ";
	}
}
