/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:11:26 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/10/23 14:55:55 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Creating a new 2 dimensions array of size entries. Heap allocated.
*/

void	**ft_tab_new(int size)
{
	void	**result;
	int		index;

	result = (void **)malloc(sizeof(void *) * (size + 1));
	if (result == NULL)
		return (ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_MLC));
	index = 0;
	while (index < size)
	{
		result[index] = NULL;
		index++;
	}
	result[index] = NULL;
	return (result);
}
