/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:40:41 by jvacaris          #+#    #+#             */
/*   Updated: 2023/01/17 12:40:06 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
int main()
{
	std::cout << "Bureaucrats" << std::endl;

	try
	{	
		Bureaucrat first("First", 42);

		std::cout << "-------" << std::endl;
		std::cout << first << std::endl;
		std::cout << "-------" << std::endl;

		std::cout << "1. " << std::endl;
		first.gradeup();

		std::cout << "-------" << std::endl;
		std::cout << first << std::endl;
		std::cout << "=======" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
/*	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << e.what();
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << e.what();
	}*/


	try
	{
		Bureaucrat second("Second", 155);

		std::cout << "-------" << std::endl;
		std::cout << second << std::endl;
		std::cout << "-------" << std::endl;

		std::cout << "2. ";
		second.gradedown();

		std::cout << "-------" << std::endl;
		std::cout << second << std::endl;
		std::cout << "=======" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
/*	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << e.what();
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << e.what();
	}*/


	try
	{
		Bureaucrat third("Third", 1);
		Bureaucrat fourth(third);

		std::cout << "-------" << std::endl;
		std::cout << third << std::endl;
		std::cout << fourth << std::endl;
		std::cout << "-------" << std::endl;

		std::cout << "3. ";
		third.gradeup();
		std::cout << "4. ";
		third.gradedown();

		std::cout << "\n-------" << std::endl;
		std::cout << third << std::endl;
		std::cout << fourth << std::endl;
		std::cout << "=======" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}

	std::cout << "Done" << std::endl;
}