/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:47:44 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/17 18:52:10 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Animal.hpp"

class Brain
{
	protected:
		std::string ideas[100];
	public:
		Brain();
		Brain(Brain &tocopy);
		~Brain();
		Brain & operator = (Brain &toequalize);
		void think(int index, std::string newidea);
		std::string recall(int index);
};

#endif