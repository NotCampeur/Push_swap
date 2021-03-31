/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 10:56:05 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/31 14:33:56 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_smallest_a_on_b(t_list_node **s_a, t_list_node **s_b, void ***ops)
{
	if (*s_a != NULL && *s_b == NULL)
	{
		while (((t_node*)(*s_a)->data)->index != 0)
		{
			ft_add_to_tab("ra\n", ops);
			rotate_a(s_a);
		}
	}
	else if (*s_a != NULL)
	{
		while (((t_node*)(*s_a)->data)->index
		!= ((t_node*)(*s_b)->data)->index + 1)
		{
			ft_add_to_tab("ra\n", ops);
			rotate_a(s_a);
		}
	}
	ft_add_to_tab("pb\n", ops);
	push_b(s_a, s_b);
}

void	empty_stack(t_list_node **s_a, t_list_node **s_b, void ***ops)
{
	while (*s_a != NULL)
	{
		ft_add_to_tab("pa\n", ops);
		push_a(s_a, s_b);
	}
}

void	push_untagged(t_list_node **s_a, t_list_node **s_b, void ***ops)
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
				ft_add_to_tab("sa\n", ops);
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
				ft_add_to_tab("sa\n", ops);
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
			ft_add_to_tab("pb\n", ops);
			push_b(s_a, s_b);
			count--;
		}
		else if (((t_node*)(*s_a)->data)->tag == true)
		{
			ft_add_to_tab("ra\n", ops);
			rotate_a(s_a);
		}
	}
}

void	execute_ops(t_list_node **s_a, t_list_node **s_b, char **ops)
{
	int	i;

	i = 0;
	while (ops[i] != NULL)
	{
		if (ft_strcmp(ops[i], "sa\n") == 1 || ft_strcmp(ops[i], "ss\n") == 1)
			swap_stack(s_a);
		if (ft_strcmp(ops[i], "sb\n") == 1 || ft_strcmp(ops[i], "ss\n") == 1)
			swap_stack(s_b);
		if (ft_strcmp(ops[i], "pa\n") == 1)
			push_a(s_a, s_b);
		if (ft_strcmp(ops[i], "pb\n") == 1)
			push_b(s_a, s_b);
		if (ft_strcmp(ops[i], "ra\n") == 1 || ft_strcmp(ops[i], "rr\n") == 1)
			rotate_a(s_a);
		if (ft_strcmp(ops[i], "rb\n") == 1 || ft_strcmp(ops[i], "rr\n") == 1)
			rotate_b(s_b);
		if (ft_strcmp(ops[i], "rra\n") == 1 || ft_strcmp(ops[i], "rrr\n") == 1)
			reverse_rotate_a(s_a);
		if (ft_strcmp(ops[i], "rrb\n") == 1 || ft_strcmp(ops[i], "rrr\n") == 1)
			reverse_rotate_b(s_b);
		i++;
	}
}

// static void	undo_ops(t_list_node **s_a, t_list_node **s_b, char **ops)
// {
// 	int	i;

// 	i = ft_tab_len((void**)ops) - 1;
// 	while (i >= 0)
// 	{
// 		if (ft_strcmp(ops[i], "sa\n") == 1 || ft_strcmp(ops[i], "ss\n") == 1)
// 			swap_stack(s_a);
// 		if (ft_strcmp(ops[i], "sb\n") == 1 || ft_strcmp(ops[i], "ss\n") == 1)
// 			swap_stack(s_b);
// 		if (ft_strcmp(ops[i], "pa\n") == 1)
// 			push_b(s_a, s_b);
// 		if (ft_strcmp(ops[i], "pb\n") == 1)
// 			push_a(s_a, s_b);
// 		if (ft_strcmp(ops[i], "ra\n") == 1 || ft_strcmp(ops[i], "rr\n") == 1)
// 			reverse_rotate_a(s_a);
// 		if (ft_strcmp(ops[i], "rb\n") == 1 || ft_strcmp(ops[i], "rr\n") == 1)
// 			reverse_rotate_b(s_b);
// 		if (ft_strcmp(ops[i], "rra\n") == 1 || ft_strcmp(ops[i], "rrr\n") == 1)
// 			rotate_a(s_a);
// 		if (ft_strcmp(ops[i], "rrb\n") == 1 || ft_strcmp(ops[i], "rrr\n") == 1)
// 			rotate_b(s_b);
// 		i--;
// 	}
// }

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

