/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:00:33 by ldutriez          #+#    #+#             */
/*   Updated: 2020/10/23 13:29:21 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Printing a 2 dimensions integers array. Note that user can
**	define a name for the array. Otherwise, set NULL as the second parameter.
*/

void	ft_print_int_tab(char *name, int *tab, size_t len)
{
	size_t		index;

	index = 0;
	if (tab == NULL)
		return ((void)ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG));
	if (name != NULL)
	{
		ft_putchar('{');
		ft_putstr(name);
		ft_putstr("}\n");
	}
	ft_putstr("-----===-----\n");
	while (tab != NULL && index < len)
	{
		ft_putnbr(index);
		ft_putstr("--->[");
		ft_putnbr(tab[index]);
		ft_putstr("]\n");
		index++;
	}
	ft_putstr("-----===-----\n");
}
