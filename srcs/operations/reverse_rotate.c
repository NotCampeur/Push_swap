/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:53:55 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/29 14:24:35 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_c_operations.h"

void	reverse_rotate_a(t_list_node **stack_a)
{
	t_list_node	*tmp;

	tmp = *stack_a;
	if (ft_list_size(*stack_a) > 2)
	{
		while ((*stack_a)->next->next != NULL)
			*stack_a = (*stack_a)->next;
		(*stack_a)->next->next = tmp;
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = NULL;
	}
	else if (ft_list_size(*stack_a) == 2)
		rotate_a(stack_a);
}

void	reverse_rotate_b(t_list_node **stack_b)
{
	t_list_node	*tmp;

	tmp = *stack_b;
	if (ft_list_size(*stack_b) > 2)
	{
		while ((*stack_b)->next->next != NULL)
			*stack_b = (*stack_b)->next;
		(*stack_b)->next->next = tmp;
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = NULL;
	}
	else if (ft_list_size(*stack_b) == 2)
		rotate_b(stack_b);
}
