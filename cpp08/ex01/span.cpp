/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:21:14 by jvacaris          #+#    #+#             */
/*   Updated: 2023/02/19 22:15:05 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(): n(0)
{
	if (NOTIFS)
		std::cout << "Span default constructor called." << std::endl;
}

Span::Span(unsigned int _n): n(_n)
{
	if (NOTIFS)
		std::cout << "Span constructor called." << std::endl;
}

Span::Span(const Span &tocopy)
{
	if (NOTIFS)
		std::cout << "Span copy constructor called." << std::endl;
	*this = tocopy;
}

Span & Span::operator = (const Span &toequalize)
{
	if (NOTIFS)
		std::cout << "Span assignation operator called." << std::endl;
	n = toequalize.n;
	values = toequalize.values;
	return (*this);
}

Span::~Span()
{
	if (NOTIFS)
		std::cout << "Span default destructor called." << std::endl;

}

void Span::addNumber(int newnum)
{
	if (values.size() < n)
	{
		values.push_back(newnum);
	}
	else
	{
		throw Span::SpanFull();
	}
}

void Span::addNumberRange(int minnum, int maxnum)
{
	int i = minnum;
	bool last = false;

	while (i != maxnum || last)
	{
		if (values.size() < n)
		{
			values.push_back(i);
			if (minnum < maxnum)
				i++;
			else
				i--;
			if (last)
				return ;
			if (i == maxnum)
				last = true;

		}
		else
			throw Span::SpanFull();
	}
}

int Span::shortestSpan()
{
	int shortest = 2147483647;

	if (values.size() < 2)
		throw Span::ShortSpan();
	Span spncpy(*this);
	std::sort(spncpy.values.begin(), spncpy.values.end());
	for (unsigned int i = 0; i < values.size() - 1; i++)
	{
		if (spncpy.values[i + 1] - spncpy.values[i] < shortest)
			shortest = spncpy.values[i + 1] - spncpy.values[i];
	}
	return (shortest);
}

int Span::longestSpan()
{
	if (values.size() < 2)
		throw Span::ShortSpan();
	return (*std::max_element(values.begin(), values.end()) - *std::min_element(values.begin(), values.end()));
}

std::string Span::show()
{
	std::string retval;

	retval = retval + "{ ";
	for (unsigned int i = 0; i < n; i++)
	{
		retval = retval + std::to_string(values[i]) + " ";
	}
	retval = retval + "}";
	return (retval);
}
