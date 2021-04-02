/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_untagged_manager.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 09:28:03 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/02 10:05:07 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_untagged(t_list_node *s_a)
{
	int			result;
	t_list_node	*tmp;

	result = 0;
	tmp = s_a;
	while (s_a != NULL)
	{
		if (((t_node*)s_a->data)->tag == false)
			result++;
		s_a = s_a->next;
	}
	s_a = tmp;
	return (result);
}

static void	is_true_and_swappable(t_list_node **s_a, t_list_node **ops
															, int *remaining)
{
	t_list_node	*tmp;

	if ((*s_a)->next != NULL
		&& ((t_node*)(*s_a)->data)->tag == true
		&& ((t_node*)(*s_a)->next->data)->tag == false)
	{
		tmp = ft_list_get_node(s_a, INT_MAX);
		if (((t_node*)(*s_a)->data)->index
										> ((t_node*)(*s_a)->next->data)->index
		&& (((t_node*)(*s_a)->next->data)->index > ((t_node*)tmp->data)->index))
		{
			((t_node*)(*s_a)->next->data)->tag = true;
			ft_list_add_back(ops, ft_malloc_node("sa\n"));
			swap_stack(s_a);
			(*remaining)--;
		}
	}
}

static void	is_false_and_swappable(t_list_node **s_a, t_list_node **ops
															, int *remaining)
{
	t_list_node	*tmp;

	if ((*s_a)->next != NULL && (*s_a)->next->next != NULL
		&& ((t_node*)(*s_a)->data)->tag == false
		&& ((t_node*)(*s_a)->next->data)->tag == true)
	{
		tmp = *s_a;
		tmp = tmp->next->next;
		while (tmp != NULL && ((t_node*)(tmp)->data)->tag == false)
		{
			tmp = tmp->next;
		}
		if (tmp != NULL
		&& ((t_node*)(*s_a)->data)->index > ((t_node*)(*s_a)->next->data)->index
		&& ((t_node*)(*s_a)->data)->index < ((t_node*)(tmp)->data)->index)
		{
			((t_node*)(*s_a)->data)->tag = true;
			ft_list_add_back(ops, ft_malloc_node("sa\n"));
			swap_stack(s_a);
			(*remaining)--;
		}
	}
}

void		push_untagged(t_list_node **s_a, t_list_node **s_b
															, t_list_node **ops)
{
	int			count;

	count = count_untagged(*s_a);
	while (count > 0)
	{
		is_true_and_swappable(s_a, ops, &count);
		is_false_and_swappable(s_a, ops, &count);
		if (is_in_crescent_order(*s_a) == true)
			count = 0;
		else if (((t_node*)(*s_a)->data)->tag == false)
		{
			ft_list_add_back(ops, ft_malloc_node("pb\n"));
			push_b(s_a, s_b);
			count--;
		}
		else if (((t_node*)(*s_a)->data)->tag == true)
		{
			ft_list_add_back(ops, ft_malloc_node("ra\n"));
			rotate_a(s_a);
		}
	}
}
