/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:07:22 by jvacaris          #+#    #+#             */
/*   Updated: 2022/11/23 21:32:36 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("PresidentialPardonForm", 25, 5), target("???")
{
	if (NOTIFS)
		std::cout << "PresidentialPardonForm Default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string _target): Form("PresidentialPardonForm", 25, 5), target(_target)
{
	if (NOTIFS)
		std::cout << "PresidentialPardonForm Regular constructor called." << std::endl;
}

Form::Form(Form &tocopy): name(tocopy.name), sign_grade(tocopy.sign_grade), exec_grade(tocopy.exec_grade)
{
	if (NOTIFS)
		std::cout << "PresidentialPardonForm Copy constructor called." << std::endl;
	*this = tocopy;

}

PresidentialPardonForm::~PresidentialPardonForm()
{
	if (NOTIFS)
		std::cout << "PresidentialPardonForm Default destructor called." << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator = (PresidentialPardonForm &toequalize)
{
	if (NOTIFS)
		std::cout << "PresidentialPardonForm Assignation operator called." << std::endl;
	Form::is_signed = toequalize.getSignGrade();
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor)
{
	(void)executor;
	try
	{
		if (getSignatureStatus())
			throw Form::NotSignedException();
//		if (executor.getGrade() < getSignGrade())
		std::cout << target << " has been pardoned by Zafod Beeblebrox" << std::endl;
	}
	catch(Form::NotSignedException & e)
	{
		std::cout << e.exceptionPrint();
	}
	
}