/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_engine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:25:29 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/25 18:08:07 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool			is_sort(t_list_node *stack_a, t_list_node *stack_b)
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

void			**gen_instructions(t_list_node **stack_a, t_list_node **stack_b)
{
	void		**operations;

	operations = ft_tab_new(0);
	if (is_in_following_order(*stack_a, &operations) == true)
		return (operations);
	rev_push_sort(stack_a, stack_b, &operations);
	return (operations);
}

void			send_instructions(void **operation)
{
	int	index;
	int	len;

	index = 0;
	len = ft_tab_len(operation);
	while (index < len)
	{
		ft_putstr(operation[index]);
		index++;
	}
}

void			quit(t_list_node *stack_a, t_list_node *stack_b, void **ops)
{
	if (stack_a != NULL)
		ft_list_clear(&stack_a, free);
	if (stack_b != NULL)
		ft_list_clear(&stack_b, free);
	if (ops != NULL)
		free(ops);
	exit(0);
}
