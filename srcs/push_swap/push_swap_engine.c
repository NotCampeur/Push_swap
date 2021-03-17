/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_engine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:25:29 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/17 13:45:09 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	**gen_instructions(t_list_node *stack_a)
{
	void	**operations;

	operations = ft_tab_new(0);
	if (stack_a != NULL)
	{
		ft_add_to_tab("ra\n", &operations);
		ft_add_to_tab("sa\n", &operations);
		ft_add_to_tab("rra\n", &operations);
	}
	return (operations);
}

void	send_instructions(void **operation)
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

void	quit(t_list_node *stack_a, t_list_node *stack_b, void **ops)
{
	if (stack_a != NULL)
		ft_list_clear(&stack_a, free);
	if (stack_b != NULL)
		ft_list_clear(&stack_b, free);
	if (ops != NULL)
		free(ops);
	exit(0);
}
