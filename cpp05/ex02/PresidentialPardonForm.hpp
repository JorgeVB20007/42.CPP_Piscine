/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:09:18 by jvacaris          #+#    #+#             */
/*   Updated: 2022/11/29 16:27:21 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"


class PresidentialPardonForm: public Form
{
	private:
		const std::string target;
	
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(PresidentialPardonForm &tocopy);
		~PresidentialPardonForm();
		PresidentialPardonForm & operator = (PresidentialPardonForm &toequalize);
		void execute(Bureaucrat const & executor) const;
		const std::string getTarget();
};

#endif