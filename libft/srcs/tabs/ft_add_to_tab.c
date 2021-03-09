/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:09:42 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/10/23 14:54:07 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Adding a an entry at the end of an 2 dimension array. Heap allocated.
*/

void	ft_add_to_tab(void *to_add, void ***tab)
{
	void	**tmp;

	if (to_add == NULL || tab == NULL)
		return ((void)ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG));
	tmp = *tab;
	*tab = ft_tab_new(ft_tab_len(tmp) + 1);
	if (tmp != NULL)
	{
		ft_tab_cpy(*tab, tmp);
		free(tmp);
	}
	(*tab)[ft_tab_len(*tab)] = to_add;
}
