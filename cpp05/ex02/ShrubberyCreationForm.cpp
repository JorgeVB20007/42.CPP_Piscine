/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:37:11 by jvacaris          #+#    #+#             */
/*   Updated: 2022/11/28 23:56:59 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): Form("ShrubberyCreationForm", 25, 5), target("???")
{
	if (NOTIFS)
		std::cout << "ShrubberyCreationForm Default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string _target): Form("ShrubberyCreationForm", 25, 5), target(_target)
{
	if (NOTIFS)
		std::cout << "ShrubberyCreationForm Regular constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &tocopy): Form("ShrubberyCreationForm", 25, 5), target(tocopy.getTarget())
{
	if (NOTIFS)
		std::cout << "ShrubberyCreationForm Copy constructor called." << std::endl;
	*this = tocopy;

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	if (NOTIFS)
		std::cout << "ShrubberyCreationForm Default destructor called." << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator = (ShrubberyCreationForm &toequalize)
{
	if (NOTIFS)
		std::cout << "ShrubberyCreationForm Assignation operator called." << std::endl;
	setSignatureStatus(toequalize.getSignGrade());
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
	std::ofstream	foutput;

	try
	{
		if (getSignatureStatus())
			throw Form::NotSignedException();
		if (executor.getGrade() > getExecGrade())
			throw Form::GradeTooHighException();
		foutput.open(executor.getName() + "_shrubbery");
		if (!foutput.is_open())
		{
			throw ShrubberyCreationForm::FileOpeningErrorException();
		}
	
	}
	catch(Form::NotSignedException & e)
	{
		std::cout << e.exceptionPrint();
	}
	catch(Form::GradeTooHighException & e)
	{
		std::cout << e.exceptionPrint();
	}
	catch(ShrubberyCreationForm::FileOpeningErrorException & e)
	{
		std::cout << e.exceptionPrint(executor.getName());
	}
	
}

const std::string ShrubberyCreationForm::getTarget()
{
	return(target);
}
