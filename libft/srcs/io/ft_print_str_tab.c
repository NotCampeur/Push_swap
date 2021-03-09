/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:11:20 by ldutriez          #+#    #+#             */
/*   Updated: 2020/10/23 13:35:12 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Computing the offset to avoid a shift in output
*/

static void	print_offset(size_t nbr)
{
	size_t	i;

	i = 0;
	while (i < nbr)
	{
		ft_putchar(' ');
		i++;
	}
}

/*
**	Printing a 2 dimensions characters array. Note that user can
**	define a name for the array. Otherwise, set NULL as the second parameter.
*/

void		ft_print_str_tab(char *name, char **tab)
{
	size_t		index;
	size_t		line_offset;

	index = 0;
	if (tab == NULL)
		return ((void)ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG));
	line_offset = ft_nbr_len(ft_tab_len((void**)tab));
	if (name != NULL)
	{
		ft_putchar('{');
		ft_putstr(name);
		ft_putstr("}\n");
	}
	ft_putstr("-----===-----\n");
	while (tab != NULL && tab[index] != NULL)
	{
		ft_putnbr(index);
		print_offset(line_offset - ft_nbr_len(index));
		ft_putstr("--->");
		ft_putstr(tab[index]);
		ft_putstr("\n");
		index++;
	}
	ft_putstr("-----===-----\n");
}
