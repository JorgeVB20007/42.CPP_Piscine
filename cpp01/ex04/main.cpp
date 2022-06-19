/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:45:40 by jvacaris          #+#    #+#             */
/*   Updated: 2022/06/19 21:32:28 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int argc, char *argv[])
{
	std::ifstream	finput;
	std::ofstream	foutput;
	std::string		content;
	int				position = 0;
	std::string		strline;
	size_t				result;


	if (argc != 4)
	{
		std::cout << "Wrong number of parameters. Got " << argc - 1 << " expected 3." << std::endl;
		return (1);
	}

	std::string filename(argv[1]);
	std::string	s1(argv[2]);
	std::string	s2(argv[3]);
	
	finput.open(argv[1]);
	foutput.open(filename + ".replace");
	char line[s1.length() * 2];

	while (finput.read(line, s1.length() * 2 - 1))		//! getline might not work when the string passed contains newlines.
	{
//		std::cout <<  finput.read(line, s1.length() * 2 - 1) << std::endl;
		line[s1.length() * 2 - 1] = 0;
		strline = line;
		position += s1.length();
		result = strline.find(s1);
		if (result != std::string::npos)
		{
			strline.erase(result, s1.length());
			strline.insert(result, s2);
			foutput << strline;
//			std::cout << "[" << strline << "]";
			position += s1.length() - 1;
		}
		else
		{
			strline.resize(s1.length());
			foutput << strline;
//			std::cout << "(" << strline << ")";

		}
		finput.seekg(position);
	}
	std::cout << line;			//! This is wrong as it doesn't account for a match right at the end of a file.
	finput.close();
	foutput.close();
	return (0);
}
