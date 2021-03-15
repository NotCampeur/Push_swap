/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_putstr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:43:33 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/15 15:44:28 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Computing the offset to avoid a shift in output
*/

static void	print_offset(int fd, size_t nbr)
{
	size_t	i;

	i = 0;
	while (i < nbr)
	{
		ft_putchar_fd(fd, ' ');
		i++;
	}
}

static void	print_name(int fd, char *name)
{
	ft_putchar_fd(fd, '{');
	ft_putstr_fd(fd, name);
	ft_putstr_fd(fd, "}\n");
}

/*
**	Printing a linked list data, casted in str in a file. Note that user can
**	define a name for the array. Otherwise, set NULL as the first parameter.
*/

void		ft_list_putstr_fd(int fd, char *name, t_list_node *list)
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
		print_name(fd, name);
	ft_putstr_fd(fd, "-----===-----\n");
	while (list != NULL)
	{
		ft_putnbr_fd(fd, index);
		print_offset(fd, line_offset - ft_nbr_len(index));
		ft_putstr_fd(fd, "--->");
		ft_putstr_fd(fd, list->data);
		ft_putstr_fd(fd, "\n");
		list = list->next;
		index++;
	}
	list = tmp;
	ft_putstr_fd(fd, "-----===-----\n");
}
