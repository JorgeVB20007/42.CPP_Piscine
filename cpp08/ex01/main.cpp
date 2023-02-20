/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:21:17 by jvacaris          #+#    #+#             */
/*   Updated: 2023/02/20 21:25:55 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main()
{
	{
		std::cout << std::endl << "\033[1;33m~~~ Span of 4 values ~~~\033[0m" << std::endl;
		Span test_one(4);

		try
		{
			test_one.addNumber(42);
			test_one.addNumber(19);
			test_one.addNumber(21);
			test_one.addNumber(1337);
			test_one.addNumber(33);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		std::cout << "Span values: " << test_one << std::endl;
		std::cout << "Shortest span: " << test_one.shortestSpan() << std::endl;
		std::cout << "Longest span: " << test_one.longestSpan() << std::endl;
	}

	{
		std::cout << std::endl << "\033[1;33m~~~ Span of 15000 values ~~~\033[0m" << std::endl;

		Span test_two(15000);

		try
		{
			std::cout << "Adding the first 10k numbers." << std::endl;
			test_two.addNumberRange(-2000, 7999);
			std::cout << "Adding the next 5k numbers." << std::endl;
			test_two.addNumberRange(-42000, -37001);
			std::cout << "Span should now be full. Trying to add 2 more numbers." << std::endl;
			test_two.addNumberRange(50000, 50001);
			std::cout << "THIS SHOULD NOT APPEAR" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "Shortest span: " << test_two.shortestSpan() << std::endl;
		std::cout << "Longest span: " << test_two.longestSpan() << std::endl;
	}

	{
		std::cout << std::endl << "\033[1;33m~~~ Span of 1 value ~~~\033[0m" << std::endl;
		Span test_three(1);

		try
		{
			test_three.addNumber(42);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "Span values: " << test_three << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "Shortest span: " << test_three.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "Longest span: " << test_three.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout << std::endl << "\033[1;33m~~~ Size 5 Span with 3 values ~~~\033[0m" << std::endl;
		Span test_four(5);

		test_four.addNumber(21);
		test_four.addNumber(42);
		test_four.addNumber(84);
		std::cout << "Span values: " << test_four << std::endl;
		std::cout << "Shortest span: " << test_four.shortestSpan() << std::endl;
		std::cout << "Longest span: " << test_four.longestSpan() << std::endl;
	}
	std::cout << std::endl << "\033[1;33m~~~ Done ~~~\033[0m" << std::endl;
}
