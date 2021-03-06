/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_charset_in_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:14:11 by ncoudsi           #+#    #+#             */
/*   Updated: 2021/03/25 16:16:19 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Checking if str string contains at least one character of the to_find
**	string. Return true at the first occurence, return false if none is found.
*/

t_bool			ft_is_charset_in_str(char *str, char *to_find)
{
	size_t	index;

	index = 0;
	if (str == NULL || to_find == NULL)
	{
		return (false);
	}
	while (str[index] != '\0')
	{
		if (ft_is_char_in_str(str[index], to_find) == true)
			return (true);
		index++;
	}
	return (false);
}
