/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:50:52 by jvacaris          #+#    #+#             */
/*   Updated: 2022/11/30 22:19:11 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "changetitle.hpp"

struct s_str_characteristics get_str_facts(std::string str)
{
	struct s_str_characteristics facts;
	int a = -1;

	facts.has_sign = false;
	facts.has_digits = false;
	facts.has_decimal = false;
	facts.has_others = false;
	while (str[++a])
	{
		if (str[a] == '+' || str[a] == '-')
			facts.has_sign = true;
		else if (str[a] >= '0' && str[a] <= '9')
			facts.has_digits = true;
		else if (str[a] == '.')
			facts.has_decimal = true;
		else
			facts.has_others = true;
	}
	if (str[a - 1] == 'f' || str[a - 1] == 'F')
		facts.final_f = true;
	else
		facts.final_f = false;
	return (facts);
}

int identify_type(std::string str)
{
	struct s_str_characteristics facts;
	
	facts = get_str_facts(str);
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return(FLOAT);
	if (str == "-inf" || str == "+inf" || str == "nan")
		return(DOUBLE);
	if (str.length() == 1 && str[0] >= 32 && str[0] <= 126 && !facts.has_digits)
		return(CHAR);
	if (facts.has_others || !facts.has_digits)
		return(-1);
	if (!facts.has_decimal)
		return(INT);
	if (facts.has_decimal && facts.final_f)
		return(FLOAT);
	if (facts.has_decimal && !facts.final_f)
		return(DOUBLE);
	return(-1);
	
}


void is_char(std::string str)
{
	char str_char;
	int str_int;
	float str_float;
	double str_double;

	str_char = str[0];
	str_int = (int)str[0];
	str_float = (float)str[0];
	str_double = (double)str[0];

	std::cout << "char: " << str_char << std::endl;
	std::cout << "int: " << str_int << std::endl;
	std::cout << "float: " << str_float << std::endl;
	std::cout << "double: " << str_double << std::endl;
}

int main(int argc, char **argv)
{
	int type;
	
	if (argc != 2)
		return (1);
	
	type = identify_type(argv[1]);
	if (type == CHAR)
		is_char(argv[1]);




/*	char chr = '*';
	int itg = 21;
	float flt = 5.1f;
	double dbl = 42.0;

	std::cout << chr << " | " << itg << " | " << flt << " | " << dbl << std::endl;*/
}
