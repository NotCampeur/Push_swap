/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 11:49:49 by tguilbar          #+#    #+#             */
/*   Updated: 2020/10/23 13:26:48 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returning the length of the number (in characters, in order to write it in
**	the string after conversion), depending on its value and the base.
*/

static size_t	ft_nbrlen(long long int nbr, size_t base_len)
{
	size_t					result;
	unsigned long long int	abs_nbr;

	result = 1;
	if (nbr < 0)
	{
		result++;
		abs_nbr = -nbr;
	}
	else
		abs_nbr = nbr;
	while (abs_nbr >= base_len)
	{
		abs_nbr /= base_len;
		result++;
	}
	return (result);
}

/*
**	Converting an integer value into a string filled with numerical characters
**	refering to the value, in a set base.
*/

char			*ft_itoa_base(long long int nbr, char *base)
{
	size_t					base_len;
	size_t					nbr_len;
	char					*result;
	unsigned long long int	abs_nbr;

	if (base == NULL)
		return (ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG));
	base_len = ft_strlen(base);
	nbr_len = ft_nbrlen(nbr, base_len) - 1;
	result = ft_strnew(nbr_len);
	if (nbr < 0)
	{
		result[0] = '-';
		abs_nbr = -nbr;
	}
	else
		abs_nbr = nbr;
	while (abs_nbr >= base_len)
	{
		result[nbr_len] = base[abs_nbr % base_len];
		abs_nbr /= base_len;
		nbr_len--;
	}
	result[nbr_len] = base[abs_nbr % base_len];
	return (result);
}
