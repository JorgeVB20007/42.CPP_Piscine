/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:50:52 by jvacaris          #+#    #+#             */
/*   Updated: 2023/01/21 20:50:31 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.hpp"

static struct s_str_characteristics get_str_facts(std::string str)
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
		else if ((str[a] != 'f' && str[a] != 'F') || !(!str[a + 1] && (str[a] == 'f' || str[a] == 'F')))
		{
			facts.has_others = true;
		}
	}
	if (str[a - 1] == 'f' || str[a - 1] == 'F')
		facts.final_f = true;
	else
		facts.final_f = false;
	return (facts);
}

static int identify_type(std::string str)
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

int main(int argc, char **argv)
{
	int type;

	if (argc != 2)
	{
		if (argc < 2)
			std::cerr << "Please introduce a value." << std::endl;
		if (argc > 2)
			std::cerr << "Only one value is allowed." << std::endl;
		return (1);
	}
	
	type = identify_type(argv[1]);
	if (type == CHAR)
		is_char(argv[1]);
	if (type == INT)
		is_int(argv[1]);
	if (type == FLOAT)
		is_float(argv[1]);
	if (type == DOUBLE)
		is_double(argv[1]);
	if (type == -1)
	{
		std::cout << "Error: Value type not found." << std::endl;
		return (2);
	}
	return (0);
}

