/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:32:17 by jvacaris          #+#    #+#             */
/*   Updated: 2023/01/15 16:13:06 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#define NOTIFS 0

#include <iostream>




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

		class GradeTooHighException: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return("Exception: Grade is too high!\n");
				}
		};

		class GradeTooLowException: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return("Exception: Grade is too low!\n");
				}
		};

};

std::ostream & operator << (std::ostream &ost, Bureaucrat &toprint);

#endif