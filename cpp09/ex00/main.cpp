/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:42:05 by jvacaris          #+#    #+#             */
/*   Updated: 2023/03/08 19:31:02 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	std::ifstream csvstream;
	std::ifstream txtstream;

	txtstream.open(argv[1]);
	csvstream.open(CSV_NAME);
	if (!txtstream.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	if (!csvstream.is_open())
	{
		std::cout << "Error: could not open the .csv file." << std::endl;
		return (1);
	}
	BitcoinExchange(&csvstream, &txtstream);
	return (0);
}