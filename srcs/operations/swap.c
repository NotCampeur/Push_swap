/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:51:03 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/25 17:19:50 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_c_operations.h"

void	swap_stack(t_list_node **stack)
{
	void *tmp;

	if (ft_list_size(*stack) > 1)
	{
		tmp = (*stack)->next->data;
		(*stack)->next->data = (*stack)->data;
		(*stack)->data = tmp;
	}
}
