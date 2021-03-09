/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rm_charset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:59:06 by ldutriez          #+#    #+#             */
/*   Updated: 2020/10/23 15:08:22 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Counting the lenght of the string without the characters of
**	the charset and returning it.
*/

static int		len_without_charset(char *str, char *charset)
{
	int result;
	int index;

	result = 0;
	index = 0;
	if (str == NULL)
		return (result);
	while (str[index] != '\0')
	{
		if (ft_is_char_in_str(str[index], charset) == false)
			result++;
		index++;
	}
	return (result);
}

/*
**	Removing all characters of a charset of a string and returning
**	the cleaned string.
*/

char			*ft_rm_charset(char *str, char *charset)
{
	char	*result;
	int		index;
	int		result_index;

	if (str == NULL || charset == NULL)
		return (ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG));
	index = 0;
	result_index = 0;
	result = ft_strnew(len_without_charset(str, charset));
	if (result == NULL)
		return (ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_MLC));
	while (str[index] != '\0')
	{
		if (ft_is_char_in_str(str[index], charset) == false)
		{
			result[result_index] = str[index];
			result_index++;
		}
		index++;
	}
	free(str);
	return (result);
}
