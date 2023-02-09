#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

#define NOTIFS 0

template <class T>
class Array
{
	public:
		Array(): arr_size(0)
		{
			content = new T[0];
			if (NOTIFS)
				std::cout << "Array Default constructor called." << std::endl;
		}

		Array(unsigned int n): arr_size(n)
		{
			content = new T[n];
			if (NOTIFS)
				std::cout << "Array constructor called." << std::endl;
		}

		Array(const Array &tocopy): arr_size(tocopy.size())
		{
			*this = tocopy;
			if (NOTIFS)
				std::cout << "Array constructor called." << std::endl;
		}
		Array & operator = (const Array &toequalize)
		{
			content = toequalize.content;
		}

		Array & operator[] (const unsigned int idx)
		{
			if (idx >= arr_size)
				throw Array::ElementOutOfLimits();
			return (content[idx]);
		}

//!		~Array();


		const unsigned int &size() const
		{
			return (arr_size);
		}

		class ElementOutOfLimits: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return("Exception: Attempting to reach out of the Array's limits\n");
				}
		};

	private:
		const unsigned int arr_size;
		T	*content;
};

#endif