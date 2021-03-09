/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_abs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoudsi <ncoudsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 09:00:01 by ldutriez          #+#    #+#             */
/*   Updated: 2020/10/15 11:17:52 by ncoudsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returning an absolute value of an integer.
*/

int		ft_int_abs(int value)
{
	if (value == 0)
		return (0);
	if (value < 0)
		value *= -1;
	return (value);
}
