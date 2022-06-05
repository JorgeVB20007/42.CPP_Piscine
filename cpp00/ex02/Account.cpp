/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:43:37 by jvacaris          #+#    #+#             */
/*   Updated: 2022/06/02 21:07:18 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <cmath>

Account::Account (int initial_deposit)
{
	_totalAmount = initial_deposit;
}

static void printNum_withZeroes(int digits, int number)
{
	int a = 0;
	if (number == 0)
	{
		while(a < digits)
		{
			std::cout << "0";
			a++;
		}
	}
	else
	{
		a = log10(number);

		while(a + 1 < digits)
		{
			std::cout << "0";
			a++;
		}
		std::cout << number;		
	}

}

static void _displayTimestamp(void)
{
	time_t now = time(0);

	tm* localtm = localtime(&now);

	std::cout << "[";
	printNum_withZeroes(4, localtm->tm_year + 1900);
	printNum_withZeroes(2, localtm->tm_mon);
	printNum_withZeroes(2, localtm->tm_mday);
	std::cout << "_";
	printNum_withZeroes(2, localtm->tm_hour);
	printNum_withZeroes(2, localtm->tm_min);
	printNum_withZeroes(2, localtm->tm_sec);
	std::cout << "]" << std::endl;
}
