/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:13:06 by tguilbar          #+#    #+#             */
/*   Updated: 2020/10/23 14:10:03 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Counting the number of nodes in a list and returning it.
*/

int	ft_list_size(t_list_node *list)
{
	int		result;

	if (list == NULL)
		return ((int)ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG));
	result = 1;
	while (list->next != NULL)
	{
		list = list->next;
		result++;
	}
	return (result);
}
