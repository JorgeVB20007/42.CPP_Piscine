/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:18:37 by jvacaris          #+#    #+#             */
/*   Updated: 2023/02/22 23:07:29 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"


int main()
{
	std::cout << std::endl << "\033[1;33m~~~ Stack of strings ~~~\033[0m" << std::endl;
	{
		MutantStack<std::string> first;

		first.push("Mercury");
		first.push("Venus");
		first.push("Earth");
		first.push("Mars");
		first.push("Jupiter");
		first.push("Saturn");
		first.push("Uranus");
		first.push("Neptune");
		first.push("Pluto");

		std::cout << "Stack size: " << first.size() << std::endl;
		first.pop();
		std::cout << "Stack size: " << first.size() << std::endl;

		MutantStack<std::string>::iterator first_start = first.begin();
		MutantStack<std::string>::iterator first_end = first.end() - 1;

		while (first_start != first_end)
		{
			std::cout << *first_start << " | " << *first_end << std::endl;
			first_start++;
			if (first_start == first_end)
				break ;
			first_end--;
			if (first_start == first_end)
				std::cout << " | " << *first_start << " |" << std::endl;
		}

	}

	std::cout << std::endl << "\033[1;33m~~~ Stack of floats ~~~\033[0m" << std::endl;
	{
		MutantStack<float> second;
		float result = 0.0f;

		second.push(0.99f);
		second.push(1.15f);
		second.push(0.59f);
		second.push(0.7f);
		second.push(1.29f);
		second.push(0.77f);
		second.push(1.5f);
		second.push(2.19f);
		second.push(1.82f);
		second.push(5.95f);
		second.push(2.46f);
		second.push(4.98f);
		second.push(1.59f);

		MutantStack<float>::iterator second_start = second.begin();
		MutantStack<float>::iterator second_end = second.end();
		
		while (second_start != second_end)
		{
			result += *second_start;
			std::cout << *second_start;
			if (second_start != second_end - 1)
				std::cout << " + ";
			second_start++;
		}
		std::cout << " = " << result << std::endl;

		std::cout << "Stack size: " << second.size() << std::endl;
		std::cout << "Average: " << result / second.size() << std::endl;

	}

	std::cout << std::endl << "\033[1;33m~~~ Copy constructor and assignation test ~~~\033[0m" << std::endl;
	{
		MutantStack<int> third;
		third.push(1337);
		third.push(42);
		third.push(21);
		third.push(19);
		MutantStack<int> third_cpy(third);
		third.pop();
		MutantStack<int> third_double_cpy;
		third_double_cpy = third_cpy;
		third_double_cpy.pop();

		std::cout << "Orig: " << third.size() << "  |  Copy: " << third_cpy.size() << "  |  DCpy: " << third_double_cpy.size() << std::endl;
		MutantStack<int>::iterator third_start = third.begin();
		MutantStack<int>::iterator third_cpy_start = third_cpy.begin();
		MutantStack<int>::iterator third_double_cpy_start = third_double_cpy.begin();
		std::cout << "Orig[0] == Copy[0]?  >> " << (third_start == third_cpy_start) << " <<" << std::endl;
		std::cout << "DCpy[0] == Copy[0]?  >> " << (third_double_cpy_start == third_cpy_start) << " <<" << std::endl;
		std::cout << "Orig[0] == DCpy[0]?  >> " << (third_start == third_double_cpy_start) << " <<" << std::endl;
		std::cout << "Orig[0] == Orig[0]?  >> " << (third_start == third_start) << " <<" << std::endl;
		std::cout << "Copy[0] == Copy[0]?  >> " << (third_cpy_start == third_cpy_start) << " <<" << std::endl;
		std::cout << "DCpy[0] == DCpy[0]?  >> " << (third_double_cpy_start == third_double_cpy_start) << " <<" << std::endl;
		std::cout << "<" << *third_start << "> <" << *third_cpy_start << "> <" << *third_double_cpy_start << ">" << std::endl;
	}

}
