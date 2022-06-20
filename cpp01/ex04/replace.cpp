/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:42:52 by jvacaris          #+#    #+#             */
/*   Updated: 2022/06/20 20:47:48 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

static void reset_line(char *str, int size)
{
	int a = 0;

	while (a < size)
	{
		str[a] = 0;
		a++;
	}
}

int ft_replacer(char *argv[])
{
	std::ifstream	finput;
	std::ofstream	foutput;
	int				position = 0;
	std::string		strline;
	size_t			result;
	int				stop = 0;

	std::string filename(argv[1]);
	std::string	s1(argv[2]);
	std::string	s2(argv[3]);
	
	finput.open(argv[1]);
	if (!finput.is_open())
	{
		std::cerr << "Something went wrong when opening the file \"" << filename << "\"." << std::endl;
		return (1);
	}
	foutput.open(filename + ".replace");
	if (!foutput.is_open())
	{
		std::cerr << "Something went wrong when creating/editing the file \"" << filename << ".replace\"." << std::endl;
		return (1);
	}
	char line[s1.length() * 2];

	while (!stop)
	{
		reset_line(line, s1.length() * 2);
		if (!(finput.read(line, s1.length() * 2 - 1)))
			stop = 1;
		line[s1.length() * 2 - 1] = 0;
		strline = line;
		position += s1.length();
		result = strline.find(s1);
		if (result != std::string::npos)
		{
			strline.erase(result, s1.length());
			strline.insert(result, s2);
			foutput << strline;
			position += s1.length() - 1;
		}
		else
		{
			if (!stop)
				strline.resize(s1.length());
			foutput << strline;
		}
		finput.seekg(position);
	}
	finput.close();
	foutput.close();
	return (0);


}
