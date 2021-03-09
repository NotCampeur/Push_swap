/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_abs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoudsi <ncoudsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 09:03:19 by ldutriez          #+#    #+#             */
/*   Updated: 2020/10/15 10:37:38 by ncoudsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returning the absolute value of a floating point.
*/

float	ft_float_abs(float value)
{
	if (value == 0.0f)
		return (0.0f);
	if (value < 0.0f)
		value *= -1;
	return (value);
}
