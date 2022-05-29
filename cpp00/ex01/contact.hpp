/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:24:03 by jvacaris          #+#    #+#             */
/*   Updated: 2022/05/30 00:51:31 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
	private:
		std::string	name;
		std::string	surname;
		std::string	nickname;
		std::string	phone;
		std::string	secret;
	public:
		Contact(void);
		~Contact(void);
		void addContact(void);
		void printContactOnGrid(int index);
		void printContact(int index);
};

void grid_printHeader(void);
void grid_printFooter(void);
void grid_printSpaces(int a);
void grid_printItem(std::string item);

#endif