/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 10:47:17 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/10/23 13:22:57 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Converting numericals characters in a string into an integer. Skip all the
**	spaces at the start of the string and accept one sign ('+' or '-'), then
**	take only numericals characters. As soon as we encounter a non numerical
**	character, we retrun the actual value of result.
*/

int	ft_atoi(char *str)
{
	int	result;
	int	index;
	int	sign;

	if (str == NULL)
		return ((int)ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG));
	result = 0;
	index = 0;
	sign = 1;
	while (str[index] == ' ')
		index++;
	if (str[index] == '+')
		index++;
	else if (str[index] == '-')
	{
		index++;
		sign *= -1;
	}
	while (str[index] != '\0' && (str[index] >= '0' && str[index] <= '9'))
	{
		result = (result * 10) + (str[index] - '0');
		index++;
	}
	return (result * sign);
}
