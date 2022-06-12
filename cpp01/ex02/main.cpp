/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 22:04:53 by jvacaris          #+#    #+#             */
/*   Updated: 2022/06/12 22:23:03 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string str;
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	str = "HI THIS IS BRAIN";
	std::cout << "\033[0;33mAddress of the string:\033[0m" << std::endl;
	std::cout << &str << std::endl;
	

	std::cout << "\033[0;33mAddress of the string (stringPTR):\033[0m" << std::endl;
	std::cout << stringPTR << std::endl;

	std::cout << "\033[0;33mAddress of the string (stringREF):\033[0m" << std::endl;
	std::cout << &stringREF << std::endl << std::endl;


	std::cout << "\033[0;33mString (stringPTR):\033[0m" << std::endl;
	std::cout << *stringPTR << std::endl;

	std::cout << "\033[0;33mString (stringREF):\033[0m" << std::endl;
	std::cout << stringREF << std::endl;
}
