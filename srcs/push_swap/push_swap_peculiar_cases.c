/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_peculiar_cases.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:49:24 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/07 18:14:51 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_in_crescent_order(t_list_node *s_a)
{
	t_list_node	*t;
	t_list_node	*t2;

	t = s_a;
	t2 = ft_list_get_node(&s_a, INT_MAX);
	while (s_a->next != NULL)
	{
		if (((t_node*)s_a->data)->index
									> ((t_node*)s_a->next->data)->index)
			if (((t_node*)s_a->next->data)->index != 0
				|| ((t_node*)t->data)->index < ((t_node*)t2->data)->index)
			{
				s_a = t;
				return (false);
			}
		s_a = s_a->next;
	}
	s_a = t;
	return (true);
}
