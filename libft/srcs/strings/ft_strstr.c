/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:29:15 by ldutriez          #+#    #+#             */
/*   Updated: 2020/10/23 14:51:18 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Searching for the full needle string is found in the haystack string.
**	If needle is found, returns a pointer on haystack string, starting at
**	the first character of needle. If needle is not found, returns NULL.
*/

char	*ft_strstr(char *haystack, char *needle)
{
	if (haystack == NULL)
		return (ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG));
	return (ft_strnstr(haystack, needle, ft_strlen(haystack)));
}
