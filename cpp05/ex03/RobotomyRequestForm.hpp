/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 21:57:52 by jvacaris          #+#    #+#             */
/*   Updated: 2022/11/29 16:27:25 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"


class RobotomyRequestForm: public Form
{
	private:
		const std::string target;
	
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(RobotomyRequestForm &tocopy);
		~RobotomyRequestForm();
		RobotomyRequestForm & operator = (RobotomyRequestForm &toequalize);
		void execute(Bureaucrat const & executor) const;
		const std::string getTarget();
};

#endif