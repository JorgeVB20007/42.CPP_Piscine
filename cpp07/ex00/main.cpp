/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:57:51 by jvacaris          #+#    #+#             */
/*   Updated: 2023/02/06 19:33:12 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main()
{
	{
		std::cout << "\033[1;33m~~~ Testing using ints ~~~\033[0m" << std::endl;
		int x = 42;
		int y = 21;

		std::cout << "x = " << x << " | y = " << y << std::endl;
		::swap(x, y);
		std::cout << "x = " << x << " | y = " << y << std::endl;
		std::cout << "Min: " << ::min(x, y) << std::endl;
		std::cout << "Max: " << ::max(x, y) << std::endl << std::endl;
	}

	{
		std::cout << "\033[1;33m~~~ Testing using const ints ~~~\033[0m" << std::endl;
		const int x = 42;
		const int y = 21;

		std::cout << "(\033[1mswap\033[0m between const types cannot be done)" << std::endl;
		std::cout << "x = " << x << " | y = " << y << std::endl;
		std::cout << "Min: " << ::min(x, y) << std::endl;
		std::cout << "Max: " << ::max(x, y) << std::endl << std::endl;
	}

	{
		std::cout << "\033[1;33m~~~ Testing using chars ~~~\033[0m" << std::endl;
		char x = 'X';
		char y = 'D';

		std::cout << "x = " << x << " | y = " << y << std::endl;
		::swap(x, y);
		std::cout << "x = " << x << " | y = " << y << std::endl;
		std::cout << "Min: " << ::min(x, y) << std::endl;
		std::cout << "Max: " << ::max(x, y) << std::endl << std::endl;
	}
	
	{
		std::cout << "\033[1;33m~~~ Testing using floats ~~~\033[0m" << std::endl;
		float x = 12345.8f;
		float y = 12345.2f;

		std::cout << "x = " << x << " | y = " << y << std::endl;
		::swap(x, y);
		std::cout << "x = " << x << " | y = " << y << std::endl;
		std::cout << "Min: " << ::min(x, y) << std::endl;
		std::cout << "Max: " << ::max(x, y) << std::endl << std::endl;
	}

	{
		std::cout << "\033[1;33m~~~ Testing using pointers ~~~\033[0m" << std::endl;
		int temp[2];
		void *x = &temp[0];
		void *y = &temp[1];

		std::cout << "x = " << x << " | y = " << y << std::endl;
		::swap(x, y);
		std::cout << "x = " << x << " | y = " << y << std::endl;
		std::cout << "Min: " << ::min(x, y) << std::endl;
		std::cout << "Max: " << ::max(x, y) << std::endl << std::endl;
	}


	{
		std::cout << "\033[1;33m~~~ Testing using strings ~~~\033[0m" << std::endl;
		std::string x = "Test a";
		std::string y = "Test b";

		std::cout << "x = " << x << " | y = " << y << std::endl;
		::swap(x, y);
		std::cout << "x = " << x << " | y = " << y << std::endl;
		std::cout << "Min: " << ::min(x, y) << std::endl;
		std::cout << "Max: " << ::max(x, y) << std::endl << std::endl;
	}
	
}

