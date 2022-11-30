/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:37:11 by jvacaris          #+#    #+#             */
/*   Updated: 2022/11/30 16:53:31 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

static std::string getTrees()
{
	std::string toreturn;
	toreturn = \
"       ****                     \n" \
"    ********                       __  \\_|    V  V  /-'    *\n" \
"**  ******                         __\\_\\__\\   | / \\/      ***\n" \
"    *   ******     ******       _/  /  \\  |/  /   V      *****\n" \
"        ******   *********        _/    000__/   /      *******\n" \
"        ****  *****   ***         |   \\/000  \\__X      *********\n" \
"        ***  ***     **              _/ 000    / \\    ***********\n" \
"*************       *                   000            *********\n" \
"******************                /\\    000           ***********\n" \
"*****   H*****H*******           //\\\\   000          *************\n" \
"***     H-___-H  *********      ///\\\\\\                ***********\n" \
"***     H     H     *******     ///\\\\\\               *************\n" \
"**      H-___-H      *****      ///\\\\\\              ***************\n" \
"    *   H     H         ****   ////\\\\\\\\            *****************\n" \
"        H     H         ***     ///\\\\\\                   |||||\n" \
"        H-___-H         **        ||                     |||||\n" \
"        H     H         *         ||           \\V/            \n" \
"        H-___-H                               \\\\|//\n" \
"                                              \\\\|//\n" \
"                                                |";
	
	return (toreturn);
}

ShrubberyCreationForm::ShrubberyCreationForm(): Form("ShrubberyCreationForm", 145, 137), target("???")
{
	if (NOTIFS)
		std::cout << "ShrubberyCreationForm Default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string _target): Form("ShrubberyCreationForm", 145, 137), target(_target)
{
	if (NOTIFS)
		std::cout << "ShrubberyCreationForm Regular constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &tocopy): Form("ShrubberyCreationForm", 145, 137), target(tocopy.getTarget())
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

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream	foutput;

	if (!getSignatureStatus())
		throw Form::NotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw Form::GradeTooHighException();
	try
	{
		foutput.open(target + "_shrubbery");
		if (!foutput.is_open())
		{
			throw ShrubberyCreationForm::FileOpeningErrorException();
		}
		foutput << getTrees();
		foutput.close();
	}
	catch (ShrubberyCreationForm::FileOpeningErrorException & e)
	{
		std::cout << e.exceptionPrint(target);
	}
}

const std::string ShrubberyCreationForm::getTarget()
{
	return(target);
}
