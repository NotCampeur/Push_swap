/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:22:24 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/07 16:34:46 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_load_define.h"

static int			find_first(t_node **nodes, int d[3], int i, int result)
{
	if (i < d[SIZE])
	{
		if (nodes[i]->index + i < d[BEST_POD])
		{
			d[BEST_POD] = nodes[i]->index + i;
			result = i;
		}
		return (find_first(nodes, d, i + 1, result));
	}
	return (result);
}

static int			find_best(t_node **nodes, int d[3], int i, int result)
{
	int		pod_tab;
	int		dist_index;
	int		dist_pos;

	if (i < d[SIZE])
	{
		dist_index = nodes[i]->index - nodes[d[POS]]->index;
		dist_pos = i - d[POS];
		if (dist_index >= 0 && dist_pos >= 0)
		{
			pod_tab = dist_index + dist_pos;
			if (pod_tab < d[BEST_POD])
			{
				d[BEST_POD] = pod_tab;
				result = i;
			}
		}
		return (find_best(nodes, d, i + 1, result));
	}
	return (result);
}

void				nodes_markup(t_node **nodes, int data[3], int i
														, t_bool first_time)
{
	if (first_time == true)
	{
		data[BEST_POD] = INT_MAX;
		data[POS] = find_first(nodes, data, 0, -1);
		nodes[data[POS]]->tag = true;
		i = data[POS];
	}
	data[BEST_POD] = INT_MAX;
	if (i < data[SIZE])
	{
		i = find_best(nodes, data, i + 1, -1);
		data[POS] = i;
		if (i >= 0)
			nodes[i]->tag = true;
		else
			i = data[SIZE];
		nodes_markup(nodes, data, i, false);
	}
}

void				index_stack_nodes(t_node **nodes, int size, int i)
{
	int	j;
	int	pod_index;

	if (i < size)
	{
		pod_index = 0;
		j = 0;
		while (j < size)
		{
			if (nodes[i]->value > nodes[j]->value)
				pod_index++;
			j++;
		}
		nodes[i]->index = pod_index;
		index_stack_nodes(nodes, size, i + 1);
	}
}
