#include "converter.hpp"

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

	try
	{
		str_int = std::stoi(str);
	}
	catch (std::exception & e)
	{
		std::cout << "Error: The number given is formatted as an int but it represents an out-of-range value." << std::endl;
		return ;
	}
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
	try
	{
		str_float = std::stof(str, NULL);
	}
	catch (std::exception & e)
	{
		std::cout << "Error: The number given is formatted as a float but it represents an out-of-range value." << std::endl;
		return ;
	}
	

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
	try
	{
		str_double = std::stod(str, NULL);
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: The number given is formatted as a double but it represents an out-of-range value." << std::endl;
		return ;
	}
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
