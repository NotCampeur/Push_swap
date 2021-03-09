/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:31:29 by tguilbar          #+#    #+#             */
/*   Updated: 2020/10/23 15:20:19 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Applying a function to all the list's datas.
*/

void	ft_list_iter(t_list_node *list, void (*function)(void *))
{
	if (list == NULL)
		return ((void)ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG));
	while (list->next != NULL)
	{
		(*function)(list->data);
		list = list->next;
	}
	(*function)(list->data);
}
