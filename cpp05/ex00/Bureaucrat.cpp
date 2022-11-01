/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:52:51 by jvacaris          #+#    #+#             */
/*   Updated: 2022/11/01 21:32:54 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("???")
{
	if (NOTIFS)
		std::cout << "Bureaucrat Default constructor called." << std::endl;
	grade = 150;
}

Bureaucrat::Bureaucrat(const std::string _name, int _grade): name(_name)
{
	if (NOTIFS)
		std::cout << "Bureaucrat Regular constructor called." << std::endl;
	grade = _grade;
	try
	{
		if (grade < 1)
			throw 1;
		else if (grade > 150)
			throw 2;
	}
	//!    Missing try/catch
}

Bureaucrat::Bureaucrat(Bureaucrat &tocopy)
{
	if (NOTIFS)
		std::cout << "Bureaucrat Copy constructor called." << std::endl;
	*this = tocopy;

}

Bureaucrat::~Bureaucrat()
{
	if (NOTIFS)
		std::cout << "Bureaucrat Default destructor called." << std::endl;
}

Bureaucrat & Bureaucrat::operator = (Bureaucrat &toequalize)
{
	if (NOTIFS)
		std::cout << "Bureaucrat Assignation operator called." << std::endl;
	grade = toequalize.getGrade();
	return (*this);
}

const std::string Bureaucrat::getName()
{
	return (name);
}

int Bureaucrat::getGrade()
{
	return (grade);
}

void Bureaucrat::gradeup()
{
	grade--;
	//!    Missing try/catch
}

void Bureaucrat::gradedown()
{
	grade++;
	//!    Missing try/catch
}
