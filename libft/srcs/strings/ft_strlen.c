/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 14:01:19 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/10/23 14:41:28 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Counting the lenght of a string and returning it.
*/

size_t		ft_strlen(char *src)
{
	size_t	result;

	result = 0;
	if (src == NULL)
	{
		return ((size_t)ft_print_error(__PRETTY_FUNCTION__, __LINE__,
										FT_E_ARG));
	}
	while (src[result] != '\0')
		result++;
	return (result);
}
