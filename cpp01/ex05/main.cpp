/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:18:04 by jvacaris          #+#    #+#             */
/*   Updated: 2022/06/22 22:15:50 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main()
{
	Karen pence;
	
	std::cout << "\033[0;33m   --------------------   \033[0m";
	std::cout << std::endl << "\033[0;36mPrinting DEBUG:\033[0m" << std::endl;
	pence.complain("debug");
	std::cout << std::endl << "\033[0;36mPrinting INFO:\033[0m" << std::endl;
	pence.complain("info");
	std::cout << std::endl << "\033[0;36mPrinting WARNING:\033[0m" << std::endl;
	pence.complain("warning");
	std::cout << std::endl << "\033[0;36mPrinting ERROR:\033[0m" << std::endl;
	pence.complain("error");
	std::cout << std::endl << "\033[0;36mPrinting THE MASSIVE ERROR:\033[0m" << std::endl;
	pence.complain("idk");
	std::cout << "\033[0;33m   --------------------   \033[0m" << std::endl;
}
