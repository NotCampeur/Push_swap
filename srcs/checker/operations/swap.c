/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:51:03 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/11 16:34:28 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    swap_a(t_list_node *stack_a)
{
	void *tmp;

	if (ft_list_size(stack_a) > 1)
	{
		tmp = stack_a->next->data;
		stack_a->next->data = stack_a->data;
		stack_a->data = tmp;
	}
}

void    swap_b(t_list_node *stack_b)
{
	void *tmp;
	
	if (ft_list_size(stack_b) > 1)
	{
		tmp = stack_b->next->data;
		stack_b->next->data = stack_b->data;
		stack_b->data = tmp;
	}
}
