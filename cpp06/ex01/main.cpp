/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:23:08 by jvacaris          #+#    #+#             */
/*   Updated: 2023/01/22 19:42:39 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialization.hpp"

int main()
{
	{
		Data		*test_data = new Data;
		uintptr_t	test_uint;
		Data		*ret_value;


		test_data->the_data = 42;
		test_uint = serialize(test_data);
		ret_value = deserialize(test_uint);

		std::cout << "Initial value: " << test_data->the_data << std::endl;
		std::cout << "Current value: " << ret_value->the_data << std::endl;
		std::cout << "Serialized value: " << test_uint << std::endl;
		delete test_data;
	}

	return (0);
}
