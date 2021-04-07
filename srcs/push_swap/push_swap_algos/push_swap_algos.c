/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 10:56:05 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/07 13:50:11 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				execute_ops(t_list_node **s_a, t_list_node **s_b
														, t_list_node *ops)
{
	if (ops != NULL)
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
		execute_ops(s_a, s_b, ops);
	}
}

static t_list_node	*catch_best_value(t_system *sys, int index
									, int minimal_moves, t_list_node *result)
{
	int			moves_needed;
	t_list_node	*ops_to_do;

	moves_needed = 0;
	ops_to_do = moves_to_place(&sys->s_a, &sys->s_b, &moves_needed, index);
	if (moves_needed < minimal_moves)
	{
		ft_list_clear(&result, NULL);
		ft_list_add_back(&result, ops_to_do);
		minimal_moves = moves_needed;
	}
	else
		ft_list_clear(&ops_to_do, NULL);
	if (index > 0)
		return (catch_best_value(sys, index - 1, minimal_moves, result));
	return (result);
}

void				move_the_best_value(t_system *sys)
{
	t_list_node	*best_ops;
	t_list_node *tmp;

	best_ops = catch_best_value(sys, ft_list_size(sys->s_b) - 1, INT_MAX, NULL);
	tmp = best_ops;
	execute_ops(&sys->s_a, &sys->s_b, best_ops);
	best_ops = tmp;
	ft_list_add_back(&sys->ops, best_ops);
}

void				rev_push_sort(t_system *sys)
{
	if (sys->s_b != NULL)
	{
		move_the_best_value(sys);
		rev_push_sort(sys);
	}
}
