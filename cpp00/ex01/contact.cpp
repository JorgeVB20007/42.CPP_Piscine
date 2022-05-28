/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:31:20 by jvacaris          #+#    #+#             */
/*   Updated: 2022/05/28 23:57:43 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

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
	std::cout << "| NAME: " << name << std::endl;
	std::cout << "| LAST NAME: " << surname << std::endl;
	std::cout << "| NICKNAME: " << nickname << std::endl;
	std::cout << "| PHONE NUMBER: " << phone << std::endl;
	std::cout << "| DARKEST SECRET: " << secret << std::endl;
}

void Contact::addContact(/*int current_capacity*/)
{
	std::cout << "Name: ";
//	std::cin >> name ;
	std::getline(std::cin, name);
	std::cout << "Last name: ";
//	std::cin >> surname ;
	std::getline(std::cin, surname);
	std::cout << "Nickname: ";
//	std::cin >> nickname ;
	std::getline(std::cin, nickname);
	std::cout << "Phone number: ";
//	std::cin >> phone ;				//! Check stoi (~atoi) on <string>
	std::getline(std::cin, phone);
	std::cout << "Darkest secret: ";
//	std::cin >> secret ;
	std::getline(std::cin, secret);
}
