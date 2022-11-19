/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:09:13 by jvacaris          #+#    #+#             */
/*   Updated: 2022/11/18 21:11:39 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form(): name("???")
{
	if (NOTIFS)
		std::cout << "Form Default constructor called." << std::endl;
	min_grade = 150;
}

Form::Form(const std::string _name, int _min_grade): name(_name)
{
	if (NOTIFS)
		std::cout << "Form Regular constructor called." << std::endl;
	min_grade = _min_grade;
	try
	{
		if (min_grade < 1)
			throw Form::GradeTooLowException();
		else if (min_grade > 150)
			throw Form::GradeTooHighException();
	}
	catch (Form::GradeTooHighException & e)
	{
		e.exceptionPrint();
	}
	catch (Form::GradeTooLowException & e)
	{
		e.exceptionPrint();
	}
}

Form::Form(Form &tocopy)
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
	min_grade = toequalize.getGrade();
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

std::ostream & operator << (std::ostream &ost, Form &toprint)
{
	ost << toprint.getName() << ", form required grade: " << toprint.getGrade() << ".";
	return (ost);
}
