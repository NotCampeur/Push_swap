/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 10:01:23 by ldutriez          #+#    #+#             */
/*   Updated: 2020/10/23 14:11:00 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Adding a node at the start of a linked list. See libft_list_node.h
**	for further informations on t_list_node structure.
*/

void	ft_list_add_front(t_list_node **list, t_list_node *node)
{
	if (list == NULL || node == NULL)
		return ((void)ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG));
	node->next = *list;
	*list = node;
}
