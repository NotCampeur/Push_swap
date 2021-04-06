/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_load.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:49:33 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/06 16:34:18 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_load_define.h"

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

static void			nodes_markup(t_node **nodes, int size, int i)
{
	int	data[3];

	data[SIZE] = size;
	data[BEST_POD] = INT_MAX;
	if (i < size)
	{
		data[POS] = i;
		i = find_best(nodes, data, i + 1, -1);
		if (i >= 0)
			nodes[i]->tag = true;
		else
			i = size;
		nodes_markup(nodes, size, i);
	}
}

static void			index_stack_nodes(t_node **nodes, int size, int i)
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

static t_node		**init_stack_nodes(int argc, char **argv, int index
															, t_node **result)
{
	if (index == 0)
	{
		result = (t_node**)malloc(sizeof(t_node*) * argc);
		if (result == NULL)
			return (NULL);
	}
	if (index < argc)
	{
		result[index] = (t_node*)malloc(sizeof(t_node));
		if (result[index] == NULL)
			return (NULL);
		result[index]->value = ft_atoi(argv[index]);
		result[index]->index = 0;
		result[index]->tag = false;
		return (init_stack_nodes(argc, argv, index + 1, result));
	}
	index_stack_nodes(result, argc, 0);
	nodes_markup(result, argc, 0);
	return (result);
}

t_list_node			*init_stack(int argc, char **argv)
{
	int			index;
	t_list_node	*result;
	t_node		**nodes;

	index = 0;
	nodes = init_stack_nodes(argc, argv, 0, NULL);
	result = NULL;
	while (index < argc)
	{
		if (nodes[index] == NULL)
		{
			while (index >= 0)
			{
				free(nodes[index]);
				index--;
			}
			free(nodes);
			return (NULL);
		}
		ft_list_add_back(&result, ft_malloc_node(nodes[index]));
		index++;
	}
	free(nodes);
	return (result);
}

t_system			*system_init(void)
{
	t_system	*result;

	result = (t_system*)malloc(sizeof(t_system));
	result->s_a = NULL;
	result->s_b = NULL;
	result->ops = NULL;
	return (result);
}
