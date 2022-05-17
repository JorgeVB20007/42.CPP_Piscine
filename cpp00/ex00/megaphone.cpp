/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:53:06 by jvacaris          #+#    #+#             */
/*   Updated: 2022/05/17 20:27:02 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void ft_toupper(char *argv)
{
	int	a;

	a = 0;
	while (argv[a])
	{
		if (argv[a] >= 'a' && argv[a] <= 'z')
			argv[a] = argv[a] - 32;
		a++;
	}
}

int main(int argc, char **argv)
{
	int	a;

	a = 1;
	if (argc <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		while (a < argc - 1)
		{
			ft_toupper(argv[a]);
			std::cout << argv[a] << " ";
			a++;
		}
		ft_toupper(argv[a]);
		std::cout << argv[a] << std::endl;
	}
}