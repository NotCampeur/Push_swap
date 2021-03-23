/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 10:56:05 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/23 12:58:03 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_smallest_a_on_b(t_list_node **stack_a, t_list_node **stack_b,
															void ***operations)
{
	if (*stack_a != NULL && *stack_b == NULL)
	{
		while (((t_node*)(*stack_a)->data)->index != 0)
		{
			ft_add_to_tab("ra\n", operations);
			rotate_a(stack_a);
		}
	}
	else if(*stack_a != NULL)
	{
		while (((t_node*)(*stack_a)->data)->index
		!= ((t_node*)(*stack_b)->data)->index + 1)
		{
			ft_add_to_tab("ra\n", operations);
			rotate_a(stack_a);
		}
	}
	ft_add_to_tab("pb\n", operations);
	push_b(stack_a, stack_b);
}

void	empty_stack(t_list_node **src, t_list_node **dst, void ***operations)
{
	while (*src != NULL)
	{
		ft_add_to_tab("pa\n", operations);
		push_b(src, dst);
	}
}

void	rev_push_sort(t_list_node **stack_a, t_list_node **stack_b,
															void ***operations)
{
	while (is_sort(*stack_a, *stack_b) == false)
	{
		push_smallest_a_on_b(stack_a, stack_b, operations);
		if (*stack_a == NULL || ft_list_size(*stack_a) <= 1)
			empty_stack(stack_b, stack_a, operations);
	}
}