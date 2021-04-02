/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 10:56:05 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/02 12:43:55 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		execute_ops(t_list_node **s_a, t_list_node **s_b, t_list_node *ops)
{
	t_list_node *tmp;

	tmp = ops;
	while (ops != NULL)
	{
		if (ft_strcmp(ops->data, "sa\n") || ft_strcmp(ops->data, "ss\n"))
			swap_stack(s_a);
		if (ft_strcmp(ops->data, "sb\n") || ft_strcmp(ops->data, "ss\n"))
			swap_stack(s_b);
		if (ft_strcmp(ops->data, "pa\n"))
			push_a(s_a, s_b);
		if (ft_strcmp(ops->data, "pb\n"))
			push_b(s_a, s_b);
		if (ft_strcmp(ops->data, "ra\n") || ft_strcmp(ops->data, "rr\n"))
			rotate_a(s_a);
		if (ft_strcmp(ops->data, "rb\n") || ft_strcmp(ops->data, "rr\n"))
			rotate_b(s_b);
		if (ft_strcmp(ops->data, "rra\n") || ft_strcmp(ops->data, "rrr\n"))
			reverse_rotate_a(s_a);
		if (ft_strcmp(ops->data, "rrb\n") || ft_strcmp(ops->data, "rrr\n"))
			reverse_rotate_b(s_b);
		ops = ops->next;
	}
	ops = tmp;
}

void		move_the_best_value(t_list_node **s_a, t_list_node **s_b
														, t_list_node **ops)
{
	int			minimal_moves;
	int			moves_needed;
	int			index;
	t_list_node	*ops_to_do;
	t_list_node	*best_ops;

	minimal_moves = INT_MAX;
	index = ft_list_size(*s_b) - 1;
	best_ops = NULL;
	while (index >= 0)
	{
		moves_needed = 0;
		ops_to_do = moves_to_place(s_a, s_b, &moves_needed, index);
		if (minimal_moves > moves_needed)
		{
			ft_list_clear(&best_ops, NULL);
			ft_list_add_back(&best_ops, ops_to_do);
			minimal_moves = moves_needed;
		}
		else
			ft_list_clear(&ops_to_do, NULL);
		index--;
	}
	execute_ops(s_a, s_b, best_ops);
	ft_list_add_back(ops, best_ops);
}

void		rev_push_sort(t_list_node **s_a, t_list_node **s_b
															, t_list_node **ops)
{
	push_untagged(s_a, s_b, ops);
	while (*s_b != NULL)
		move_the_best_value(s_a, s_b, ops);
	order_stack(s_a, ops);
}
