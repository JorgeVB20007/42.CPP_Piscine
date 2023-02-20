/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:21:19 by jvacaris          #+#    #+#             */
/*   Updated: 2023/02/20 22:20:18 by jvacaris         ###   ########.fr       */
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
		typedef typename MutantStack::iterator iterator;

		MutantStack()
		{
			if (NOTIFS)
				std::cout << "Span default constructor called." << std::endl;
		}

		MutantStack(MutantStack &tocopy)
		{
			this = tocopy;
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
			//! -------------
			(void)toequalize;
			//! -------------
			return (*this);
		}

		iterator begin()
		{
			return (this[0]);
		}

		iterator end()
		{
			return (this[this->size() - 1]);
		}

};


#endif
