/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:44:04 by jvacaris          #+#    #+#             */
/*   Updated: 2022/05/18 21:55:24 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Contact::Contact(std::string _name, std::string _surname, std::string _nickname, int phone, std::string)

int main()
{
	Contact		itemlist[8];
	std::string	command;
	int			num_items = 0;
	while (42)
	{
		std::cin >> command;
		if (!command.compare("EXIT"))
			return(0);
		else if (!command.compare("SEARCH"))
			pb_search(command, itemlist, num_items);
		else if (!command.compare("ADD"))
			pb_add(command, itemlist, &num_items);

	}
}
