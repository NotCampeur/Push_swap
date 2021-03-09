/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_only_digits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:44:35 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/10/23 14:02:51 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Checking in a string if all the characters are digits.
*/

t_bool	ft_is_only_digits(char *str)
{
	size_t index;

	index = 0;
	if (str == NULL)
	{
		return ((t_bool)ft_print_error(__PRETTY_FUNCTION__, __LINE__,
										FT_E_ARG));
	}
	while (str[index] != '\0')
	{
		if (ft_is_digit(str[index]) == false)
			return (false);
		index++;
	}
	return (true);
}
