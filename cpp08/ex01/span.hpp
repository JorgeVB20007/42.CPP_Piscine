/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:37:11 by jvacaris          #+#    #+#             */
/*   Updated: 2023/02/20 21:26:36 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define NOTIFS 0

class Span
{
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &tocopy);
		Span & operator = (const Span &toequalize);
		~Span();
		void addNumber(int newnum);
		void addNumberRange(int minnum, int maxnum);
		int shortestSpan();
		int longestSpan();
		std::string show() const;

		class SpanFull: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return("Exception: Can't add new items!\n");
				}
		};

		class ShortSpan: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return("Exception: Can't get the span without at least two values!\n");
				}
		};

	private:
		std::vector<int> values;
		unsigned int n;
};

std::ostream & operator << (std::ostream &output, Span const &toprint);

#endif
