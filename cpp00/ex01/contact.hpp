/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:24:03 by jvacaris          #+#    #+#             */
/*   Updated: 2022/05/19 21:43:21 by jvacaris         ###   ########.fr       */
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
		Contact(std::string, std::string, std::string, int, std::string);
		int valid_name(std::string name);
};
