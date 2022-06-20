/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:18:04 by jvacaris          #+#    #+#             */
/*   Updated: 2022/06/20 22:32:48 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main()
{
	Karen pence;
	
	std::cout << std::endl << "   ----------   " << std::endl;
	std::cout << std::endl << "Printing DEBUG:" << std::endl;
	pence.complain("debug");
	std::cout << std::endl << "Printing INFO:" << std::endl;
	pence.complain("info");
	std::cout << std::endl << "Printing WARNING:" << std::endl;
	pence.complain("warning");
	std::cout << std::endl << "Printing ERROR:" << std::endl;
	pence.complain("error");
	std::cout << std::endl << "   ----------   " << std::endl;
}
