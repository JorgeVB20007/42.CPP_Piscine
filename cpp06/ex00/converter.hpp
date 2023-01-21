/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:53:10 by jvacaris          #+#    #+#             */
/*   Updated: 2023/01/21 18:11:18 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANGETITLE_HPP
# define CHANGETITLE_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

#define MAX_FLOAT 340282346638528859811704183484516925440.0f
#define MIN_FLOAT -340282346638528859811704183484516925440.0f

enum e_type_of_value
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

struct s_str_characteristics
{
	bool has_sign;
	bool has_digits;
	bool has_decimal;
	bool has_others;
	bool final_f;
}	t_str_characteristics;


void is_char(std::string str);
void is_int(std::string str);
void is_float(std::string str);
void is_double(std::string str);

#endif