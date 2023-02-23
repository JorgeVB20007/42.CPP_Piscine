/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:36:13 by jvacaris          #+#    #+#             */
/*   Updated: 2023/02/23 18:35:44 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	//?	Testing using int vectors
	{
		std::cout << std::endl << "\033[1;33m~~~ Testing using a vector of ints ~~~\033[0m" << std::endl;
		std::vector<int>first_vector;

		first_vector.push_back(19);
		first_vector.push_back(21);
		first_vector.push_back(42);
		first_vector.push_back(1337);

		std::cout << "Is 1337 in vector? -> " << easyfind(first_vector, 1337) << std::endl;
		std::cout << "Is 5 in vector?    -> " << easyfind(first_vector, 5) << std::endl;
		std::cout << "Is 123 in vector?  -> " << easyfind(first_vector, 123) << std::endl;
		std::cout << "Is 42 in vector?   -> " << easyfind(first_vector, 42) << std::endl;
	}


	//?	Testing using int arrays
	{
		std::cout << std::endl << "\033[1;33m~~~ Testing using an array of ints ~~~\033[0m" << std::endl;
		std::array<int, 10>first_array = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

		std::cout << "Is 9 in array?    -> " << easyfind(first_array, 9) << std::endl;
		std::cout << "Is 32 in array?   -> " << easyfind(first_array, 32) << std::endl;
		std::cout << "Is 42 in array?   -> " << easyfind(first_array, 42) << std::endl;
		std::cout << "Is 128 in array?  -> " << easyfind(first_array, 128) << std::endl;
		std::cout << "Is 1024 in array? -> " << easyfind(first_array, 1024) << std::endl;
	}


	//?	Testing using int arrays
	{
		std::cout << std::endl << "\033[1;33m~~~ Testing using a constant array of constant ints ~~~\033[0m" << std::endl;
		const std::array<const int, 7>first_array = {2048, 4096, 8192, 16384, 32768, 65536, 131072};

		std::cout << "Is 16384 in array?  -> " << easyfind(first_array, 16384) << std::endl;
		std::cout << "Is 123456 in array? -> " << easyfind(first_array, 123456) << std::endl;
		std::cout << "Is -42 in array?    -> " << easyfind(first_array, -42) << std::endl;
		std::cout << "Is 2048 in array?   -> " << easyfind(first_array, 2048) << std::endl;
		std::cout << "Is 1024 in array?   -> " << easyfind(first_array, 1024) << std::endl;
	}

	//?	Testing using int lists
	{
		std::cout << std::endl << "\033[1;33m~~~ Testing using a list of ints ~~~\033[0m" << std::endl;
		std::list<int>first_list;

		first_list.push_back(42);
		first_list.push_back(420);
		first_list.push_back(4200);
		first_list.push_back(42000);
		first_list.push_back(420000);

		std::cout << "Is 42 in list? -> " << easyfind(first_list, 42) << std::endl;
		std::cout << "Is 421 in list? -> " << easyfind(first_list, 421) << std::endl;
		std::cout << "Is 4200 in list? -> " << easyfind(first_list, 4200) << std::endl;
		std::cout << "Is 21000 in list? -> " << easyfind(first_list, 21000) << std::endl;
		std::cout << "Is 420000 in list? -> " << easyfind(first_list, 420000) << std::endl;
	}
}

