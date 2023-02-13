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

		Array(const Array &tocopy)
		{
			content = NULL;
			*this = tocopy;
			if (NOTIFS)
				std::cout << "Array constructor called." << std::endl;
		}

		Array & operator = (const Array &toequalize)
		{
			if (content)
				delete content;
			content = new T[toequalize.size()];
			arr_size = toequalize.size();
			for (unsigned int i = 0; i < toequalize.size(); i++)
				content[i] = toequalize[i];
			return (*this);
		}

		T & operator[] (const unsigned int idx) const
		{
			if (NOTIFS)
				std::cout << "Index " << idx << " accessed through operator []" << std::endl;
			if (idx >= arr_size)
				throw Array::ElementOutOfLimits();
			return (content[idx]);
		}

		~Array()
		{
			delete[] this->content;
			if (NOTIFS)
				std::cout << "Array destructor called." << std::endl;
		}


		const unsigned int &size() const
		{
			return (arr_size);
		}

		void print()
		{
			std::cout << "-- ARRAY SIZE: " << arr_size << " --" << std::endl;
			for (unsigned int i = 0; i < arr_size; i++)
			{
				std::cout << i << ": " << content[i] << std::endl;
			}
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
		unsigned int arr_size;
		T	*content;
};

#endif