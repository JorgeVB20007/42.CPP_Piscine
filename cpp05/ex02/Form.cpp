/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:09:13 by jvacaris          #+#    #+#             */
/*   Updated: 2022/11/21 20:00:15 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form(): name("Untitled"), min_grade(150)
{
	if (NOTIFS)
		std::cout << "Form Default constructor called." << std::endl;
	is_signed = false;
}

Form::Form(const std::string _name, const int _min_grade): name(_name), min_grade(_min_grade)
{
	if (NOTIFS)
		std::cout << "Form Regular constructor called." << std::endl;
	is_signed = false;
	try
	{
		if (min_grade < 1)
			throw Form::GradeTooLowException();
		else if (min_grade > 150)
			throw Form::GradeTooHighException();
	}
	catch (Form::GradeTooHighException & e)
	{
		std::cout << e.exceptionPrint();
	}
	catch (Form::GradeTooLowException & e)
	{
		std::cout << e.exceptionPrint();
	}
}

Form::Form(Form &tocopy): name(tocopy.name), min_grade(tocopy.min_grade)
{
	if (NOTIFS)
		std::cout << "Form Copy constructor called." << std::endl;
	*this = tocopy;

}

Form::~Form()
{
	if (NOTIFS)
		std::cout << "Form Default destructor called." << std::endl;
}

Form & Form::operator = (Form &toequalize)
{
	if (NOTIFS)
		std::cout << "Form Assignation operator called." << std::endl;
	is_signed = toequalize.getGrade();
	return (*this);
}

const std::string Form::getName()
{
	return (name);
}

int Form::getGrade()
{
	return (min_grade);
}

bool Form::getSignatureStatus()
{
	return (is_signed);
}

void Form::beSigned(Bureaucrat signer)
{
	if (min_grade < 1)
		throw Form::GradeTooHighException();
	else if (min_grade > 150)
		throw Form::GradeTooLowException();
	else if (is_signed)
		throw Form::AlreadySignedException();
	else if (min_grade < signer.getGrade())
		throw Form::GradeTooHighException();

	is_signed = true;
}

std::ostream & operator << (std::ostream &ost, Form &toprint)
{
	ost << "Form name: " << toprint.getName() << " | Required grade: " << toprint.getGrade() << " | Signed: " << toprint.getSignatureStatus() << ".";
	return (ost);
}
