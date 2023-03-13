/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:37:56 by jvacaris          #+#    #+#             */
/*   Updated: 2023/03/13 18:54:06 by jvacaris         ###   ########.fr       */
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

void print_best_unit(long nanosec)
{
	long nanosec_cpy = nanosec;
	double nanosec_dbl = -1.0;
	int idx = 0;
	std::string units = "num ";

	while (nanosec_cpy > 1000 && idx <= 2)
	{
		if (nanosec_cpy < 1000000)
			nanosec_dbl = nanosec_cpy / 1000.0;
		nanosec_cpy = nanosec_cpy / 1000;
		idx++;
	}
	if (nanosec_dbl == -1.0)
		std::cout << nanosec_cpy << " " << units[idx] << "s" << std::endl;
	else
		std::cout << nanosec_dbl << " " << units[idx] << "s" << std::endl;
}

void print_vector(std::vector<int> the_vector, std::string prefix)
{
	std::cout << prefix;
	for (std::vector<int>::iterator it = the_vector.begin(); it != the_vector.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


static void single_parser(char *argv, std::vector<int> *the_vector, std::deque<int> *the_deque)
{
	int a_number;
	for (int idx = 0; argv[idx]; idx++)
	{
		while (argv[idx] == ' ')
			idx++;
		if (!isdigit(argv[idx]))
			throw ExtraneousChars();
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

static void multi_parser(int argc, char **argv, std::vector<int> *the_vector, std::deque<int> *the_deque)
{
	for (int idx = 1; idx < argc; idx++)
	{
		single_parser(argv[idx], the_vector, the_deque);
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
			return (1);
		}
	}
	else
	{
		try
		{
			multi_parser(argc, argv, &the_vector, &the_deque);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			return (1);
		}
	}

	if (std::is_sorted(the_vector.begin(), the_vector.end()))
	{
		print_vector(the_vector, "Before:	");
		print_vector(the_vector, "After:	");
		std::cout << "INFO: The sequence is already sorted, so no operations were executed." << std::endl;
	}
	else
	{
		struct timespec time_struct_vector_start;
		struct timespec time_struct_vector_end;
		struct timespec time_struct_deque_start;
		struct timespec time_struct_deque_end;

		print_vector(the_vector, "Before:	");
		clock_gettime(CLOCK_REALTIME, &time_struct_vector_start);
		the_vector = PmergeMe_vector(the_vector);
		clock_gettime(CLOCK_REALTIME, &time_struct_vector_end);
		clock_gettime(CLOCK_REALTIME, &time_struct_deque_start);
		the_deque = PmergeMe_deque(the_deque);
		clock_gettime(CLOCK_REALTIME, &time_struct_deque_end);
		print_vector(the_vector, "After:	");

		std::cout << "Time to process a range of " << the_vector.size() << " elements with std::vector : ";
		print_best_unit((time_struct_vector_end.tv_nsec + (time_struct_vector_end.tv_sec - time_struct_vector_start.tv_sec) * 1000000000) - time_struct_vector_start.tv_nsec);
		std::cout << "Time to process a range of " << the_vector.size() << " elements with std::deque  : ";
		print_best_unit((time_struct_deque_end.tv_nsec + (time_struct_deque_end.tv_sec - time_struct_deque_start.tv_sec) * 1000000000) - time_struct_deque_start.tv_nsec);

	}

	return (0);
}