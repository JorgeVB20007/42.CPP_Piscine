/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:37:18 by jvacaris          #+#    #+#             */
/*   Updated: 2023/01/13 16:40:20 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern &tocopy);
		~Intern();
		Intern & operator = (Intern &toequalize);
		Form *makeForm(std::string type, std::string target);

		class UnknownFormException: public std::exception
		{
			public:
				std::string exceptionPrint()
				{
					return("Exception: Form not found.\n");
				}
		};
};