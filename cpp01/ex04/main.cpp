/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:45:40 by jvacaris          #+#    #+#             */
/*   Updated: 2022/06/16 22:56:30 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int argc, char **argv)
{
	std::ifstream	finput;
	std::string		content;
	std::string		line;

	if (argc != 4)
	{
		std::cout << "Wrong number of paremeters. Got " << argc - 1 << "expected 4." << std::endl;
		return (1);
	}

	finput.open(argv[1]);


	while (std::getline(line))		//! getline might not work when the string passed contains newlines.
	{

	}



	return (0);
}
