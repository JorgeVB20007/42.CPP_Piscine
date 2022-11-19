/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:40:41 by jvacaris          #+#    #+#             */
/*   Updated: 2022/11/19 18:15:14 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
int main()
{
	std::cout << "Bureaucrats" << std::endl;
	Bureaucrat first("First", 42);
	Bureaucrat second("Second", 155);
	Bureaucrat third("Third", 1);
	Bureaucrat fourth(third);

	std::cout << "-------" << std::endl;
	std::cout << first << std::endl;
	std::cout << second << std::endl;
	std::cout << third << std::endl;
	std::cout << fourth << std::endl;
	std::cout << "-------" << std::endl;

	std::cout << "1. " << std::endl;
	first.gradeup();
	std::cout << "2. ";
	second.gradedown();
	std::cout << "3. ";
	third.gradeup();

	std::cout << "-------" << std::endl;
	std::cout << first << std::endl;
	std::cout << second << std::endl;
	std::cout << third << std::endl;
	std::cout << "-------" << std::endl;

	std::cout << "Done" << std::endl;
}