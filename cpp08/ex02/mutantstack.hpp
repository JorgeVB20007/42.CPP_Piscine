/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:21:19 by jvacaris          #+#    #+#             */
/*   Updated: 2023/02/22 23:23:10 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

#define NOTIFS 0

template<class T>
class MutantStack: public std::stack<T>
{
	public:
		typedef typename std::deque<T>::iterator iterator;
		MutantStack()
		{
			if (NOTIFS)
				std::cout << "Span default constructor called." << std::endl;
		}

		MutantStack(MutantStack &tocopy)
		{
			this->c = tocopy.c;
			if (NOTIFS)
				std::cout << "Span copy constructor called." << std::endl;
		}

		~MutantStack()
		{
			if (NOTIFS)
				std::cout << "Span default destructor called." << std::endl;
		}

		MutantStack & operator = (const MutantStack &toequalize)
		{
			this->c = toequalize.c;
			return (*this);
		}

		iterator begin()
		{
			return (this->c.begin());
		}

		iterator end()
		{
			return (this->c.end());
		}
};


#endif
