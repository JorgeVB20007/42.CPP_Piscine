/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:43:37 by jvacaris          #+#    #+#             */
/*   Updated: 2022/06/07 20:04:52 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <cmath>

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

void Account::_displayTimestamp(void)
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
	std::cout << "] ";
}

void Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;

	_amount = _amount + deposit;
	_totalAmount = _totalAmount + deposit;
	_nbDeposits = _nbDeposits + 1;
	_totalNbDeposits = getNbDeposits() + 1;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}	

bool Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return (0);
	}
	_amount = _amount - withdrawal;
	_totalAmount = getTotalAmount() - withdrawal;
	_nbWithdrawals = _nbWithdrawals + 1;
	_totalNbWithdrawals = getNbWithdrawals() + 1;
	std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (1);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals <<  std::endl;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

Account::Account (int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_totalAmount = getTotalAmount() + initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	_nbAccounts = _nbAccounts + 1;
	std::cout << "index:" << _accountIndex << ";amount:" << initial_deposit << ";created" << std::endl; 
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl; 
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
