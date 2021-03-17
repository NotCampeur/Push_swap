/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_engine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:16:15 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/17 13:26:06 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			quit(t_list_node *stack_a, t_list_node *stack_b, void **ops)
{
	if (stack_a != NULL)
		ft_list_clear(&stack_a, free);
	if (stack_b != NULL)
		ft_list_clear(&stack_b, free);
	if (ops != NULL)
		ft_free_tab(ops);
	exit(0);
}

t_bool			resolution(t_list_node *stack_a, t_list_node *stack_b)
{
	t_list_node	*tmp;

	tmp = stack_a;
	if (stack_b != NULL && ft_list_size(stack_b) != 0)
	{
		ft_putstr(FT_BOLD_RED"KO\n"FT_BASIC);
		return (false);
	}
	while (stack_a->next != NULL)
	{
		if (ft_atoi((stack_a->data)) >= ft_atoi((stack_a->next->data)))
		{
			ft_putstr(FT_BOLD_RED"KO\n"FT_BASIC);
			stack_a = tmp;
			return (false);
		}
		stack_a = stack_a->next;
	}
	ft_putstr(FT_BOLD_GREEN"OK\n"FT_BASIC);
	stack_a = tmp;
	return (true);
}
