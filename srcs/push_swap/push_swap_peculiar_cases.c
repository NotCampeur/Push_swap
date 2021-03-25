/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_peculiar_cases.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:49:24 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/25 17:59:45 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_in_descending_order(t_list_node *stack_a)
{
	t_list_node	*tmp;

	tmp = stack_a;
	while (stack_a->next != NULL)
	{
		if (ft_atoi((stack_a->data)) < ft_atoi((stack_a->next->data)))
			break ;
		if (stack_a->next->next == NULL)
		{
			stack_a = tmp;
			return (true);
		}
		stack_a = stack_a->next;
	}
	stack_a = tmp;
	return (false);
}

t_bool	is_in_crescent_order(t_list_node *stack_a)
{
	t_list_node	*tmp;

	tmp = stack_a;
	while (stack_a->next != NULL)
	{
		if (ft_atoi((stack_a->data)) > ft_atoi((stack_a->next->data)))
			break ;
		if (stack_a->next->next == NULL)
		{
			stack_a = tmp;
			return (true);
		}
		stack_a = stack_a->next;
	}
	stack_a = tmp;
	return (false);
}

t_bool	is_in_following_order(t_list_node *stack_a, void ***operations)
{
	int			index;
	int			list_size;

	index = 0;
	list_size = ft_list_size(stack_a);
	if (is_in_crescent_order(stack_a) == true)
		return (true);
	else if (is_in_descending_order(stack_a) == true)
	{
		while (index < list_size)
		{
			ft_add_to_tab("rra\n", operations);
			ft_add_to_tab("pb\n", operations);
			index++;
		}
		index = 0;
		while (index < list_size)
		{
			ft_add_to_tab("pa\n", operations);
			index++;
		}
		return (true);
	}
	return (false);
}
