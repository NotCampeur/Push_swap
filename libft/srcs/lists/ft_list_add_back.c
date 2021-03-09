/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 08:24:59 by ldutriez          #+#    #+#             */
/*   Updated: 2020/10/23 14:05:28 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Adding a node at the end of a linked list. See libft_list_node.h for further
**	informations on t_list_node structure.
*/

void	ft_list_add_back(t_list_node **list, t_list_node *node)
{
	t_list_node	*start;

	start = *list;
	if (node == NULL || list == NULL)
		return ((void)ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG));
	if (*list == NULL)
	{
		*list = node;
		return ;
	}
	while ((*list)->next != NULL)
		(*list) = (*list)->next;
	(*list)->next = node;
	*list = start;
}
