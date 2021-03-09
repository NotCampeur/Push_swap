/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:55:32 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/10/23 14:03:47 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Cheking if 2 strings are entirely similar.
*/

t_bool	ft_strcmp(char *src, char *target)
{
	size_t	index;

	index = 0;
	if (src == NULL || target == NULL)
	{
		return ((t_bool)ft_print_error(__PRETTY_FUNCTION__, __LINE__,
										FT_E_ARG));
	}
	while (src[index] != '\0' || target[index] != '\0')
	{
		if (src[index] != target[index])
			return (false);
		index++;
	}
	return (true);
}
