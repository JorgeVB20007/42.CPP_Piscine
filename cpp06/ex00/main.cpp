/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:50:52 by jvacaris          #+#    #+#             */
/*   Updated: 2023/01/21 17:51:13 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.hpp"

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

	std::cout << "char: '" << str_char << "'" << std::endl;
	std::cout << "int: " << str_int << std::endl;
	std::cout << "float: " << str_float << ".0f" << std::endl;
	std::cout << "double: " << str_double << ".0" << std::endl;
}

void is_int(std::string str)
{
	char str_char;
	int str_int;
	float str_float;
	double str_double;

	str_int = std::stoi(str);
	if (str_int >= 32 && str_int <= 126)
	{
		str_char = (char)str_int;
		std::cout << "char: '" << str_char << "'" << std::endl;
	}
	else if (str_int < -127 || str_int > 127)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	str_float = (float)str_int;
	str_double = (double)str_int;

	std::cout << "int: " << str_int << std::endl;
	std::cout << "float: " << str_float << ".0f" << std::endl;
	std::cout << "double: " << str_double << ".0" << std::endl;
}

void is_float(std::string str)
{
	char str_char;
	int str_int;
	float str_float;
	double str_double;

	std::cout.precision(10);
	str_float = std::stof(str, NULL);

	if (str_float >= 32.0f && str_float < 127.0f)
	{
		str_char = (char)str_float;
		std::cout << "char: '" << str_char << "'" << std::endl;
	}
	else if (str_float < -127.0f || str_float > 128.0f || str == "nanf")
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (str_float < -2147483648.0f || str_float >= 2147483648.0f || str == "nanf")
	{
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		str_int = (int)str_float;
		std::cout << "int: " << str_int << std::endl;
	}

	str_double = (double)str_float;
	std::cout << "float: " << str_float;
	if (!(str_float - floorf(str_float)))
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;
	std::cout << "double: " << str_double;
	if (!(str_double - floorf(str_double)))
		std::cout << ".0";
	std::cout << std::endl;
}

void is_double(std::string str)
{
	char str_char;
	int str_int;
	float str_float;
	double str_double;

	std::cout.precision(10);
	str_double = std::stod(str, NULL);
	if (str_double >= 32.0 && str_double < 127.0)
	{
		str_char = (char)str_double;
		std::cout << "char: '" << str_char << "'" << std::endl;
	}
	else if (str_double < -127.0 || str_double > 128.0 || str == "nan")
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (str_double < -2147483648.0 || str_double >=  2147483648.0 || str == "nan")
	{
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		str_int = (int)str_double;
		std::cout << "int: " << str_int << std::endl;
	}

	if (str == "+inf" || str == "-inf")
		std::cout << "float: " << str << "f" << std::endl;
	else if (str_double < MIN_FLOAT || str_double > MAX_FLOAT)
		std::cout << "float: impossible" << std::endl;
	else
	{
		str_float = (float)str_double;
		std::cout << "float: " << str_float;
		if (!(str_float - floorf(str_float)))
			std::cout << ".0f" << std::endl;
		else
			std::cout << "f" << std::endl;
	}


	std::cout << "double: " << str_double;
	if (!(str_double - floorf(str_double)))
		std::cout << ".0";
	std::cout << std::endl;
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

