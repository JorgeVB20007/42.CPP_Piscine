/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:48:15 by jvacaris          #+#    #+#             */
/*   Updated: 2022/05/19 21:32:41 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "contact.hpp"

class PhoneBook
{
	private:
		Contact	pages[8];
		int		curr_capacity;
	public:
		void search_contact();
		void add_contact();
};
