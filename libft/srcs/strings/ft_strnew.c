/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:39:13 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/10/23 15:08:10 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Allocating memory for a new string of len lenght and filling it with '\0'.
*/

char	*ft_strnew(size_t len)
{
	char		*result;
	size_t		index;

	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_MLC));
	index = 0;
	while (index < len)
	{
		result[index] = '\0';
		index++;
	}
	result[index] = '\0';
	return (result);
}
