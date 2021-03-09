/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:46:00 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/10/23 15:08:04 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Copying the characters of src string in a new string. Note that we allocate
**	memory for the new string before copying.
*/

char	*ft_strdup(char *src)
{
	int		index;
	int		len;
	char	*result;

	if (src == NULL)
		return (ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG));
	len = ft_strlen(src);
	result = ft_strnew(len);
	if (result == NULL)
		return (ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_MLC));
	index = 0;
	while (index < len)
	{
		result[index] = src[index];
		index++;
	}
	return (result);
}
