/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_engine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:25:29 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/07 16:49:53 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool		is_sort(t_list_node *stack_a, t_list_node *stack_b)
{
	t_list_node	*tmp;

	tmp = stack_a;
	if (stack_b != NULL && ft_list_size(stack_b) != 0)
		return (false);
	while (stack_a->next != NULL)
	{
		if (((t_node*)stack_a->data)->value >=
										((t_node*)stack_a->next->data)->value)
		{
			stack_a = tmp;
			return (false);
		}
		stack_a = stack_a->next;
	}
	stack_a = tmp;
	return (true);
}

void		gen_instructions(t_system *sys)
{
	push_untagged(&sys->s_a, &sys->s_b, &sys->ops);
	rev_push_sort(sys);
	order_stack(&sys->s_a, &sys->ops);
}

void		send_instructions(t_list_node *operation)
{
	t_list_node	*tmp;

	tmp = operation;
	while (operation != NULL)
	{
		ft_putstr(operation->data);
		operation = operation->next;
	}
	operation = tmp;
}

void		quit(t_system *sys, int exit_nb)
{
	if (sys->s_a != NULL)
		ft_list_clear(&sys->s_a, free);
	if (sys->s_b != NULL)
		ft_list_clear(&sys->s_b, free);
	if (sys->ops != NULL)
		ft_list_clear(&sys->ops, NULL);
	free(sys);
	exit(exit_nb);
}

t_system	*system_init(void)
{
	t_system	*result;

	result = (t_system*)malloc(sizeof(t_system));
	result->s_a = NULL;
	result->s_b = NULL;
	result->ops = NULL;
	return (result);
}
