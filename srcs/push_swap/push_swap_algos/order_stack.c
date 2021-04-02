/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 10:09:46 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/02 10:29:43 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pos_is_near_end(t_list_node **s_a, t_list_node **ops
														, int pos, int size_a)
{
	while (pos < size_a)
	{
		ft_list_add_back(ops, ft_malloc_node("rra\n"));
		reverse_rotate_a(s_a);
		pos++;
	}
}

static void	pos_is_near_start(t_list_node **s_a, t_list_node **ops, int pos)
{
	while (pos > 0)
	{
		ft_list_add_back(ops, ft_malloc_node("ra\n"));
		rotate_a(s_a);
		pos--;
	}
}

void		order_stack(t_list_node **s_a, t_list_node **ops)
{
	t_list_node	*tmp;
	int			pos;
	int			size_a;
	int			is_odd;

	tmp = *s_a;
	pos = 0;
	size_a = ft_list_size(*s_a);
	is_odd = size_a % 2;
	while (((t_node*)(*s_a)->data)->index != 0)
	{
		pos++;
		(*s_a) = (*s_a)->next;
	}
	*s_a = tmp;
	if (pos >= size_a / 2 + is_odd && pos != 0)
		pos_is_near_end(s_a, ops, pos, size_a);
	else
		pos_is_near_start(s_a, ops, pos);
}
