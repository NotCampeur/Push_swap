/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:47:03 by tguilbar          #+#    #+#             */
/*   Updated: 2020/10/23 14:11:08 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Apply the destructor function to all the datas and free each nodes
*/

void	ft_list_clear(t_list_node **list, void (*destructor)(void*))
{
	t_list_node *tmp;

	if (*list == NULL)
		return ((void)ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG));
	while (*list != NULL)
	{
		tmp = *list;
		if (destructor != NULL)
			(*destructor)(tmp->data);
		*list = tmp->next;
		free(tmp);
	}
}
