/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:40:41 by jvacaris          #+#    #+#             */
/*   Updated: 2023/01/17 12:36:35 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Intern newintern;
	
//?		Creating Bureaucrats
	std::cout << "Creating Bureaucrats" << std::endl;
	Bureaucrat bfirst("First Bureaucrat", 42);
	Bureaucrat bsecond("Second Bureaucrat", 84);
	Bureaucrat bthird("Third Bureaucrat", 2);

//?		Creating Forms
	std::cout << std::endl << "Creating Forms" << std::endl;
	Form	*ppf;
	Form	*rrf;
	Form	*scf;

	ppf = newintern.makeForm("Presidential Pardon", "Trillian");
	rrf = newintern.makeForm("robotomy", "Ford Prefect");
	scf = newintern.makeForm("shrubberycreation", "forest");
//!		Creating invalid Form
	try
	{
		Form	*invf;
		invf = newintern.makeForm("unknown form", "someone");
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}

//?		Printing stuff
	std::cout << "-------" << std::endl;
	std::cout << bfirst << std::endl;
	std::cout << bsecond << std::endl;
	std::cout << bthird << std::endl;
	std::cout << std::endl;

	std::cout << *ppf << std::endl;
	std::cout << *rrf << std::endl;
	std::cout << *scf << std::endl;
	std::cout << "-------" << std::endl;

//!		Signing Forms by unauthorized Bureaucrats
	std::cout << std::endl << "   Trying some invalid signatures   " << std::endl;
	bsecond.signForm(*rrf);
	bfirst.signForm(*ppf);

//?		Printing stuff
	std::cout << std::endl << "-------" << std::endl;
	std::cout << bfirst << std::endl;
	std::cout << bsecond << std::endl;
	std::cout << bthird << std::endl;
	std::cout << std::endl;
	std::cout << *ppf << std::endl;
	std::cout << *rrf << std::endl;
	std::cout << *scf << std::endl;

	std::cout << "-------" << std::endl;

//*		Properly signiing Forms
	std::cout << std::endl << "   Signing all forms   " << std::endl;
	bfirst.signForm(*rrf);
	bsecond.signForm(*scf);
	bthird.signForm(*ppf);

//?		Printing stuff
	std::cout << std::endl << "-------" << std::endl;
	std::cout << bfirst << std::endl;
	std::cout << bsecond << std::endl;
	std::cout << bthird << std::endl;
	std::cout << std::endl;
	std::cout << *ppf << std::endl;
	std::cout << *rrf << std::endl;
	std::cout << *scf << std::endl;
	std::cout << "-------" << std::endl;

//!		Trying to execute Forms by unauthorized Bureucrats
	std::cout << std::endl << "   Trying some invalid executions   " << std::endl;
	bfirst.executeForm(*ppf);
	bsecond.executeForm(*rrf);

//?		Printing stuff
	std::cout << std::endl << "-------" << std::endl;
	std::cout << bfirst << std::endl;
	std::cout << bsecond << std::endl;
	std::cout << bthird << std::endl;
	std::cout << std::endl;
	std::cout << *ppf << std::endl;
	std::cout << *rrf << std::endl;
	std::cout << *scf << std::endl;
	std::cout << "-------" << std::endl;

//*		Properly executing Forms
	std::cout << std::endl << "   Executing all forms   " << std::endl;
	bfirst.executeForm(*rrf);
	bsecond.executeForm(*scf);
	bthird.executeForm(*ppf);

//?		Printing stuff
	std::cout << std::endl << "-------" << std::endl;
	std::cout << bfirst << std::endl;
	std::cout << bsecond << std::endl;
	std::cout << bthird << std::endl;
	std::cout << std::endl;
	std::cout << *ppf << std::endl;
	std::cout << *rrf << std::endl;
	std::cout << *scf << std::endl;
	std::cout << "-------" << std::endl;
	
//?		Executing ShrubberyCreationForms to demonstrate the 50% executing rate.
	std::cout << std::endl << "   Proving Shrubbery   " << std::endl;
	std::cout << "\033[0;32m";
	bfirst.executeForm(*rrf);
	std::cout << "\033[0;33m";
	bthird.executeForm(*rrf);
	std::cout << "\033[0;31m";
	bfirst.executeForm(*rrf);
	std::cout << "\033[0;35m";
	bfirst.executeForm(*rrf);
	std::cout << "\033[0;36m";
	bthird.executeForm(*rrf);
	std::cout << "\033[0m";
	bthird.executeForm(*rrf);

//?		leaks are no more
	delete(scf);
	delete(rrf);
	delete(ppf);
	
	std::cout << "Done" << std::endl;
}