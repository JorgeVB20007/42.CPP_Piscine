/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:09:18 by jvacaris          #+#    #+#             */
/*   Updated: 2022/11/19 00:53:06 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool is_signed;
		const int min_grade;
	
	public:
		Form();
		Form(const std::string _name, int _min_grade);
		Form(Form &tocopy);
		~Form();
		Form & operator = (Form &toequalize);
		const std::string getName();
		int getGrade();
		void gradeup();
		void gradedown();

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

std::ostream & operator << (std::ostream &ost, Form &toprint);

#endif