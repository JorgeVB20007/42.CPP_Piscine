/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:31:20 by jvacaris          #+#    #+#             */
/*   Updated: 2022/05/19 21:34:00 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact(/*std::string _name, std::string _surname, std::string _nickname, int _phone, std::string _secret*/void)
{
	return ;
	// name = _name;
	// surname = _surname;
	// nickname = _nickname;
	// phone = _phone;
	// secret = _secret;
}

Contact::~Contact(void)
{
	return ;
}

int valid_name(std::string name)
{
	if (ft_strlen(name) > 0)
		return (1);
	else
		return (0);
}
