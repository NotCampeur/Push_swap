/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:18:37 by ldutriez          #+#    #+#             */
/*   Updated: 2020/10/23 14:17:26 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Thoses functions will use the XOR bit operator
**	to swap two integers values.
*/

void	ft_swap_int(int *x, int *y)
{
	if (x == NULL || y == NULL)
		return ((void)ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG));
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}

void	ft_swap_char(char *x, char *y)
{
	if (x == NULL || y == NULL)
		return ((void)ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG));
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}
