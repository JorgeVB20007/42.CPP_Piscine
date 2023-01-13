/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:40:41 by jvacaris          #+#    #+#             */
/*   Updated: 2023/01/12 21:07:10 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
//?		Creating Bureaucrats
	std::cout << "Creating Bureaucrats" << std::endl;
	Bureaucrat bfirst("First Bureaucrat", 42);
	Bureaucrat bsecond("Second Bureaucrat", 84);
	Bureaucrat bthird("Third Bureaucrat", 2);

//!		Testing an invalid  Bureaucrat
	try
	{
		Bureaucrat bad_bureaucrat_one("Third Bureaucrat", 160);
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << e.exceptionPrint();
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << e.exceptionPrint();
	}

//?		Creating Forms
	std::cout << std::endl << "Creating Forms" << std::endl;
	PresidentialPardonForm	ffirst("Trillian");
	RobotomyRequestForm		fsecond("Ford Prefect");
	ShrubberyCreationForm	fthird("forest");
	Form					*ffourth = new PresidentialPardonForm("Pointy Trillian");

//?		Printing stuff
	std::cout << "-------" << std::endl;
	std::cout << bfirst << std::endl;
	std::cout << bsecond << std::endl;
	std::cout << bthird << std::endl;
	std::cout << std::endl;

	std::cout << ffirst << std::endl;
	std::cout << fsecond << std::endl;
	std::cout << fthird << std::endl;
	std::cout << *ffourth << std::endl;
	std::cout << "-------" << std::endl;

//!		Signing forms by unauthorized Bureaucrats
	std::cout << std::endl << "   Trying some invalid signatures   " << std::endl;
	bsecond.signForm(fsecond);
	bfirst.signForm(ffirst);

//?		Printing stuff
	std::cout << std::endl << "-------" << std::endl;
	std::cout << bfirst << std::endl;
	std::cout << bsecond << std::endl;
	std::cout << bthird << std::endl;
	std::cout << std::endl;
	std::cout << ffirst << std::endl;
	std::cout << fsecond << std::endl;
	std::cout << fthird << std::endl;
	std::cout << *ffourth << std::endl;

	std::cout << "-------" << std::endl;

//*		Signing forms by authorized Bureaucrats
	std::cout << std::endl << "   Signing all forms   " << std::endl;
	bfirst.signForm(fsecond);
	bsecond.signForm(fthird);
	bthird.signForm(ffirst);
	bthird.signForm(*ffourth);

//?		Printing stuff
	std::cout << std::endl << "-------" << std::endl;
	std::cout << bfirst << std::endl;
	std::cout << bsecond << std::endl;
	std::cout << bthird << std::endl;
	std::cout << std::endl;
	std::cout << ffirst << std::endl;
	std::cout << fsecond << std::endl;
	std::cout << fthird << std::endl;
	std::cout << *ffourth << std::endl;
	std::cout << "-------" << std::endl;

//!		Executing Forms by unauthorized Bureaucrats
	std::cout << std::endl << "   Trying some invalid executions   " << std::endl;
	bfirst.executeForm(ffirst);
	bsecond.executeForm(fsecond);

//?		Printing stuff
	std::cout << std::endl << "-------" << std::endl;
	std::cout << bfirst << std::endl;
	std::cout << bsecond << std::endl;
	std::cout << bthird << std::endl;
	std::cout << std::endl;
	std::cout << ffirst << std::endl;
	std::cout << fsecond << std::endl;
	std::cout << fthird << std::endl;
	std::cout << *ffourth << std::endl;
	std::cout << "-------" << std::endl;

//*		Executing Forms by authorized Bureaucrats
	std::cout << std::endl << "   Executing all forms   " << std::endl;
	bfirst.executeForm(fsecond);
	bsecond.executeForm(fthird);
	bthird.executeForm(ffirst);
	bthird.executeForm(*ffourth);

//?		Printing stuff
	std::cout << std::endl << "-------" << std::endl;
	std::cout << bfirst << std::endl;
	std::cout << bsecond << std::endl;
	std::cout << bthird << std::endl;
	std::cout << std::endl;
	std::cout << ffirst << std::endl;
	std::cout << fsecond << std::endl;
	std::cout << fthird << std::endl;
	std::cout << *ffourth << std::endl;
	std::cout << "-------" << std::endl;
	
//?		Executing ShrubberyCreationForms to demonstrate the 50% executing rate.
	std::cout << std::endl << "   Proving Shrubbery   " << std::endl;
	std::cout << "\033[0;32m";
	bfirst.executeForm(fsecond);
	std::cout << "\033[0;33m";
	bthird.executeForm(fsecond);
	std::cout << "\033[0;31m";
	bfirst.executeForm(fsecond);
	std::cout << "\033[0;35m";
	bfirst.executeForm(fsecond);
	std::cout << "\033[0;36m";
	bthird.executeForm(fsecond);
	std::cout << "\033[0m";
	bthird.executeForm(fsecond);
	
	std::cout << "Done" << std::endl;
}