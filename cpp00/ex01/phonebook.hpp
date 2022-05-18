/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:48:15 by jvacaris          #+#    #+#             */
/*   Updated: 2022/05/18 21:55:34 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Contact
{
	private:
		std::string	name;
		std::string	surname;
		std::string	nickname;
		int			phone;
		std::string	secret;
	public:
		Contact(std::string, std::string, std::string, int, std::string)
		int valid_name(std::string name);
};
