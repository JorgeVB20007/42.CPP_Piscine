/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:32:17 by jvacaris          #+#    #+#             */
/*   Updated: 2023/01/17 12:32:33 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#define NOTIFS 0

#include <iostream>
#include "Form.hpp"

class Form ;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string &_name, int _grade);
		Bureaucrat(Bureaucrat &tocopy);
		~Bureaucrat();
		Bureaucrat & operator = (Bureaucrat &toequalize);
		const std::string &getName() const;
		int getGrade() const;
		void gradeup();
		void gradedown();
		void signForm(Form & tosign);
		void executeForm(Form const & form);

		class GradeTooHighException: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return("Exception: Bureaucrat's grade is too high!\n");
				}
		};

		class GradeTooLowException: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return("Exception: Bureaucrat's grade is too low!\n");
				}
		};

};

std::ostream & operator << (std::ostream &ost, Bureaucrat &toprint);

#endif