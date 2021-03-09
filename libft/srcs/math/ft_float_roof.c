/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_roof.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoudsi <ncoudsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:11:18 by ldutriez          #+#    #+#             */
/*   Updated: 2020/10/15 11:12:22 by ncoudsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Rounding up a floating point value.
*/

float		ft_float_roof(float value)
{
	float	result;
	int		int_value;

	int_value = value;
	if (value == 0.0f)
		return (value);
	if (value < 0.0f)
	{
		result = int_value;
		return (result);
	}
	if (value - int_value == 0.0f)
	{
		result = value;
		return (result);
	}
	else
		result = int_value + 1;
	return (result);
}
