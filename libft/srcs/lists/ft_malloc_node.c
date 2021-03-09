/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 09:46:35 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/10/23 14:10:26 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Allocating memory for a t_list_node pointer and filling it with data.
**	Then returns the t_list_node pointer.
*/

t_list_node	*ft_malloc_node(void *data)
{
	t_list_node	*result;

	result = (t_list_node *)malloc(sizeof(t_list_node));
	if (result == NULL)
		return (ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_MLC));
	result->data = data;
	result->next = NULL;
	return (result);
}
