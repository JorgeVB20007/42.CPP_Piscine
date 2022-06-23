/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:39:07 by jvacaris          #+#    #+#             */
/*   Updated: 2022/06/23 22:22:34 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(int argc, const char **argv)
{
	Karen	pence;

	if (argc != 2)
	{
		std::cout << "Wrong number of arguments. Got " << argc - 1 << "expected 1." << std::endl;
		return (1);
	}

	std::string argument = argv[1];
	switch (argv[1])
	{
		case ("DEBUG"):
		{
			pence.debug();
			break;
		}
		case ("INFO"):
		{
			pence.info();
			break;
		}
		case ("WARNING"):
		{
			pence.warning();
			break;
		}
		case ("ERROR"):
		{
			pence.error();
			break;
		}
	}


	return (0);
}
