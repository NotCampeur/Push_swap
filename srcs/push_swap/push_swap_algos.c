/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 10:56:05 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/01 12:09:28 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_untagged(t_list_node **s_a, t_list_node **s_b, t_list_node	**ops)
{
	int			count;
	t_list_node	*tmp;
	t_list_node	*tmp_2;

	count = 0;
	tmp = *s_a;
	while ((*s_a) != NULL)
	{

		if (((t_node*)(*s_a)->data)->tag == false)
			count++;
		(*s_a) = (*s_a)->next;
	}
	*s_a = tmp;
	while (count > 0)
	{
		// if ((*s_a)->next != NULL)
		// {
		// 	if (((t_node*)(*s_a)->data)->index == 0
		// 		&& ((t_node*)(*s_a)->next->data)->index == ft_list_size(*s_a))
		// 	{
		// 		if (((t_node*)(*s_a)->data)->tag == false)
		// 		{
		// 			((t_node*)(*s_a)->data)->tag = true;
		// 			count--;
		// 		}
		// 		if (((t_node*)(*s_a)->next->data)->tag == false)
		// 		{
		// 			((t_node*)(*s_a)->next->data)->tag = true;
		// 			count--;
		// 		}
		// 		ft_add_to_tab("sa\n", ops);
		// 		swap_stack(s_a);
		// 	}
		// }
		if ((*s_a)->next != NULL
			&& ((t_node*)(*s_a)->data)->tag == true
			&& ((t_node*)(*s_a)->next->data)->tag == false)
		{
			tmp_2 = ft_list_get_node(s_a, INT_MAX);
			if (((t_node*)(*s_a)->data)->index > ((t_node*)(*s_a)->next->data)->index
			&& (((t_node*)(*s_a)->next->data)->index > ((t_node*)(tmp_2)->data)->index
				))
			{
				((t_node*)(*s_a)->next->data)->tag = true;
				ft_list_add_back(ops, ft_malloc_node("sa\n"));
				swap_stack(s_a);
				count--;
			}
		}
		else if ((*s_a)->next != NULL && (*s_a)->next->next != NULL
			&& ((t_node*)(*s_a)->data)->tag == false
			&& ((t_node*)(*s_a)->next->data)->tag == true)
		{
			tmp_2 = *s_a;
			tmp_2 = tmp_2->next->next;
			while (tmp_2 != NULL && ((t_node*)(tmp_2)->data)->tag == false)
			{
				tmp_2 = tmp_2->next;
			}
			if (tmp_2 != NULL
			&& ((t_node*)(*s_a)->data)->index > ((t_node*)(*s_a)->next->data)->index
			&& ((t_node*)(*s_a)->data)->index < ((t_node*)(tmp_2)->data)->index)
			{
				((t_node*)(*s_a)->data)->tag = true;
				ft_list_add_back(ops, ft_malloc_node("sa\n"));
				swap_stack(s_a);
				count--;
			}
		}
		if (is_in_crescent_order(*s_a) == true)
		{
			count = 0;
		}
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

void	execute_ops(t_list_node **s_a, t_list_node **s_b, t_list_node *ops)
{
	t_list_node *tmp;

	tmp = ops;
	while (ops != NULL)
	{
		if (ft_strcmp(ops->data, "sa\n") || ft_strcmp(ops->data, "ss\n"))
			swap_stack(s_a);
		if (ft_strcmp(ops->data, "sb\n") || ft_strcmp(ops->data, "ss\n"))
			swap_stack(s_b);
		if (ft_strcmp(ops->data, "pa\n"))
			push_a(s_a, s_b);
		if (ft_strcmp(ops->data, "pb\n"))
			push_b(s_a, s_b);
		if (ft_strcmp(ops->data, "ra\n") || ft_strcmp(ops->data, "rr\n"))
			rotate_a(s_a);
		if (ft_strcmp(ops->data, "rb\n") || ft_strcmp(ops->data, "rr\n"))
			rotate_b(s_b);
		if (ft_strcmp(ops->data, "rra\n") || ft_strcmp(ops->data, "rrr\n"))
			reverse_rotate_a(s_a);
		if (ft_strcmp(ops->data, "rrb\n") || ft_strcmp(ops->data, "rrr\n"))
			reverse_rotate_b(s_b);
		ops = ops->next;
	}
	ops = tmp;
}

static int	find_target(t_list_node **s_a, t_list_node **s_b)
{
	t_list_node	*tmp_a;
	int			result;
	int			smallest_index;
	int			index;
	int			smallest_pos;

	tmp_a = *s_a;
	result = 0;
	smallest_index = INT_MAX;
	index = 0;
	smallest_pos = 0;
	while ((*s_a) != NULL)
	{
		if (((t_node*)(*s_a)->data)->index < smallest_index)
		{
			smallest_index = ((t_node*)(*s_a)->data)->index;
			smallest_pos = index;
		}
		if (((t_node*)(*s_a)->data)->index < ((t_node*)(*s_b)->data)->index)
			result++;
		(*s_a) = (*s_a)->next;
		index++;
	}
	*s_a = tmp_a;
	result += smallest_pos;
	if (result >= ft_list_size(*s_a))
		result -= ft_list_size(*s_a);
	return (result);
}

t_list_node	*moves_to_place(t_list_node **s_a, t_list_node **s_b
							, int *moves_needed, int location)
{
	t_list_node *result;
	int			target;
	int			index;
	t_list_node	*tmp_b;
	int			size_a;
	int			size_b;

	result = NULL;
	target = 0;
	index = 0;
	tmp_b = *s_b;
	size_a = ft_list_size(*s_a);
	size_b = ft_list_size(*s_b);
	while (index < location)
	{
		(*s_b) = (*s_b)->next;
		index++;
	}
	target = find_target(s_a, s_b);
	*s_b = tmp_b;
	if (target >= size_a / 2)
	{
		if (location >= size_b / 2)
		{
			while (target < size_a && location < size_b)
			{
				ft_list_add_back(&result, ft_malloc_node("rrr\n"));
				(*moves_needed)++;
				target++;
				location++;
			}
			while (location < size_b)
			{
				ft_list_add_back(&result, ft_malloc_node("rrb\n"));
				(*moves_needed)++;
				location++;
			}
		}
		else
		{
			while (location > 0)
			{
				ft_list_add_back(&result, ft_malloc_node("rb\n"));
				(*moves_needed)++;
				location--;
			}
		}
		while (target < size_a)
		{
			ft_list_add_back(&result, ft_malloc_node("rra\n"));
			(*moves_needed)++;
			target++;
		}
	}
	else if (target < size_a / 2)
	{
		if (location < size_b / 2)
		{
			while (target > 0 && location > 0)
			{
				ft_list_add_back(&result, ft_malloc_node("rr\n"));
				(*moves_needed)++;
				target--;
				location--;
			}
			while (location > 0)
			{
				ft_list_add_back(&result, ft_malloc_node("rb\n"));
				(*moves_needed)++;
				location--;
			}
		}
		else
		{
			while (location < size_b && location != 0)
			{
				ft_list_add_back(&result, ft_malloc_node("rrb\n"));
				(*moves_needed)++;
				location++;
			}
		}
		while (target > 0)
		{
			ft_list_add_back(&result, ft_malloc_node("ra\n"));
			(*moves_needed)++;
			target--;
		}
	}
	
	ft_list_add_back(&result, ft_malloc_node("pa\n"));
	(*moves_needed)++;
	return (result);
}

void	move_the_best_value(t_list_node **s_a,
										t_list_node **s_b, t_list_node	**ops)
{
	int			minimal_moves;
	int			moves_needed;
	int			index;
	t_list_node	*ops_to_do;
	t_list_node	*best_ops;
	t_list_node	*tmp;

	minimal_moves = INT_MAX;
	index = ft_list_size(*s_b) - 1;
	ops_to_do = NULL;
	best_ops = NULL;
	while (index >= 0)
	{
		moves_needed = 0;
		ops_to_do = moves_to_place(s_a, s_b, &moves_needed, index);
		if (minimal_moves > moves_needed)
		{
			ft_list_clear(&best_ops, NULL);
			tmp = ops_to_do;
			while (ops_to_do != NULL)
			{
				ft_list_add_back(&best_ops, ft_malloc_node(ops_to_do->data));
				ops_to_do = ops_to_do->next;
			}
			ops_to_do = tmp;
			minimal_moves = moves_needed;
		}
		ft_list_clear(&ops_to_do, NULL);
		index--;
	}
	execute_ops(s_a, s_b, best_ops);
	ft_list_add_back(ops, best_ops);
}

static void	order_stack(t_list_node **s_a, t_list_node	**ops)
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
	{
		while (pos < size_a)
		{
			ft_list_add_back(ops, ft_malloc_node("rra\n"));
			reverse_rotate_a(s_a);
			pos++;
		}
	}
	else
	{
		while (pos > 0)
		{
			ft_list_add_back(ops, ft_malloc_node("ra\n"));
			rotate_a(s_a);
			pos--;
		}
	}
}

void	rev_push_sort(t_list_node **s_a, t_list_node **s_b, t_list_node	**ops)
{
	push_untagged(s_a, s_b, ops);
	// ft_putstr_fd(2, "Untaggeds pushed, list size = [");
	// ft_putnbr_fd(2, ft_list_size(*s_a));
	// ft_putstr_fd(2, "]\n");
	while (*s_b != NULL)
	{
		move_the_best_value(s_a, s_b, ops);
	}
	// ft_putstr_fd(2, "Stack_b is empty\n");
	order_stack(s_a, ops);
	// while (is_sort(*s_a, *s_b) == false)
		// push_smallest_a_on_b(s_a, s_b, ops);
		// if (*s_a == NULL || ft_list_size(*s_a) <= 1)
			// empty_stack(s_a, s_b, ops);
}
