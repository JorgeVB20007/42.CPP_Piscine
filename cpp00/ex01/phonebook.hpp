/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:48:15 by jvacaris          #+#    #+#             */
/*   Updated: 2022/05/29 00:31:48 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "contact.hpp"

class PhoneBook
{
	private:
		Contact	pages[8];
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	preparePage(int curr_capacity);
		void	displayGrid(int curr_capacity);
		void	displayContact(int choice, int curr_capacity);
		void	moveUp();
//		void	increase_capacity(void);
};
