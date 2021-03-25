/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:52:06 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/25 13:41:07 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_c_operations.h"

void	push_a(t_list_node **stack_a, t_list_node **stack_b)
{
	t_list_node *tmp;

	tmp = *stack_b;
	if (*stack_b != NULL && ft_list_size(*stack_b) > 0)
	{
		*stack_b = (*stack_b)->next;
		tmp->next = NULL;
		ft_list_add_front(stack_a, tmp);
	}
}

void	push_b(t_list_node **stack_a, t_list_node **stack_b)
{
	t_list_node *tmp;

	if (stack_a != NULL)
	{
		tmp = *stack_a;
		if (*stack_a != NULL && ft_list_size(*stack_a) > 0)
		{
			*stack_a = (*stack_a)->next;
			tmp->next = NULL;
			ft_list_add_front(stack_b, tmp);
		}
	}
}
