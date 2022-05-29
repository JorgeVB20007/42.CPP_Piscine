/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:31:20 by jvacaris          #+#    #+#             */
/*   Updated: 2022/05/30 00:49:14 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

int phone_isValid(std::string number)
{
	int a = 0;
	int parenthesis = 0;
	char c;

	while (number[a])
	{
		c = number[a];
		if (std::isdigit(c) || c == '(' || c == ')' || c == ' ' || c == '-' || c == '+')
		{
			if (c == '(')
				parenthesis++;
			else if (c == ')')
				parenthesis--;
			if (parenthesis < 0)
			{
				std::cout << "ERROR: Parenthesis are not properly organized." << std::endl;
				return (0);
			}

		}
		else
		{
			std::cout << "ERROR: Invalid characters." << std::endl;
			return (0);
		}
		a++;
	}
	if (parenthesis)
		std::cout << "ERROR: Parenthesis are not properly closed." << std::endl;
	return (!parenthesis);
}

int name_specialChars(std::string name)
{
	int a = 0;

	while (name[a])
	{
		if (name[a] < 0 || name[a] > 127)
		{
			std::cout << "Please, use ASCII characters only" << std::endl;
			return (0);
		}
		a++;
	}
	return (1);
}

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void Contact::printContactOnGrid(int index)
{
	std::cout << "|         " << index + 1 << "|";
	grid_printItem(name);
	grid_printItem(surname);
	grid_printItem(nickname);
	std::cout << std::endl;
}

void Contact::printContact(int index)
{
	std::cout << "CONTACT #" << index << ":" << std::endl;
	std::cout << "- NAME: " << name << std::endl;
	std::cout << "- LAST NAME: " << surname << std::endl;
	std::cout << "- NICKNAME: " << nickname << std::endl;
	std::cout << "- PHONE NUMBER: " << phone << std::endl;
	std::cout << "- DARKEST SECRET: " << secret << std::endl;
}

void Contact::addContact(/*int current_capacity*/)
{
	int a = 1;
	
	std::cout << "Name: ";
//	std::getline(std::cin, name);
	while (a == 1 && std::getline(std::cin, name))
	{
		if (name_specialChars(name) == 1)
			a = 0;
		else
			std::cout << "Name: ";
	}
/*	
	if (!name_specialChars(name))
	{
		std::cout << "--- ERROR ---" <<std::endl;
	}
*/
	a = 1;
	std::cout << "Last name: ";
	while (a == 1 && std::getline(std::cin, surname))
	{
		if (name_specialChars(surname) == 1)
			a = 0;
		else
			std::cout << "Last name: ";
	}
//	std::getline(std::cin, surname);

	a = 1;
	std::cout << "Nickname: ";
	while (a == 1 && std::getline(std::cin, nickname))
	{
		if (name_specialChars(nickname) == 1)
			a = 0;
		else
			std::cout << "Nickname: ";
	}
//	std::getline(std::cin, nickname);

	a = 1;
	std::cout << "Phone number: ";
	while (a == 1 && std::getline(std::cin, phone))
	{
		if (phone_isValid(phone) == 1)
			a = 0;
		else
			std::cout << "Phone number: ";
	}
	std::cout << "Darkest secret: ";
	std::getline(std::cin, secret);
	if (name.length() < 1 && surname.length() < 1 && nickname.length() < 1 && phone.length() < 1)
		std::cout << "It's a bit sad that you add no one to your contact list, but sure..." << std::endl << std::endl;
	else if (name.length() < 1)
		std::cout << "Contact successfully added." << std::endl << std::endl;
	else
		std::cout << name << " was successfully added." << std::endl << std::endl;
}
