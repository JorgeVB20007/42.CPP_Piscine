/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:40:41 by jvacaris          #+#    #+#             */
/*   Updated: 2022/11/21 20:15:31 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
int main()
{
	std::cout << "Creating Bureaucrats" << std::endl;
	Bureaucrat bfirst("First Bureaucrat", 42);
	Bureaucrat bsecond("Second Bureaucrat", 84);
	Bureaucrat bthird("Third Bureaucrat", 2);
	Bureaucrat bad_bureaucrat_one("Third Bureaucrat", 160);

	std::cout << std::endl << "Creating Forms" << std::endl;
	Form ffirst("First Form", 42);
	Form fsecond("Second Form", 21);
	Form fthird("Third Form", 2);
	Form bad_form_one("First Bad Form", 156);
	Form bad_form_two("Second Bad Form", 0);



	std::cout << "-------" << std::endl;
	std::cout << bfirst << std::endl;
	std::cout << bsecond << std::endl;
	std::cout << bthird << std::endl;
	std::cout << std::endl;

	std::cout << ffirst << std::endl;
	std::cout << fsecond << std::endl;
	std::cout << fthird << std::endl;
	std::cout << bad_form_one << std::endl;
	std::cout << bad_form_two << std::endl;
	std::cout << "-------" << std::endl;

	std::cout << std::endl << "   Trying some invalid cases   " << std::endl;
	bsecond.signForm(ffirst);
	bthird.signForm(bad_form_one);
	bad_bureaucrat_one.signForm(fsecond);
	bad_bureaucrat_one.signForm(bad_form_two);


	std::cout << std::endl << "-------" << std::endl;
	std::cout << bfirst << std::endl;
	std::cout << bsecond << std::endl;
	std::cout << bthird << std::endl;
	std::cout << std::endl;
	std::cout << ffirst << std::endl;
	std::cout << fsecond << std::endl;
	std::cout << fthird << std::endl;
	std::cout << bad_form_one << std::endl;
	std::cout << bad_form_two << std::endl;
	std::cout << "-------" << std::endl;


	std::cout << std::endl << "   Trying some valid cases   " << std::endl;
	bfirst.signForm(ffirst);
	bthird.signForm(fsecond);

	std::cout << std::endl << "-------" << std::endl;
	std::cout << bfirst << std::endl;
	std::cout << bsecond << std::endl;
	std::cout << bthird << std::endl;
	std::cout << std::endl;
	std::cout << ffirst << std::endl;
	std::cout << fsecond << std::endl;
	std::cout << fthird << std::endl;
	std::cout << bad_form_one << std::endl;
	std::cout << bad_form_two << std::endl;
	std::cout << "-------" << std::endl;

	std::cout << "Done" << std::endl;
}