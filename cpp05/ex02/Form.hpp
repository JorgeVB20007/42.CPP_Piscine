/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:09:18 by jvacaris          #+#    #+#             */
/*   Updated: 2022/11/28 21:54:59 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat ;

class Form
{
	private:
		const std::string name;
		bool is_signed;
		const int sign_grade;
		const int exec_grade;
	
	public:
		Form();
		Form(const std::string _name, int _sign_grade, int _exec_grade);
		Form(Form &tocopy);
		~Form();
		Form & operator = (Form &toequalize);
		const std::string getName();
		int getSignGrade();
		int getExecGrade();
		bool getSignatureStatus();
		void beSigned(Bureaucrat signer);
		virtual void execute(Bureaucrat const & executor) = 0;
		void setSignatureStatus(bool newstatus);

		class GradeTooHighException: public std::exception
		{
			public:
				std::string exceptionPrint()
				{
					return("Exception: Form's grade is too high!\n");
				}
		};

		class GradeTooLowException: public std::exception
		{
			public:
				std::string exceptionPrint()
				{
					return("Exception: Form's grade is too low!\n");
				}
		};

		class AlreadySignedException: public std::exception
		{
			public:
				std::string exceptionPrint()
				{
					return("Exception: Form was already signed!\n");
				}
		};

		class NotSignedException: public std::exception
		{
			public:
				std::string exceptionPrint()
				{
					return("Exception: Unsigned forms cannot be executed!\n");
				}
		};
		
};

std::ostream & operator << (std::ostream &ost, Form &toprint);

#endif