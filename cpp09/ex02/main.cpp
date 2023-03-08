/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:37:56 by jvacaris          #+#    #+#             */
/*   Updated: 2023/03/08 22:48:21 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void the_printer(std::vector<int> the_vector, std::deque<int> the_deque)
{
	std::cout << "----- Vector -----" << std::endl;
	for (std::vector<int>::iterator it = the_vector.begin(); it != the_vector.end(); it++)
	{
		std::cout << "(" << *it << ") ";
	}
	std::cout << std::endl << std::endl << "----- DEQue -----" << std::endl;
	for (std::deque<int>::iterator it = the_deque.begin(); it != the_deque.end(); it++)
	{
		std::cout << "(" << *it << ") ";
	}
	std::cout << std::endl;
}


static void multi_parser(int argc, char **argv, std::vector<int> *the_vector, std::deque<int> *the_deque)
{
	
}

static void single_parser(char *argv, std::vector<int> *the_vector, std::deque<int> *the_deque)
{
	int a_number;
	for (int idx = 0; argv[idx]; idx++)
	{
		if (!isdigit(argv[idx]))
		{
			std::cout << "Index: " << idx << " | Char: " << argv[idx] << std::endl;
			throw ExtraneousChars();
		}
			
		a_number = std::stoi(&argv[idx]);
		the_vector->push_back(a_number);
		the_deque->push_back(a_number);
		while (argv[idx] && argv[idx] != ' ')
		{
			if (!isdigit(argv[idx]))
				throw ExtraneousChars();
			idx++;
		}
		if (!argv[idx])
			break;
	}
}

int main(int argc, char **argv)
{
	std::vector<int> the_vector;
	std::deque<int> the_deque;
	if (argc < 2)
	{
		std::cout << "Error: At least one argument's required." << std::endl;
		return (1);
	}
	else if (argc == 2)
	{
		try
		{
			single_parser(argv[1], &the_vector, &the_deque);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	the_printer(the_vector, the_deque);
	
	return (0);
}