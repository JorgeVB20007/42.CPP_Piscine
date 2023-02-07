/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:57:51 by jvacaris          #+#    #+#             */
/*   Updated: 2023/02/06 20:38:09 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

//*		vvvv  TEST FUNCTIONS  vvvv


template <class t_iter>
void ft_addone(t_iter &arry)
{
	arry++;
}

void ft_touppercase(std::string &arry)
{
	for (size_t i = 0; arry[i]; i++)
	{
		if (arry[i] >= 'a' && arry[i] <= 'z')
			arry[i] -= 32;
	}
}

template <class t_iter>
void ft_print_item(const t_iter item)
{
	std::cout << item << " ";
}

//*		^^^^  TEST FUNCTIONS  ^^^^

int main()
{
	{
		std::cout << "\033[1;33m~~~ Testing using ints ~~~\033[0m" << std::endl;
		int arry[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
		int size = 10;
		::iter(arry, size, ft_print_item);
		std::cout << std::endl;
		::iter(arry, size, ft_addone);
		::iter(arry, size, ft_print_item);
		std::cout << std::endl << std::endl;
	}

	{
		std::cout << "\033[1;33m~~~ Testing using const ints ~~~\033[0m" << std::endl;
		const int arry[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
		int size = 10;
		::iter(arry, size, ft_print_item);
		std::cout << std::endl << std::endl;
	}

	{
		std::cout << "\033[1;33m~~~ Testing using floats ~~~\033[0m" << std::endl;
		float arry[] = {2.1f, 4.2f, 6.3f, 8.4f, 10.5f, 12.6f, 14.7f, 16.8f};
		int size = 8;
		::iter(arry, size, ft_print_item);
		std::cout << std::endl;
		::iter(arry, size, ft_addone);
		::iter(arry, size, ft_print_item);
		std::cout << std::endl << std::endl;
	}

	{
		std::cout << "\033[1;33m~~~ Testing using strings ~~~\033[0m" << std::endl;
		std::string arry[] = {"Larry", "Harry", "Gerry", "Terry", "Mary"};
		int size = 5;
		::iter(arry, size, ft_print_item);
		std::cout << std::endl;
		::iter(arry, size, ft_touppercase);
		::iter(arry, size, ft_print_item);
		std::cout << std::endl << std::endl;
	}

	{
		std::cout << "\033[1;33m~~~ Testing using chars ~~~\033[0m" << std::endl;
		char arry[] = {"aBcDeFgHiJk"};
		int size = 11;
		::iter(arry, size, ft_print_item);
		std::cout << std::endl;
		::iter(arry, size, ft_addone);
		::iter(arry, size, ft_print_item);
		std::cout << std::endl << std::endl;
	}

	{
		std::cout << "\033[1;33m~~~ Testing using pointers ~~~\033[0m" << std::endl;
		char temp[] = {"12345"};
		void *arry[5];
		int size = 5;
		for (int i = 0; i < size; i++)
		{
			arry[i] = &temp[i];
		}
		::iter(&arry, size, ft_print_item);
		std::cout << std::endl;
	}

}

