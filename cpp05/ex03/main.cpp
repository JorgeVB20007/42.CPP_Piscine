/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:40:41 by jvacaris          #+#    #+#             */
/*   Updated: 2022/11/29 19:16:28 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::cout << "Creating Bureaucrats" << std::endl;
	Bureaucrat bfirst("First Bureaucrat", 42);
	Bureaucrat bsecond("Second Bureaucrat", 84);
	Bureaucrat bthird("Third Bureaucrat", 2);
	Bureaucrat bad_bureaucrat_one("Third Bureaucrat", 160);

	std::cout << std::endl << "Creating Forms" << std::endl;
	PresidentialPardonForm	ffirst("Trillian");
	RobotomyRequestForm		fsecond("Ford Prefect");
	ShrubberyCreationForm	fthird("forest");



	std::cout << "-------" << std::endl;
	std::cout << bfirst << std::endl;
	std::cout << bsecond << std::endl;
	std::cout << bthird << std::endl;
	std::cout << std::endl;

	std::cout << ffirst << std::endl;
	std::cout << fsecond << std::endl;
	std::cout << fthird << std::endl;
	std::cout << "-------" << std::endl;

	std::cout << std::endl << "   Trying some invalid signatures   " << std::endl;
	bsecond.signForm(fsecond);
	bfirst.signForm(ffirst);
	bad_bureaucrat_one.signForm(fthird);


	std::cout << std::endl << "-------" << std::endl;
	std::cout << bfirst << std::endl;
	std::cout << bsecond << std::endl;
	std::cout << bthird << std::endl;
	std::cout << std::endl;
	std::cout << ffirst << std::endl;
	std::cout << fsecond << std::endl;
	std::cout << fthird << std::endl;

	std::cout << "-------" << std::endl;


	std::cout << std::endl << "   Signing all forms   " << std::endl;
	bfirst.signForm(fsecond);
	bsecond.signForm(fthird);
	bthird.signForm(ffirst);

	std::cout << std::endl << "-------" << std::endl;
	std::cout << bfirst << std::endl;
	std::cout << bsecond << std::endl;
	std::cout << bthird << std::endl;
	std::cout << std::endl;
	std::cout << ffirst << std::endl;
	std::cout << fsecond << std::endl;
	std::cout << fthird << std::endl;
	std::cout << "-------" << std::endl;

	std::cout << std::endl << "   Trying some invalid executions   " << std::endl;
	bfirst.executeForm(ffirst);
	bsecond.executeForm(fsecond);
	bad_bureaucrat_one.executeForm(fthird);

	std::cout << std::endl << "-------" << std::endl;
	std::cout << bfirst << std::endl;
	std::cout << bsecond << std::endl;
	std::cout << bthird << std::endl;
	std::cout << std::endl;
	std::cout << ffirst << std::endl;
	std::cout << fsecond << std::endl;
	std::cout << fthird << std::endl;
	std::cout << "-------" << std::endl;

	std::cout << std::endl << "   Executing all forms   " << std::endl;
	bfirst.executeForm(fsecond);
	bsecond.executeForm(fthird);
	bthird.executeForm(ffirst);

	std::cout << std::endl << "-------" << std::endl;
	std::cout << bfirst << std::endl;
	std::cout << bsecond << std::endl;
	std::cout << bthird << std::endl;
	std::cout << std::endl;
	std::cout << ffirst << std::endl;
	std::cout << fsecond << std::endl;
	std::cout << fthird << std::endl;
	std::cout << "-------" << std::endl;
	
	std::cout << std::endl << "   Proving Shrubbery   " << std::endl;
	bfirst.executeForm(fsecond);
	bthird.executeForm(fsecond);
	bfirst.executeForm(fsecond);
	bfirst.executeForm(fsecond);
	bthird.executeForm(fsecond);
	bthird.executeForm(fsecond);
	
	std::cout << "Done" << std::endl;
}