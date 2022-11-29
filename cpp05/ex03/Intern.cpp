/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:42:24 by jvacaris          #+#    #+#             */
/*   Updated: 2022/11/29 20:54:01 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	if (NOTIFS)
		std::cout << "Intern Default constructor called." << std::endl;
}

Intern::Intern(Intern &tocopy)
{
	if (NOTIFS)
		std::cout << "Intern Copy constructor called." << std::endl;
	(void)tocopy;
}

Intern::~Intern()
{
	if (NOTIFS)
		std::cout << "Intern Default destructor called." << std::endl;
}

Intern & Intern::operator = (Intern &toequalize)
{
	if (NOTIFS)
		std::cout << "Intern Assignation operator called." << std::endl;
	(void)toequalize;
	return (*this);
}

static std::string str_toLower(std::string oldstr)
{
	int a = -1;

	while (oldstr[++a])
	{
		if (oldstr[a] >= 'A' && oldstr[a] <= 'Z' )
			oldstr[a] = oldstr[a] + 32;
	}
	return(oldstr);
}

static int find_coincidence(std::string tosearch)
{
	std::string options[] = {"shrubbery", "robotomy", "presidential", "shrubbery creation", "robotomy request", "presidential pardon", "shrubberycreation", "robotomyrequest", "presidentialpardon", "shrubberycreation", "robotomyrequest", "presidentialpardon", "shrubberycreationform", "robotomyrequestform", "presidentialpardonform"};
	int a = -1;

	while (++a < 15)
	{
		if (options[a] == tosearch)
			return (a % 3);
		std::cout << tosearch << " != " << options[a] << std::endl;
	}
	return (-1);

}

static Form *new_ShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static Form *new_RobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

static Form *new_PresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

Form	*Intern::makeForm(std::string type, std::string target)
{
	Form	*form_types[] = {new_ShrubberyCreationForm(target), new_RobotomyRequestForm(target), new_PresidentialPardonForm(target)};
	int index;
	
	index = find_coincidence(str_toLower(type));
	if (index == -1)
	{
		std::cout << "Unknown form \"" << type << "\"" << std::endl;
		return (NULL);
	}
	else
	{
		return(form_types[index]);
		//!		Return pointer to the correct specific Form.
	}
}