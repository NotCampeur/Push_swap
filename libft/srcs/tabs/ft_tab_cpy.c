/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:14:19 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/10/23 14:55:27 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Copy the entries of a 2 dimensions array in another one.
*/

void	ft_tab_cpy(void **dst, void **src)
{
	int	index;

	index = 0;
	if (dst == NULL || src == NULL)
		return ((void)ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG));
	while (src[index] != NULL)
	{
		dst[index] = src[index];
		index++;
	}
}
