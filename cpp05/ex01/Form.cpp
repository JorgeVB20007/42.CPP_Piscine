/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:09:13 by jvacaris          #+#    #+#             */
/*   Updated: 2023/01/14 23:04:31 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form(): name("Untitled"), sign_grade(150), exec_grade(150)
{
	if (NOTIFS)
		std::cout << "Form Default constructor called." << std::endl;
	is_signed = false;
}

Form::Form(const std::string &_name, const int _sign_grade, const int _exec_grade): name(_name), sign_grade(_sign_grade), exec_grade(_exec_grade)
{
	if (NOTIFS)
		std::cout << "Form Regular constructor called." << std::endl;
	is_signed = false;
	if (sign_grade < 1 || exec_grade < 1)
		throw Form::GradeTooHighException();
	else if (sign_grade > 150 || exec_grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form &tocopy): name(tocopy.name), sign_grade(tocopy.sign_grade), exec_grade(tocopy.exec_grade)
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
	is_signed = toequalize.getSignatureStatus();
	return (*this);
}

const std::string &Form::getName() const
{
	return (name);
}

int Form::getSignGrade() const
{
	return (sign_grade);
}

int Form::getExecGrade() const
{
	return (exec_grade);
}

bool Form::getSignatureStatus() const
{
	return (is_signed);
}

void Form::beSigned(Bureaucrat signer)
{
	if (sign_grade < 1)
		throw Form::GradeTooHighException();
	else if (sign_grade > 150)
		throw Form::GradeTooLowException();
	else if (is_signed)
		throw Form::AlreadySignedException();
	else if (sign_grade < signer.getGrade())
		throw Form::GradeTooHighException();

	is_signed = true;
}

std::ostream & operator << (std::ostream &ost, Form &toprint)
{
	ost << "Form name: " << toprint.getName() << " | Signing grade: " << toprint.getSignGrade() << " | Execution grade: " << toprint.getExecGrade() << " | Signed: " << toprint.getSignatureStatus() << ".";
	return (ost);
}