void	**moves_to_place(t_list_node **s_a, t_list_node **s_b, int *moves_needed
																, int location)
{
	void		**result;
	int			target;
	int			index;
	t_list_node	*tmp_b;
	int			size_a;
	int			size_b;

	result = ft_tab_new(0);
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
	// ft_putstr_fd(2, "[");
	// ft_putnbr_fd(2, location);
	// ft_putstr_fd(2, "] location to [");
	// ft_putnbr_fd(2, target);
	// ft_putstr_fd(2, "] target \n");
	*s_b = tmp_b;
	if (target >= size_a / 2)
	{
		if (location >= size_b / 2)
		{
			while (target < size_a && location < size_b)
			{
				ft_add_to_tab("rrr\n", &result);
				// reverse_rotate_a(s_a);
				// reverse_rotate_b(s_b);
				(*moves_needed)++;
				target++;
				location++;
			}
			while (location < size_b)
			{
				ft_add_to_tab("rrb\n", &result);
				// reverse_rotate_b(s_b);
				(*moves_needed)++;
				location++;
			}
		}
		else
		{
			while (location > 0)
			{
				ft_add_to_tab("rb\n", &result);
				// rotate_b(s_b);
				(*moves_needed)++;
				location--;
			}
		}
		while (target < size_a)
		{
			ft_add_to_tab("rra\n", &result);
			// reverse_rotate_a(s_a);
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
				ft_add_to_tab("rr\n", &result);
				// rotate_a(s_a);
				// rotate_b(s_b);
				(*moves_needed)++;
				target--;
				location--;
			}
			while (location > 0)
			{
				ft_add_to_tab("rb\n", &result);
				// rotate_b(s_b);
				(*moves_needed)++;
				location--;
			}
		}
		else
		{
			while (location < size_b && location != 0)
			{
				ft_add_to_tab("rrb\n", &result);
				// reverse_rotate_b(s_b);
				(*moves_needed)++;
				location++;
			}
		}
		while (target > 0)
		{
			ft_add_to_tab("ra\n", &result);
			// rotate_a(s_a);
			(*moves_needed)++;
			target--;
		}
	}
	
	ft_add_to_tab("pa\n", &result);
	// push_a(s_a, s_b);
	(*moves_needed)++;
	// undo_ops(s_a, s_b, (char**)result);
	return (result);
}

void	move_the_best_value(t_list_node **s_a, t_list_node **s_b, void ***ops)
{
	int		minimal_moves;
	int		moves_needed;
	int		index;
	void	**ops_to_do;
	void	**best_ops;

	minimal_moves = INT_MAX;
	index = ft_list_size(*s_b) - 1;
	best_ops = NULL;
	while (index >= 0)
	{
		moves_needed = 0;
		ops_to_do = moves_to_place(s_a, s_b, &moves_needed, index);
		if (minimal_moves > moves_needed)
		{
			free(best_ops);
			best_ops = ft_tab_new(ft_tab_len(ops_to_do));
			ft_tab_cpy(best_ops, ops_to_do);
			minimal_moves = moves_needed;
		}
		free(ops_to_do);
		index--;
	}
	execute_ops(s_a, s_b, (char**)best_ops);
	index = 0;
	while (best_ops[index] != NULL)
	{
		ft_add_to_tab(best_ops[index], ops);
		index++;
	}
	free(best_ops);
}

static void	order_stack(t_list_node **s_a, void ***ops)
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
			ft_add_to_tab("rra\n", ops);
			reverse_rotate_a(s_a);
			pos++;
		}
	}
	else
	{
		while (pos > 0)
		{
			ft_add_to_tab("ra\n", ops);
			rotate_a(s_a);
			pos--;
		}
	}
}

void	rev_push_sort(t_list_node **s_a, t_list_node **s_b, void ***ops)
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
