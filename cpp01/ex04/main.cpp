/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:45:40 by jvacaris          #+#    #+#             */
/*   Updated: 2022/06/19 00:41:22 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int argc, char **argv)
{
	std::ifstream	finput;
	std::string		content;
	int				position = 0;
	std::string		strline;
	size_t				result;


	if (argc != 4)
	{
		std::cout << "Wrong number of paremeters. Got " << argc - 1 << " expected 3." << std::endl;
		return (1);
	}

	std::string	s1(argv[2]);
	std::string	s2(argv[3]);
	finput.open(argv[1]);
	char line[s1.length() * 2];

	while (finput.read(line, s1.length() * 2 - 1))		//! getline might not work when the string passed contains newlines.
	{
		line[s1.length() * 2 - 1] = 0;
		strline = line;
//		std::cout << "line = " << line << std::endl << "strline = " << strline << std::endl << std::endl;
		position += s1.length();
//		std::cout << finput.tellg() << " ";
		result = strline.find(s1);
//		std::cout << " (" << result << ") ";
		if (result != std::string::npos)
		{
			strline.erase(result, s1.length());
			strline.insert(result, s2);
////			std::cout <<  "     AAAAAAAAAAAAAAAAAAAA ";
			std::cout << strline;
//			std::cout << "[" << strline << "]";
			position += s1.length() - 1;
		}
		else
		{
			strline.resize(s1.length());
			std::cout << strline;
//			std::cout << "(" << strline << ")";

		}
		finput.seekg(position);
	}
	std::cout << line;			//! This is wrong as it doesn't account for a match right at the end of a file.
//	std::cout << std::endl << s1;
	finput.close();
	return (0);
}
