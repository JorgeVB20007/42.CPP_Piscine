/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:38:05 by jvacaris          #+#    #+#             */
/*   Updated: 2023/03/04 18:35:31 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		if (!SPECIFIC_ERRORS)
			std::cout << "Error" << std::endl;
		else
			std::cout << "Error: Expected \033[1m1\033[0m argument but got \033[1;33m" << argc - 1 << "\033[0m." << std::endl;
		return (1);
	}
	std::string inpt = argv[1];
	return (RPN(inpt));	
}