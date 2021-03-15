/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:52:56 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/15 14:42:36 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate_a(t_list_node **stack_a)
{
	t_list_node *tmp;

	tmp = *stack_a;
	if (ft_list_size(*stack_a) > 0 && (*stack_a)->next != NULL)
	{
		*stack_a = (*stack_a)->next;
		tmp->next = NULL;
		ft_list_add_back(stack_a, tmp);
	}
}

void	rotate_b(t_list_node **stack_b)
{
	t_list_node *tmp;

	tmp = *stack_b;
	if (ft_list_size(*stack_b) > 0 && (*stack_b)->next != NULL)
	{
		*stack_b = (*stack_b)->next;
		tmp->next = NULL;
		ft_list_add_back(stack_b, tmp);
	}
}
