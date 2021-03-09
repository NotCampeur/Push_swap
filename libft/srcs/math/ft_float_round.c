/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_round.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoudsi <ncoudsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:54:18 by tguilbar          #+#    #+#             */
/*   Updated: 2020/10/15 11:16:38 by ncoudsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returning a rounded value of a floating point.
*/

float	ft_float_round(float value)
{
	float	floor;
	float	roof;

	floor = ft_float_floor(value);
	roof = ft_float_roof(value);
	if ((value - floor) < (roof - value))
		return (floor);
	else
		return (roof);
}
