/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:13:14 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/10/23 13:28:57 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Calculating the number of entries in a 2 dimensions array.
*/

size_t	ft_tab_len(void **tab)
{
	size_t	result;

	result = 0;
	if (tab == NULL)
	{
		return ((size_t)ft_print_error(__PRETTY_FUNCTION__, __LINE__,
										FT_E_ARG));
	}
	while (tab[result] != NULL)
		result++;
	return (result);
}
