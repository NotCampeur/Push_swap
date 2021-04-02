/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_location_to_target.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 12:37:08 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/02 12:54:18 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_algo_define.h"

static int		find_target(t_list_node **s_a, t_list_node *s_b)
{
	t_list_node	*tmp_a;
	int			d[4];

	tmp_a = *s_a;
	d[RESULT] = 0;
	d[INDEX] = 0;
	d[SMALLEST_INDEX] = INT_MAX;
	d[SMALLEST_POS] = 0;
	while ((*s_a) != NULL)
	{
		if (((t_node*)(*s_a)->data)->index < d[SMALLEST_INDEX])
		{
			d[SMALLEST_INDEX] = ((t_node*)(*s_a)->data)->index;
			d[SMALLEST_POS] = d[INDEX];
		}
		if (((t_node*)(*s_a)->data)->index < ((t_node*)s_b->data)->index)
			d[RESULT]++;
		(*s_a) = (*s_a)->next;
		d[INDEX]++;
	}
	*s_a = tmp_a;
	if (d[RESULT] + d[SMALLEST_POS] >= ft_list_size(*s_a))
		d[RESULT] -= ft_list_size(*s_a);
	return (d[RESULT] + d[SMALLEST_POS]);
}

static void		move_location_to_zero(int poses[2], t_list_node **ops
																, int *moves)
{
	while (poses[1] > 0)
	{
		ft_list_add_back(ops, ft_malloc_node("rb\n"));
		(*moves)++;
		poses[1]--;
	}
}

static void		move_to_target_near_end(int sizes[2], int poses[2]
										, t_list_node **ops, int *moves_needed)
{
	if (poses[1] >= sizes[1] / 2)
	{
		while (poses[0] < sizes[0] && poses[1] < sizes[1])
		{
			ft_list_add_back(ops, ft_malloc_node("rrr\n"));
			(*moves_needed)++;
			poses[0]++;
			poses[1]++;
		}
		while (poses[1] < sizes[1])
		{
			ft_list_add_back(ops, ft_malloc_node("rrb\n"));
			(*moves_needed)++;
			poses[1]++;
		}
	}
	else
		move_location_to_zero(poses, ops, moves_needed);
	while (poses[0] < sizes[0])
	{
		ft_list_add_back(ops, ft_malloc_node("rra\n"));
		(*moves_needed)++;
		poses[0]++;
	}
}

static void		move_to_target_near_start(int size_b, int poses[2]
										, t_list_node **ops, int *moves_needed)
{
	if (poses[1] < size_b / 2)
	{
		while (poses[0] > 0 && poses[1] > 0)
		{
			ft_list_add_back(ops, ft_malloc_node("rr\n"));
			(*moves_needed)++;
			poses[0]--;
			poses[1]--;
		}
		move_location_to_zero(poses, ops, moves_needed);
	}
	else
		while (poses[1] < size_b && poses[1] != 0)
		{
			ft_list_add_back(ops, ft_malloc_node("rrb\n"));
			(*moves_needed)++;
			poses[1]++;
		}
	while (poses[0] > 0)
	{
		ft_list_add_back(ops, ft_malloc_node("ra\n"));
		(*moves_needed)++;
		poses[0]--;
	}
}

t_list_node		*moves_to_place(t_list_node **s_a, t_list_node **s_b
											, int *moves_needed, int location)
{
	t_list_node *result;
	int			poses[2];
	int			sizes[2];
	t_list_node	*tmp;
	int			index;

	tmp = *s_b;
	index = 0;
	while (index < location)
	{
		tmp = tmp->next;
		index++;
	}
	result = NULL;
	sizes[0] = ft_list_size(*s_a);
	sizes[1] = ft_list_size(*s_b);
	poses[0] = find_target(s_a, tmp);
	poses[1] = location;
	if (poses[0] >= sizes[0] / 2)
		move_to_target_near_end(sizes, poses, &result, moves_needed);
	else
		move_to_target_near_start(sizes[1], poses, &result, moves_needed);
	ft_list_add_back(&result, ft_malloc_node("pa\n"));
	(*moves_needed)++;
	return (result);
}
