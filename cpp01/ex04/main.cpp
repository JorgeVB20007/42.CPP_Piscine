/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:45:40 by jvacaris          #+#    #+#             */
/*   Updated: 2022/06/20 20:46:05 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Wrong number of parameters. Got " << argc - 1 << " expected 3." << std::endl;
		return (1);
	}
	return(ft_replacer(argv));
}
