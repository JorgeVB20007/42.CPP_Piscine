/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:38:24 by jvacaris          #+#    #+#             */
/*   Updated: 2023/03/13 17:34:57 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void short_cases_vector(std::vector<int> *the_vector)
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
?	STEP ONE
*	Grouping numbers in pairs and then sorting the 2 numbers in each pair in ascending order.
*/
std::vector<std::vector<int> > step_one_vector(std::vector<int> the_vector)
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

/*
?	STEP TWO
*	Sorting the pairs of numbers in ascending order by the biggest number of each pair using Insertion sort.
*/
void step_two_vector(std::vector<std::vector<int> > &the_vector)
{
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
		while (the_current-- != the_vector.begin())
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

/*
?	STEP THREE
*	Pushing the biggest number from each pair of numbers to another vector.
*/
std::vector<int> step_three_vector(std::vector<std::vector<int> > the_vector)
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

void ft_binary_search_vector(std::vector<int> &big_vector, int to_add, bool has_pair, int pair)
{
	int range_size = 0;
	std::vector<int>::iterator max_pivot;
	if (has_pair)
		max_pivot = std::find(big_vector.begin(), big_vector.end(), pair);
	else
	{
		max_pivot = big_vector.end();
		max_pivot--;
	}
		
	std::vector<int>::iterator min_pivot = big_vector.begin();
	std::vector<int>::iterator mid_pivot = big_vector.begin();
	range_size = std::distance(min_pivot, max_pivot);
	std::advance(mid_pivot, range_size / 2);

	if (*min_pivot >= to_add)
	{
		big_vector.insert(min_pivot, to_add);
		return ;
	}
	if (*max_pivot < to_add)
	{
		big_vector.insert(big_vector.end(), to_add);
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
	if (mid_pivot != big_vector.begin() && *(mid_pivot - 1) > to_add)
		mid_pivot--;
	if (mid_pivot != big_vector.end() && *(mid_pivot) < to_add)
		mid_pivot++;
	big_vector.insert(mid_pivot, to_add);
}

/*
?	STEP FOUR
*	Pushing the numbers from the vector of pairs to the vector with the big numbers.
*/
void step_four_vector(std::vector<std::vector<int> > &pair_vector, std::vector<int> &big_vector)
{
	std::vector<std::vector<int> >::iterator the_current = pair_vector.begin();
	big_vector.insert(big_vector.begin(), (*the_current)[0]);
	the_current++;
	while (the_current != pair_vector.end())
	{
		if (the_current->size() == 2)
			ft_binary_search_vector(big_vector, (*the_current)[0], true, (*the_current)[1]);
		else
			ft_binary_search_vector(big_vector, (*the_current)[0], false, 0);
		the_current++;
	}
}

std::vector<int> PmergeMe_vector(std::vector<int> the_vector)
{
	std::vector<int> big_nums;
	if (the_vector.size() <= 2)
	{
		short_cases_vector(&the_vector);
		return (the_vector);
	}
	std::vector<std::vector<int> > pairs = step_one_vector(the_vector);

	step_two_vector(pairs);

	big_nums = step_three_vector(pairs);

	step_four_vector(pairs, big_nums);

	if (!std::is_sorted(big_nums.begin(), big_nums.end()))
		std::cout << "ERROR: VECTOR wasn't sorted properly." << std::endl;
	return (big_nums);
}

/*
!		    /\
!		   //\\		using
!		  ///\\\	std::vector
!		    ||
*		    ||
?		    ||
?		  \\\///	using
?		   \\//		std::deque
?		    \/
*/


void short_cases_deque(std::deque<int> *the_deque)
{
	int aux = 0;
	if (the_deque->size() < 2)
		return ;
	else if (the_deque->size() == 2)
	{
		aux = (*the_deque)[0];
		(*the_deque)[0] = (*the_deque)[1];
		(*the_deque)[1] = aux;
	}
}

/*
?	STEP ONE
*	Grouping numbers in pairs and then sorting the 2 numbers in each pair in ascending order.
*/
std::deque<std::deque<int> > step_one_deque(std::deque<int> the_deque)
{
	std::deque<std::deque<int> > result;
	std::deque<int> result_item;

	for (unsigned int idx = 0; idx < the_deque.size(); idx += 2)
	{
		result_item.clear();
		if (idx == the_deque.size() - 1)
		{
			result_item.push_back(the_deque[idx]);
		}
		else if (the_deque[idx] > the_deque[idx + 1])
		{
			result_item.push_back(the_deque[idx + 1]);
			result_item.push_back(the_deque[idx]);
		}
		else
		{
			result_item.push_back(the_deque[idx]);
			result_item.push_back(the_deque[idx + 1]);
		}
		result.push_back(result_item);
	}
	return (result);
}

/*
?	STEP TWO
*	Sorting the pairs of numbers in ascending order by the biggest number of each pair using Insertion sort.
*/
void step_two_deque(std::deque<std::deque<int> > &the_deque)
{
	std::deque<std::deque<int> >::iterator the_end = the_deque.end();
	std::deque<std::deque<int> >::iterator the_main = the_deque.begin();
	std::deque<std::deque<int> >::iterator the_current;
	std::deque<std::deque<int> >::iterator the_prev_current;

	the_main++;
	if ((*(the_end - 1)).size() == 1)
		the_end--;
	while (the_main != the_end)
	{
		the_current = the_main;
		the_prev_current = the_main;
		while (the_current-- != the_deque.begin())
		{
			if ((*the_current)[1] > (*the_prev_current)[1])
			{
				std::iter_swap(the_current, the_prev_current);
			}
			the_prev_current--;
			if (the_current == the_deque.begin())
				break ;
		}
		the_main++;
	}
}

/*
?	STEP THREE
*	Pushing the biggest number from each pair of numbers to another deque.
*/
std::deque<int> step_three_deque(std::deque<std::deque<int> > the_deque)
{
	std::deque<int> retval;
	for (std::deque<std::deque<int> >::iterator it = the_deque.begin(); it != the_deque.end(); it++)
	{
		if ((*it).size() == 2)
		{
			retval.push_back((*it)[1]);
		}
	}
	return (retval);
}

void ft_binary_search_deque(std::deque<int> &big_deque, int to_add, bool has_pair, int pair)
{
	int range_size = 0;
	std::deque<int>::iterator max_pivot;
	if (has_pair)
		max_pivot = std::find(big_deque.begin(), big_deque.end(), pair);
	else
	{
		max_pivot = big_deque.end();
		max_pivot--;
	}
		
	std::deque<int>::iterator min_pivot = big_deque.begin();
	std::deque<int>::iterator mid_pivot = big_deque.begin();
	range_size = std::distance(min_pivot, max_pivot);
	std::advance(mid_pivot, range_size / 2);

	if (*min_pivot >= to_add)
	{
		big_deque.insert(min_pivot, to_add);
		return ;
	}
	if (*max_pivot < to_add)
	{
		big_deque.insert(big_deque.end(), to_add);
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
	if (mid_pivot != big_deque.begin() && *(mid_pivot - 1) > to_add)
		mid_pivot--;
	if (mid_pivot != big_deque.end() && *(mid_pivot) < to_add)
		mid_pivot++;
	big_deque.insert(mid_pivot, to_add);
}

/*
?	STEP FOUR
*	Pushing the numbers from the deque of pairs to the deque with the big numbers.
*/
void step_four_deque(std::deque<std::deque<int> > &pair_deque, std::deque<int> &big_deque)
{
	std::deque<std::deque<int> >::iterator the_current = pair_deque.begin();
	big_deque.insert(big_deque.begin(), (*the_current)[0]);
	the_current++;
	while (the_current != pair_deque.end())
	{
		if (the_current->size() == 2)
			ft_binary_search_deque(big_deque, (*the_current)[0], true, (*the_current)[1]);
		else
			ft_binary_search_deque(big_deque, (*the_current)[0], false, 0);
		the_current++;
	}
}

std::deque<int> PmergeMe_deque(std::deque<int> the_deque)
{
	std::deque<int> big_nums;
	if (the_deque.size() <= 2)
	{
		short_cases_deque(&the_deque);
		return (the_deque);
	}
	std::deque<std::deque<int> > pairs = step_one_deque(the_deque);

	step_two_deque(pairs);

	big_nums = step_three_deque(pairs);

	step_four_deque(pairs, big_nums);

	if (!std::is_sorted(big_nums.begin(), big_nums.end()))
		std::cout << "ERROR: DEQUE wasn't sorted properly." << std::endl;
	return (big_nums);
}
