/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:32:17 by jvacaris          #+#    #+#             */
/*   Updated: 2022/11/19 21:11:23 by jvacaris         ###   ########.fr       */
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
		Bureaucrat(const std::string _name, int _grade);
		Bureaucrat(Bureaucrat &tocopy);
		~Bureaucrat();
		Bureaucrat & operator = (Bureaucrat &toequalize);
		const std::string getName();
		int getGrade();
		void gradeup();
		void gradedown();
		void signForm(Form & tosign);

		class GradeTooHighException: public std::exception
		{
			public:
				void exceptionPrint()
				{
					std::cout << "Exception: Grade is too high!" << std::endl;
				}
		};

		class GradeTooLowException: public std::exception
		{
			public:
				void exceptionPrint()
				{
					std::cout << "Exception: Grade is too low!" << std::endl;
				}
		};

};

std::ostream & operator << (std::ostream &ost, Bureaucrat &toprint);

#endif