/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_apply_operation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:35:34 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/01 15:01:12 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	apply_operation(t_list_node *op, t_list_node **s_a, t_list_node **s_b)
{
	t_list_node *tmp;

	tmp = op;
	while (op != NULL)
	{
		if (ft_strcmp(op->data, "sa\n") || ft_strcmp(op->data, "ss\n"))
			swap_stack(s_a);
		if (ft_strcmp(op->data, "sb\n") || ft_strcmp(op->data, "ss\n"))
			swap_stack(s_b);
		if (ft_strcmp(op->data, "pa\n"))
			push_a(s_a, s_b);
		if (ft_strcmp(op->data, "pb\n"))
			push_b(s_a, s_b);
		if (ft_strcmp(op->data, "ra\n") || ft_strcmp(op->data, "rr\n"))
			rotate_a(s_a);
		if (ft_strcmp(op->data, "rb\n") || ft_strcmp(op->data, "rr\n"))
			rotate_b(s_b);
		if (ft_strcmp(op->data, "rra\n") || ft_strcmp(op->data, "rrr\n"))
			reverse_rotate_a(s_a);
		if (ft_strcmp(op->data, "rrb\n") || ft_strcmp(op->data, "rrr\n"))
			reverse_rotate_b(s_b);
		op = op->next;
	}
	op = tmp;
}
