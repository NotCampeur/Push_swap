/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:17:49 by tguilbar          #+#    #+#             */
/*   Updated: 2020/10/23 14:07:35 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Applying a function to all the nodes of a list and returning a new list
**	with the new datas. If the function fails, destroy the new list and returns
**	NULL.
*/

t_list_node	*ft_list_map(t_list_node *list, void *(*function)(void *),
void (*destructor)(void *))
{
	t_list_node	*result;
	t_list_node	*new_node;

	if (list == NULL)
		return (ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG));
	result = ft_malloc_node((*function)(list->data));
	if (result == NULL)
		return (ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_MLC));
	list = list->next;
	while (list != NULL)
	{
		new_node = ft_malloc_node((*function)(list->data));
		if (new_node == NULL)
		{
			ft_list_clear(&result, destructor);
			return (ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_MLC));
		}
		ft_list_add_back(&result, new_node);
		list = list->next;
	}
	return (result);
}
