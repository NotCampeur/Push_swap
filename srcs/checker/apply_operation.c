/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:35:34 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/11 16:20:30 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	apply_operation(char **op, t_list_node *stack_a, t_list_node *stack_b)
{
	int	i;

	i = 0;
	while (op[i] != NULL)
	{
		if (ft_strcmp(op[i], "sa\n") == true || ft_strcmp(op[i], "ss\n") == true)
			swap_a(stack_a);
		if (ft_strcmp(op[i], "sb\n") == true || ft_strcmp(op[i], "ss\n") == true)
			swap_b(stack_b);
		if (ft_strcmp(op[i], "pa\n") == true)
			push_a(stack_a, stack_b);
		if (ft_strcmp(op[i], "pb\n") == true)
			push_b(stack_a, stack_b);
		if (ft_strcmp(op[i], "ra\n") == true || ft_strcmp(op[i], "rr\n") == true)
			rotate_a(stack_a);
		if (ft_strcmp(op[i], "rb\n") == true || ft_strcmp(op[i], "rr\n") == true)
			rotate_b(stack_b);
		if (ft_strcmp(op[i], "rra\n") == true || ft_strcmp(op[i], "rrr\n") == true)
			reverse_rotate_a(stack_a);
		if (ft_strcmp(op[i], "rrb\n") == true || ft_strcmp(op[i], "rrr\n") == true)
			reverse_rotate_b(stack_b);		
		i++;	
	}
}
