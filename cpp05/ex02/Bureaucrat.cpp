/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:52:51 by jvacaris          #+#    #+#             */
/*   Updated: 2022/11/21 20:00:37 by jvacaris         ###   ########.fr       */
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
			throw Bureaucrat::GradeTooLowException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooHighException();
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << e.exceptionPrint();
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << e.exceptionPrint();
	}
}

Bureaucrat::Bureaucrat(Bureaucrat &tocopy): name(tocopy.name)
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
	try
	{
		if (grade - 1 < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			grade--;
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << e.exceptionPrint();
	}
}

void Bureaucrat::gradedown()
{
	try
	{
		if (grade + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
		grade++;
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << e.exceptionPrint();
	}
}

std::ostream & operator << (std::ostream &ost, Bureaucrat &toprint)
{
	ost << toprint.getName() << ", bureaucrat grade " << toprint.getGrade() << ".";
	return (ost);
}

void Bureaucrat::signForm(Form & tosign)
{
	try
	{
		if (getGrade() < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (getGrade() > 150)
			throw Bureaucrat::GradeTooLowException();
		tosign.beSigned(*this);
		std::cout << getName() << " signs " << tosign.getName() << "." << std::endl;
	}
	catch (Form::GradeTooHighException & e)
	{
		std::cout << getName() << " cannot sign " << tosign.getName() << " because ";
		std::cout << e.exceptionPrint();
	}
	catch (Form::GradeTooLowException & e)
	{
		std::cout << getName() << " cannot sign " << tosign.getName() << " because ";
		std::cout << e.exceptionPrint();
	}
	catch (Form::AlreadySignedException & e)
	{
		std::cout << getName() << " cannot sign " << tosign.getName() << " because ";
		std::cout << e.exceptionPrint();
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << getName() << " is unauthorized to sign " << tosign.getName() << " because ";
		std::cout << e.exceptionPrint();
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << getName() << " is unauthorized to sign " << tosign.getName() << " because ";
		std::cout << e.exceptionPrint();
	}

}
	