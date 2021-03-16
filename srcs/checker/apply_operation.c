/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:35:34 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/16 14:45:33 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	print_in_log(char *op, t_list_node *stack_a, t_list_node *stack_b)
{
	ft_putstr_fp("log.log", "\n==================================\n", "APPEND");
	ft_putstr_fp("log.log", "Applying : ", "APPEND");
	ft_putstr_fp("log.log", op, "APPEND");
	if (stack_a != NULL)
		ft_list_putstr_fp("log.log", "STACK A", stack_a, "APPEND");
	else
		ft_putstr_fp("log.log", "Stack A is empty\n", "APPEND");
	if (stack_b != NULL)
		ft_list_putstr_fp("log.log", "STACK B", stack_b, "APPEND");
	else
		ft_putstr_fp("log.log", "Stack B is empty\n", "APPEND");
}

void		apply_operation(char **op, t_bool debug,
								t_list_node **stack_a, t_list_node **stack_b)
{
	int	i;

	i = 0;
	while (op[i] != NULL)
	{
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
		if (debug == true)
			print_in_log(op[i], *stack_a, *stack_b);
		i++;
	}
}
