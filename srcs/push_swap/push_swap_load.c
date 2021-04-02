/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_load.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:49:33 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/02 15:01:54 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int			go_to_next_smallest(t_node **nodes, int size, int j)
{
	int		smallest;
	int		index_small;
	int		tmp_small;

	smallest = 0;
	tmp_small = INT_MAX;
	index_small = 0;
	while (j < size)
	{
		if (tmp_small > nodes[j]->value && tmp_small < smallest)
		{
			smallest = tmp_small;
			index_small = j;
		}
		j++;
	}
	return (index_small);
}

static t_list_node	*markup_with_value(t_node **nodes, int size)
{
	int	i;
	int	j;
	int	o;
	int	tag_nb;
	int	max_value;
	t_list_node	*indexes;
	t_list_node	*tmp;
	int	tag_max;

	i = 0;
	tag_max = 0;
	indexes = NULL;
	while (i < size)
	{
		max_value = INT_MIN;
		tmp = NULL;
		j = i;
		tag_nb = 0;
		while (j < size)
		{
			o = 0;
			while (o < size)
			{
				o = go_to_next_smallest(nodes, size, j);
				if (max_value <= nodes[j]->value)
				{
					ft_list_add_back(&tmp, ft_malloc_node(ft_itoa(j)));
					max_value = nodes[j]->value;
					tag_nb++;
				}
				o++;
			}
			j++;
			if (tag_nb > tag_max)
			{
				ft_list_clear(&indexes, free);
				ft_list_add_back(&indexes, tmp);
				tag_max = tag_nb;
			}
			else
				ft_list_clear(&tmp, free);
		}
		i++;
	}
	return (indexes);
}

static void			nodes_markup(t_node **nodes, int size)
{
	t_list_node	*indexes;
	t_list_node	*tmp;

	indexes = markup_with_value(nodes, size);
	tmp = indexes;
	while (indexes != NULL)
	{
		nodes[ft_atoi(((char*)indexes->data))]->tag = true;
		indexes = indexes->next;
	}
	ft_list_clear(&tmp, free);
}

static void			index_stack_nodes(t_node **nodes, int size)
{
	int	i;
	int	j;
	int	pod_index;

	i = 0;
	while (i < size)
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
		i++;
	}
	i = 0;
}

static t_node		**init_stack_nodes(int argc, char **argv)
{
	int		index;
	t_node	**result;

	index = 0;
	result = (t_node**)malloc(sizeof(t_node*) * argc);
	if (result == NULL)
		return (NULL);
	while (index < argc)
	{
		result[index] = (t_node*)malloc(sizeof(t_node));
		if (result[index] == NULL)
			return (NULL);
		result[index]->value = ft_atoi(argv[index]);
		result[index]->index = 0;
		result[index]->tag = false;
		index++;
	}
	index_stack_nodes(result, argc);
	nodes_markup(result, argc);
	return (result);
}

t_list_node			*init_stack(int argc, char **argv)
{
	int			index;
	t_list_node	*result;
	t_node		**nodes;

	index = 0;
	nodes = init_stack_nodes(argc, argv);
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
