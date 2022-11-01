/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:40:41 by jvacaris          #+#    #+#             */
/*   Updated: 2022/11/01 21:20:54 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
int main()
{
	std::cout << "Bureaucrats" << std::endl;
	Bureaucrat first("First", 42);
	Bureaucrat second("Second", 155);
	Bureaucrat third("Third", 1);

	std::cout << first.getName() << ": " << first.getGrade() << std::endl;
	std::cout << second.getName() << ": " << second.getGrade() << std::endl;
	std::cout << third.getName() << ": " << third.getGrade() << std::endl;

	first.gradeup();
	second.gradeup();
	third.gradedown();

	std::cout << first.getName() << ": " << first.getGrade() << std::endl;
	std::cout << second.getName() << ": " << second.getGrade() << std::endl;
	std::cout << third.getName() << ": " << third.getGrade() << std::endl;

	std::cout << "Done" << std::endl;
}