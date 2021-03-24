/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_apply_operation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:35:34 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/24 18:08:49 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		apply_operation(char **op, t_list_node **stack_a,
				t_list_node **stack_b, t_bool debug, t_visualizer *visualizer)
{
	int	i;

	i = 0;
	while (op[i] != NULL)
	{
		if (debug == true)
			draw_stacks(visualizer, stack_a, stack_b);
		if (ft_strcmp(op[i], "sa\n") == 1 || ft_strcmp(op[i], "ss\n") == 1)
			swap_a(stack_a);
		if (ft_strcmp(op[i], "sb\n") == 1 || ft_strcmp(op[i], "ss\n") == 1)
			swap_b(stack_b);
		if (ft_strcmp(op[i], "pa\n") == 1)
			push_a(stack_a, stack_b);
		if (ft_strcmp(op[i], "pb\n") == 1)
			push_b(stack_a, stack_b);
		if (ft_strcmp(op[i], "ra\n") == 1 || ft_strcmp(op[i], "rr\n") == 1)
			rotate_a(stack_a);
		if (ft_strcmp(op[i], "rb\n") == 1 || ft_strcmp(op[i], "rr\n") == 1)
			rotate_b(stack_b);
		if (ft_strcmp(op[i], "rra\n") == 1 || ft_strcmp(op[i], "rrr\n") == 1)
			reverse_rotate_a(stack_a);
		if (ft_strcmp(op[i], "rrb\n") == 1 || ft_strcmp(op[i], "rrr\n") == 1)
			reverse_rotate_b(stack_b);
		i++;
	}
}
