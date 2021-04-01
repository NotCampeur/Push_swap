/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_peculiar_cases.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:49:24 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/01 09:23:42 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_in_crescent_order(t_list_node *stack_a)
{
	t_list_node	*tmp;

	tmp = stack_a;
	while (stack_a->next != NULL)
	{
		if (((t_node*)stack_a->data)->index >
									((t_node*)stack_a->next->data)->index)
		{
			stack_a = tmp;
			return (false);
		}
		stack_a = stack_a->next;
	}
	stack_a = tmp;
	return (true);
}
