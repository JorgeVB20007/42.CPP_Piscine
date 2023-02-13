/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:57:51 by jvacaris          #+#    #+#             */
/*   Updated: 2023/02/13 19:01:08 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	//?		Creating array of ints.
	Array<int> integers(4);
	integers[0] = 42;
	integers[1] = 21;
	integers[2] = 19;
	integers[3] = 1337;
	try
	{
		integers[4] = 123456;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	//?		Manually printing the array.
	try
	{
		int idx = 0;
		while (1)
		{
			std::cout << "Index " << idx << " | Value " << integers[idx] << std::endl;
			idx++;
		}

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	
	
	//?		Creating array of two arrays and assigning them values.
	Array< Array<char> > megarray(2);
	Array<char> b(5);
	Array<char> c(7);
	
	try
	{
		int i = 0;
		while (1)
		{
			b[i] = (i % 26) + 'a';
			i++;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		int i = 0;
		while (1)
		{
			c[i] = (i % 26) + 'A';
			i++;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	megarray[0] = b;
	megarray[1] = c;

	//?		Printing them with the template's print() function
	megarray[0].print();
	megarray[1].print();

	//?		Creating and printing an Array of std::string
	Array<std::string> strings(5);
	strings[0] = "Somebody once told me the world is gonna roll me";
	strings[1] = "I ain't the sharpest tool in the shed";
	strings[2] = "She was looking kind of dumb with her finger and her thumb";
	strings[3] = "In the shape of an \"L\" on her forehead";
	strings[4] = "Well";
	strings.print();
}

