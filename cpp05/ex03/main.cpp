/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:40:41 by jvacaris          #+#    #+#             */
/*   Updated: 2022/11/30 19:36:55 by jvacaris         ###   ########.fr       */
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
	
	std::cout << "Creating Bureaucrats" << std::endl;
	Bureaucrat bfirst("First Bureaucrat", 42);
	Bureaucrat bsecond("Second Bureaucrat", 84);
	Bureaucrat bthird("Third Bureaucrat", 2);
	Bureaucrat bad_bureaucrat_one("Third Bureaucrat", 160);

	std::cout << std::endl << "Creating Forms" << std::endl;

	Form	*ppf;
	Form	*rrf;
	Form	*scf;
	Form	*invf;

	ppf = newintern.makeForm("Presidential Pardon", "Trillian");
	rrf = newintern.makeForm("robotomy", "Ford Prefect");
	scf = newintern.makeForm("shrubberycreation", "forest");
	invf = newintern.makeForm("unknown form", "someone");

	std::cout << "-------" << std::endl;
	std::cout << bfirst << std::endl;
	std::cout << bsecond << std::endl;
	std::cout << bthird << std::endl;
	std::cout << std::endl;

	std::cout << *ppf << std::endl;
	std::cout << *rrf << std::endl;
	std::cout << *scf << std::endl;
	std::cout << "-------" << std::endl;

	std::cout << std::endl << "   Trying some invalid signatures   " << std::endl;
	bsecond.signForm(*rrf);
	bfirst.signForm(*ppf);
	bad_bureaucrat_one.signForm(*scf);


	std::cout << std::endl << "-------" << std::endl;
	std::cout << bfirst << std::endl;
	std::cout << bsecond << std::endl;
	std::cout << bthird << std::endl;
	std::cout << std::endl;
	std::cout << *ppf << std::endl;
	std::cout << *rrf << std::endl;
	std::cout << *scf << std::endl;

	std::cout << "-------" << std::endl;


	std::cout << std::endl << "   Signing all forms   " << std::endl;
	bfirst.signForm(*rrf);
	bsecond.signForm(*scf);
	bthird.signForm(*ppf);

	std::cout << std::endl << "-------" << std::endl;
	std::cout << bfirst << std::endl;
	std::cout << bsecond << std::endl;
	std::cout << bthird << std::endl;
	std::cout << std::endl;
	std::cout << *ppf << std::endl;
	std::cout << *rrf << std::endl;
	std::cout << *scf << std::endl;
	std::cout << "-------" << std::endl;

	std::cout << std::endl << "   Trying some invalid executions   " << std::endl;
	bfirst.executeForm(*ppf);
	bsecond.executeForm(*rrf);
	bad_bureaucrat_one.executeForm(*scf);

	std::cout << std::endl << "-------" << std::endl;
	std::cout << bfirst << std::endl;
	std::cout << bsecond << std::endl;
	std::cout << bthird << std::endl;
	std::cout << std::endl;
	std::cout << *ppf << std::endl;
	std::cout << *rrf << std::endl;
	std::cout << *scf << std::endl;
	std::cout << "-------" << std::endl;

	std::cout << std::endl << "   Executing all forms   " << std::endl;
	bfirst.executeForm(*rrf);
	bsecond.executeForm(*scf);
	bthird.executeForm(*ppf);

	std::cout << std::endl << "-------" << std::endl;
	std::cout << bfirst << std::endl;
	std::cout << bsecond << std::endl;
	std::cout << bthird << std::endl;
	std::cout << std::endl;
	std::cout << *ppf << std::endl;
	std::cout << *rrf << std::endl;
	std::cout << *scf << std::endl;
	std::cout << "-------" << std::endl;
	
	std::cout << std::endl << "   Proving Shrubbery   " << std::endl;
	bfirst.executeForm(*rrf);
	bthird.executeForm(*rrf);
	bfirst.executeForm(*rrf);
	bfirst.executeForm(*rrf);
	bthird.executeForm(*rrf);
	bthird.executeForm(*rrf);

	delete(scf);
	delete(rrf);
	delete(ppf);
	
	std::cout << "Done" << std::endl;
}