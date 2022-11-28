/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:36:57 by jvacaris          #+#    #+#             */
/*   Updated: 2022/11/28 23:56:28 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include <fstream>

class ShrubberyCreationForm: public Form
{
	private:
		const std::string target;
	
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm &tocopy);
		~ShrubberyCreationForm();
		ShrubberyCreationForm & operator = (ShrubberyCreationForm &toequalize);
		void execute(Bureaucrat const & executor);
		const std::string getTarget();

		class FileOpeningErrorException: public std::exception
		{
			public:
				std::string exceptionPrint(std::string filename)
				{
					return("Exception: File " + filename + "_shrubbery cannot be opened.\n");
				}
		};
};

#endif