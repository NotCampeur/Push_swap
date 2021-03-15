/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_putstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:06:07 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/15 14:01:28 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Computing the offset to avoid a shift in output
*/

static void	print_offset(size_t index, size_t nbr)
{
	size_t	i;

	i = 0;
	ft_putnbr(index);
	while (i < nbr)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putstr("--->");
}

static void	print_name(char *name)
{
	ft_putchar('{');
	ft_putstr(name);
	ft_putstr("}\n");
}

/*
**	Printing a linked list data, casted in str. Note that user can
**	define a name for the array. Otherwise, set NULL as the first parameter.
*/

void		ft_list_putstr(char *name, t_list_node *list)
{
	size_t		index;
	size_t		line_offset;
	t_list_node	*tmp;

	index = 0;
	tmp = list;
	if (list == NULL)
		return ((void)ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG));
	line_offset = ft_nbr_len(ft_list_size(list));
	if (name != NULL)
		print_name(name);
	ft_putstr("-----===-----\n");
	while (list != NULL)
	{
		print_offset(index, line_offset - ft_nbr_len(index));
		ft_putstr(list->data);
		ft_putstr("\n");
		list = list->next;
		index++;
	}
	list = tmp;
	ft_putstr("-----===-----\n");
}
