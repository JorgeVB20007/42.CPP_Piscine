/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:32:17 by jvacaris          #+#    #+#             */
/*   Updated: 2022/11/01 21:02:04 by jvacaris         ###   ########.fr       */
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
		Bureaucrat(const std::string _name, int _grade);
		Bureaucrat(Bureaucrat &tocopy);
		~Bureaucrat();
		Bureaucrat & operator = (Bureaucrat &toequalize);
		const std::string getName();
		int getGrade();
		void gradeup();
		void gradedown();
};
#endif