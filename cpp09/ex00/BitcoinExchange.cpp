/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:41:45 by jvacaris          #+#    #+#             */
/*   Updated: 2023/03/14 10:23:17 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


//?	Returns TRUE if the date is valid, FALSE if not
bool check_time_inconsistencies(struct tm *time)
{
	if (time->tm_mday > 30 && (time->tm_mon == 1 || time->tm_mon == 3 || time->tm_mon == 5 || time->tm_mon == 8 || time->tm_mon == 10))
		return false;
	else if (time->tm_mday == 30 && time->tm_mon == 1)
		return false;
	else if (time->tm_mday == 29 && time->tm_mon == 1)
	{
		if (!(time->tm_year + 1900 % 400))
			return true;
		else if (!(time->tm_year + 1900 % 100))
			return false;
		else if (!(time->tm_year + 1900 % 4))
			return true;
		return false;
	}
	return true;
}

void BitcoinExchange(std::ifstream *csvstream, std::ifstream *txtstream)
{
	std::string buffr;
	struct tm time_struct;
	time_t time;
	double value = 0.0f;
	std::map<time_t, float> prices;
	
	if (CSV_HAS_HEADER)
		getline(*csvstream, buffr);
	while (getline(*csvstream, buffr))
	{
		strptime(buffr.c_str(), "%Y-%m-%d", &time_struct);
		time = mktime(&time_struct);
		if (time == -1 || !check_time_inconsistencies(&time_struct) || buffr.size() < 10 || buffr[10] != ',')
		{
			std::cout << "Error: bad input -> " << buffr << std::endl;
		}
		else
		{
			value = std::stod(&buffr[11]);
			if (value < 0)
				std::cout << "Error: not a positive number." << std::endl;
			else if (value > 2147483647)
				std::cout << "Error: too large a number." << std::endl;
			prices[time] = value;
		}
	}

	getline(*txtstream, buffr);
	while (getline(*txtstream, buffr))
	{
		strptime(buffr.c_str(), "%Y-%m-%d", &time_struct);
		time = mktime(&time_struct);
		if (time == -1 || !check_time_inconsistencies(&time_struct) || buffr.size() < 14 || buffr[11] != '|' || buffr[12] != ' ')
		{
			std::cout << "Error: bad input => " << buffr << std::endl;
		}
		else
		{
			value = std::stod(&buffr[13]);
			if (value < 0)
				std::cout << "Error: not a positive number." << std::endl;
			else if (value > 2147483647)
				std::cout << "Error: too large a number." << std::endl;
			else
			{
				if (prices.begin()->first > time)
					std::cout << "Error: this date is not in the database." << std::endl;
				else
				{
					while (prices.find(time) == prices.end())
					{
						time = time - 200;
					}
					if (prices.find(time) == prices.end())
					{
						std::cout << "Error: this date is not in the database." << std::endl;
					}
					else
						std::cout << buffr.substr(0, 10) << " => " << &buffr[13] << " = " << prices[time] * value << std::endl;					
				}

			}
		}
	}
}
