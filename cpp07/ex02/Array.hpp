#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

#define NOTIFS 0

template <class T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &tocopy);
		Array & operator = (const Array &toequalize);
		~Array();
		const unsigned int size() const

		class ElementOutOfLimits: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return("Exception: Attempting to reach out of the Array's limits\n");
				}
		}

	private:
		const unsigned int arr_size;
		T	*content;
};

template <class T>
Array<T>::Array(): arr_size(0)
{
	content = new[0]
	if (NOTIFS)
		std::cout << "Array Default constructor called." << std::endl;
}

template <class T>
Array<T>::Array(unsigned int n): arr_size(n)
{
	content = new[n]
	if (NOTIFS)
		std::cout << "Array constructor called." << std::endl;
}

template <class T>
Array<T>::Array(const Array &tocopy): arr_size(tocopy.size())
{
	*this = tocopy;
	if (NOTIFS)
		std::cout << "Array constructor called." << std::endl;
}

template <class T>
Array<T> & Array<T>::operator = (const Array &toequalize)
{
	content = toequalize.content;
}

#endif