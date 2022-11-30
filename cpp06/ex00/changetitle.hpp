/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changetitle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:53:10 by jvacaris          #+#    #+#             */
/*   Updated: 2022/11/30 21:54:42 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANGETITLE_HPP
# define CHANGETITLE_HPP

#include <iostream>

enum e_type_of_value
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

struct s_str_characteristics
{
	bool has_sign;
	bool has_digits;
	bool has_decimal;
	bool has_others;
	bool final_f;
}	t_str_characteristics;

#endif