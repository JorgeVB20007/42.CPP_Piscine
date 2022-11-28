/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 21:57:32 by jvacaris          #+#    #+#             */
/*   Updated: 2022/11/28 23:53:29 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form("RobotomyRequestForm", 25, 5), target("???")
{
	if (NOTIFS)
		std::cout << "RobotomyRequestForm Default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string _target): Form("RobotomyRequestForm", 25, 5), target(_target)
{
	if (NOTIFS)
		std::cout << "RobotomyRequestForm Regular constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &tocopy): Form("RobotomyRequestForm", 25, 5), target(tocopy.getTarget())
{
	if (NOTIFS)
		std::cout << "RobotomyRequestForm Copy constructor called." << std::endl;
	*this = tocopy;

}

RobotomyRequestForm::~RobotomyRequestForm()
{
	if (NOTIFS)
		std::cout << "RobotomyRequestForm Default destructor called." << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator = (RobotomyRequestForm &toequalize)
{
	if (NOTIFS)
		std::cout << "RobotomyRequestForm Assignation operator called." << std::endl;
	setSignatureStatus(toequalize.getSignGrade());
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor)
{
	static bool is_time2robotomize = true;
//	(void)executor;
	try
	{
		if (getSignatureStatus())
			throw Form::NotSignedException();
		if (executor.getGrade() > getExecGrade())
			throw Form::GradeTooHighException();
		std::cout << "BrRrRrRrRrRrRrRrRrRrRrRrRrRrRrRrRrRrRrRrRr..." << std::endl;
		if (is_time2robotomize)
			std::cout << target << " has been robotomized successfully. ✅" << std::endl;
		else
			std::cout << target << " failed to robotomize. ❌" << std::endl;
		is_time2robotomize = !is_time2robotomize;
	}
	catch(Form::NotSignedException & e)
	{
		std::cout << e.exceptionPrint();
	}
	catch(Form::GradeTooHighException & e)
	{
		std::cout << e.exceptionPrint();
	}
	
}

const std::string RobotomyRequestForm::getTarget()
{
	return(target);
}
