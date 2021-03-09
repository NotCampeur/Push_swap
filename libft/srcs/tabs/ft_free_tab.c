/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:13:46 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/10/23 14:54:55 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Free every entity in a 2 dimensions array and free the array itself.
*/

void	ft_free_tab(void **tab)
{
	int	index;

	index = 0;
	if (tab == NULL)
		return ((void)ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG));
	while (tab[index] != NULL)
	{
		free(tab[index]);
		index++;
	}
	free(tab);
}
