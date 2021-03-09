/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoudsi <ncoudsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:33:24 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/10/15 13:40:25 by ncoudsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Converting an integer value into a string filled with numerical characters
**	refering to the value, in an hexadecimal base.
*/

char		*ft_itoa_hexa(long long int nbr)
{
	char	*base;
	char	*result;

	base = "0123456789abcdef";
	result = ft_itoa_base(nbr, base);
	return (result);
}
