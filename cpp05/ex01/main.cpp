/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:40:41 by jvacaris          #+#    #+#             */
/*   Updated: 2023/01/17 12:40:23 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
int main()
{
//?		Creating Bureaucrats
	std::cout << "Creating Bureaucrats" << std::endl;
	Bureaucrat bfirst("First Bureaucrat", 42);
	Bureaucrat bsecond("Second Bureaucrat", 84);
	Bureaucrat bthird("Third Bureaucrat", 2);

//!		Bad Bureaucrat
	try
	{
		Bureaucrat bad_bureaucrat_one("Bad Bureaucrat", 160);
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
	
//?		Creating Forms
	std::cout << std::endl << "Creating Forms" << std::endl;
	Form ffirst("First Form", 42, 24);
	Form fsecond("Second Form", 21, 12);
	Form fthird("Third Form", 2, 120);

//*		Good Form test
	try
	{
		Form good_form_test("Good Form", 42, 5);
		std::cout << "Good form created correctly!" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}

//!		Bad forms tests
	try
	{
		Form bad_form_one("First Bad Form", 156, 3);
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
	
	try
	{
		Form bad_form_two("Second Bad Form", 0, 420);
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

	std::cout << ffirst << std::endl;
	std::cout << fsecond << std::endl;
	std::cout << fthird << std::endl;
	std::cout << "-------" << std::endl;

//!		Signing Forms by unauthorized Bureaucrats
	std::cout << std::endl << "   Trying some invalid cases   " << std::endl;
	bsecond.signForm(ffirst);
	bfirst.signForm(fthird);

//?		Printing stuff
	std::cout << std::endl << "-------" << std::endl;
	std::cout << bfirst << std::endl;
	std::cout << bsecond << std::endl;
	std::cout << bthird << std::endl;
	std::cout << std::endl;
	std::cout << ffirst << std::endl;
	std::cout << fsecond << std::endl;
	std::cout << fthird << std::endl;
	std::cout << "-------" << std::endl;

//*		Signing valid forms
	std::cout << std::endl << "   Trying some valid cases   " << std::endl;
	bfirst.signForm(ffirst);
	bthird.signForm(fsecond);

//?		Printing stuff
	std::cout << std::endl << "-------" << std::endl;
	std::cout << bfirst << std::endl;
	std::cout << bsecond << std::endl;
	std::cout << bthird << std::endl;
	std::cout << std::endl;
	std::cout << ffirst << std::endl;
	std::cout << fsecond << std::endl;
	std::cout << fthird << std::endl;
	std::cout << "-------" << std::endl;

	std::cout << "Done" << std::endl;
}