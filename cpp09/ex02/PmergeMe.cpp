/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:38:24 by jvacaris          #+#    #+#             */
/*   Updated: 2023/03/12 22:10:40 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*

TODO	**********
!		* README *
TODO	**********

!	A lot of revision's required.
!	- Last digit for odd numbers does not get sorted.
!	- Missing implementation for deque.

?	Most segfaults occur for trying to print too many values in `PmergeMe_vector`.

*/


void short_cases(std::vector<int> *the_vector)
{
	int aux = 0;
	if (the_vector->size() < 2)
		return ;
	else if (the_vector->size() == 2)
	{
		aux = (*the_vector)[0];
		(*the_vector)[0] = (*the_vector)[1];
		(*the_vector)[1] = aux;
	}
}

/*
?	Turn to COUPLES (sorted).
*/
std::vector<std::vector<int> > step_one(std::vector<int> the_vector)
{
	std::vector<std::vector<int> > result;
	std::vector<int> result_item;

	for (unsigned int idx = 0; idx < the_vector.size(); idx += 2)
	{
		result_item.clear();
		if (idx == the_vector.size() - 1)
		{
			result_item.push_back(the_vector[idx]);
		}
		else if (the_vector[idx] > the_vector[idx + 1])
		{
			result_item.push_back(the_vector[idx + 1]);
			result_item.push_back(the_vector[idx]);
		}
		else
		{
			result_item.push_back(the_vector[idx]);
			result_item.push_back(the_vector[idx + 1]);
		}
		result.push_back(result_item);
	}
	return (result);
}

void step_two(std::vector<std::vector<int> > &the_vector)
{
	std::vector<std::vector<int> >::iterator the_start = the_vector.begin();
	std::vector<std::vector<int> >::iterator the_end = the_vector.end();
	std::vector<std::vector<int> >::iterator the_main = the_vector.begin();
	std::vector<std::vector<int> >::iterator the_current;
	std::vector<std::vector<int> >::iterator the_prev_current;

	the_main++;
	if ((*(the_end - 1)).size() == 1)
		the_end--;
	while (the_main != the_end)
	{
		the_current = the_main;
		the_prev_current = the_main;
		while (the_current-- != the_start)
		{
			if ((*the_current)[1] > (*the_prev_current)[1])
			{
				std::iter_swap(the_current, the_prev_current);
			}
			the_prev_current--;
		}
		the_main++;
	}
}

std::vector<int> step_three(std::vector<std::vector<int> > the_vector)
{
	std::vector<int> retval;
	for (std::vector<std::vector<int> >::iterator it = the_vector.begin(); it != the_vector.end(); it++)
	{
		if ((*it).size() == 2)
		{
			retval.push_back((*it)[1]);
		}
	}
	return (retval);
}

void ft_binary_search(std::vector<int> &big_vector, int to_add, int pair)
{
	int range_size = 0;	
	std::vector<int>::iterator max_pivot = std::find(big_vector.begin(), big_vector.end(), pair);
	std::vector<int>::iterator min_pivot = big_vector.begin();
	std::vector<int>::iterator mid_pivot = big_vector.begin();
	range_size = std::distance(min_pivot, max_pivot);
	std::advance(mid_pivot, range_size / 2);

	if (*min_pivot >= to_add)
	{
		big_vector.insert(min_pivot, to_add);
		return ;
	}
	while (range_size > 1)
	{
		if (*max_pivot == to_add)
			mid_pivot = max_pivot;
		else if (*min_pivot == to_add)
			mid_pivot = min_pivot;
		if (*mid_pivot == to_add)
			break;
		if (*mid_pivot > to_add)
			max_pivot = mid_pivot;
		else if (*mid_pivot < to_add)
			min_pivot = mid_pivot;
		range_size = std::distance(min_pivot, max_pivot);
		if (range_size > 1)
		{
			mid_pivot = min_pivot;
			std::advance(mid_pivot, range_size / 2);
		}
	}
	big_vector.insert(mid_pivot, to_add);
}

void step_four(std::vector<std::vector<int> > &pair_vector, std::vector<int> &big_vector)
{
	std::vector<std::vector<int> >::iterator the_current = pair_vector.begin();
	big_vector.insert(big_vector.begin(), (*the_current)[0]);
	the_current++;
	while (the_current != pair_vector.end())
	{
		if (the_current->size() == 2)
			ft_binary_search(big_vector, (*the_current)[0], (*the_current)[1]);
		else
			std::cout << "MISSING LAST DIGIT" << std::endl;
		the_current++;
	}
}

void PmergeMe_vector(std::vector<int> the_vector)
{
	std::vector<int> big_nums;
	if (the_vector.size() <= 2)
	{
		short_cases(&the_vector);
		return ;
	}
	std::vector<std::vector<int> > pairs = step_one(the_vector);

	std::cout << "--- Step one ---" << std::endl;
	std::cout << "(" << pairs[0][0] << " , " << pairs[0][1] << ")" << std::endl;
	std::cout << "(" << pairs[1][0] << " , " << pairs[1][1] << ")" << std::endl;
	std::cout << "(" << pairs[2][0] << " , " << pairs[2][1] << ")" << std::endl;
	std::cout << "(" << pairs[3][0] << " , " << pairs[3][1] << ")" << std::endl;
//	std::cout << "(" << pairs[4][0] << /*" , " << pairs[3][1] <<*/ ")" << std::endl;

	step_two(pairs);


	std::cout << std::endl << "--- Step two ---" << std::endl;
	std::cout << "(" << pairs[0][0] << " , " << pairs[0][1] << ")" << std::endl;
	std::cout << "(" << pairs[1][0] << " , " << pairs[1][1] << ")" << std::endl;
	std::cout << "(" << pairs[2][0] << " , " << pairs[2][1] << ")" << std::endl;
	std::cout << "(" << pairs[3][0] << " , " << pairs[3][1] << ")" << std::endl;
//	std::cout << "(" << pairs[4][0] << /*" , " << pairs[3][1] <<*/ ")" << std::endl;

	big_nums = step_three(pairs);

	std::cout << std::endl << "--- Step three ---" << std::endl;
	for (std::vector<int>::iterator it = big_nums.begin(); it != big_nums.end(); it++)
	{
		std::cout << "(" << *it << ") ";
	}

	step_four(pairs, big_nums);

	std::cout << std::endl << "--- Step four ---" << std::endl;
	for (std::vector<int>::iterator it = big_nums.begin(); it != big_nums.end(); it++)
	{
		std::cout << "(" << *it << ") ";
	}

}



