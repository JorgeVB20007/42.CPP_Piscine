/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:01:02 by jvacaris          #+#    #+#             */
/*   Updated: 2023/01/22 19:28:42 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

#include <iostream>


typedef struct Data
{
	int the_data;
} Data;


uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);


#endif