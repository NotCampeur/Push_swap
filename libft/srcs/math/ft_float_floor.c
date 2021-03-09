/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_floor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoudsi <ncoudsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 08:54:40 by ldutriez          #+#    #+#             */
/*   Updated: 2020/10/15 10:40:43 by ncoudsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Casting a floating point value into an integer to round it down, then
**	returning the rounded floating point value.
*/

float	ft_float_floor(float value)
{
	int		int_value;
	float	result;

	int_value = (int)value;
	result = int_value;
	return (result);
}
