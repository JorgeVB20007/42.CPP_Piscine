/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:39:07 by jvacaris          #+#    #+#             */
/*   Updated: 2022/06/27 18:51:57 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

static void str_tolower(char *argv)
{
	int a = 0;

	while (argv[a])
	{
		argv[a] = tolower(argv[a]);
		a++;
	}
}

int main(int argc, char **argv)
{
	Karen	pence;

	if (argc != 2)
	{
		std::cout << "Wrong number of arguments. Got " << argc - 1 << " expected 1." << std::endl;
		return (1);
	}

	str_tolower(argv[1]);
	std::string argument = argv[1];
	pence.complain(argument);

	return (0);
}
