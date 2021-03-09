/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_count_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:55:11 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/10/23 15:07:14 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Counting the number of itterations of c character in str string.
*/

int	ft_str_count_c(char *str, char c)
{
	int	result;
	int	index;

	result = 0;
	index = 0;
	if (str == NULL)
		return ((int)ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG));
	while (str[index] != '\0')
	{
		if (str[index] == c)
			result++;
		index++;
	}
	return (result);
}
