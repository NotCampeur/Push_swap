/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:53:55 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/16 15:33:41 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reverse_rotate_a(t_list_node **stack_a)
{
	t_list_node	*tmp;

	tmp = *stack_a;
	if (ft_list_size(*stack_a) > 0
			&& (*stack_a)->next != NULL
			&& (*stack_a)->next->next != NULL)
	{
		while ((*stack_a)->next != NULL && (*stack_a)->next->next != NULL)
			*stack_a = (*stack_a)->next;
		(*stack_a)->next->next = tmp;
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = NULL;
	}
}

void	reverse_rotate_b(t_list_node **stack_b)
{
	t_list_node	*tmp;

	tmp = *stack_b;
	if (ft_list_size(*stack_b) > 0
			&& (*stack_b)->next != NULL
			&& (*stack_b)->next->next != NULL)
	{
		while ((*stack_b)->next != NULL && (*stack_b)->next->next != NULL)
			*stack_b = (*stack_b)->next;
		(*stack_b)->next->next = tmp;
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = NULL;
	}
}
