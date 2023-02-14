/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:36:13 by jvacaris          #+#    #+#             */
/*   Updated: 2023/02/14 22:43:03 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int>first_vector {2, 4, 6, 8, 10};

	first_vector.push_back(21);
	first_vector.push_back(42);
	first_vector.push_back(1337);
	easyfind(first_vector, 4);
}

