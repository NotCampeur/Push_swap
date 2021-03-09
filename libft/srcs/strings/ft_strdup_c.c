/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:57:19 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/10/23 15:31:36 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Allocating memory for a new string containing only c character.
**	Then returns the string.
*/

char	*ft_strdup_c(char c)
{
	char	*result;

	result = ft_strnew(1);
	if (result == NULL)
		return (ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_MLC));
	result[0] = c;
	return (result);
}
