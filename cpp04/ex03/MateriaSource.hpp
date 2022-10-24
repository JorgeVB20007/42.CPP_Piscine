/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:52:51 by jvacaris          #+#    #+#             */
/*   Updated: 2022/10/24 20:55:50 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	public:
		virtual void learnMateria(AMateria *tolearn);
		virtual AMateria *createMateria(std::string const &);
		MateriaSource();
		MateriaSource(MateriaSource &tocopy);
		~MateriaSource();
		MateriaSource & operator = (MateriaSource &toequalize);
	private:
		AMateria *materias[4];
};
#endif