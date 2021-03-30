/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_get_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 08:24:59 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/30 13:05:47 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returning the wanted node from the list
*/

t_list_node	*ft_list_get_node(t_list_node **list, size_t pos)
{
	t_list_node	*start;
	t_list_node	*result;
	size_t		index;

	start = *list;
	result = NULL;
	index = 0;
	if (list == NULL || *list == NULL)
		return (ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG));
	while ((*list)->next != NULL && index < pos)
	{
		(*list) = (*list)->next;
		index++;
	}
	result = *list;
	*list = start;
	return (result);
}
