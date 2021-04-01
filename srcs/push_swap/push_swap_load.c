/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_load.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:49:33 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/01 14:45:11 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		markup_with_value(t_node **nodes, int size, int *tag_max)
{
	int	i;
	int	j;
	int	tag_nb;
	int	max_value;
	int	m_h_index;

	i = 0;
	*tag_max = 0;
	m_h_index = 0;
	while (i < size)
	{
		max_value = INT_MIN;
		j = i;
		tag_nb = 0;
		while (j < size)
		{
			if (max_value < nodes[j]->value)
			{
				max_value = nodes[j]->value;
				tag_nb++;
			}
			j++;
		}
		if (tag_nb > *tag_max)
		{
			*tag_max = tag_nb;
			m_h_index = i;
		}
		i++;
	}
	return (m_h_index);
}

static int		markup_with_index(t_node **nodes, int size, int *tag_max)
{
	int	i;
	int	j;
	int	tag_nb;
	int	last_index;
	int	m_h_index;

	i = 0;
	*tag_max = 0;
	m_h_index = 0;
	while (i < size)
	{
		last_index = nodes[i]->index;
		j = i;
		tag_nb = 0;
		while (j < size)
		{
			if (last_index + 1 == nodes[j]->index)
			{
				last_index++;
				tag_nb++;
			}
			j++;
		}
		if (tag_nb > *tag_max)
		{
			*tag_max = tag_nb;
			m_h_index = i;
		}
		i++;
	}
	return (m_h_index);
}

static int		find_markup_head(t_node **nodes, int size, t_bool *index_type)
{
	int	result_index;
	int	result_value;
	int	tag_nb;
	int	tmp;

	*index_type = false;
	result_index = markup_with_index(nodes, size, &tag_nb);
	tmp = tag_nb;
	result_value = markup_with_value(nodes, size, &tag_nb);
	if (tmp >= tag_nb)
	{
		*index_type = true;
		return (result_index);
	}
	return (result_value);
}

static void		nodes_markup(t_node **nodes, int size)
{
	int		i;
	int		j;
	int		tag_nb;
	int		last_index;
	t_bool	index_type;

	i = find_markup_head(nodes, size, &index_type);
	j = i;
	tag_nb = 0;
	if (index_type == true)
		last_index = nodes[j]->index;
	else
		last_index = nodes[j]->value;
	nodes[j]->tag = true;
	j++;
	while (j < size)
	{
		if (index_type == true)
		{
			if (last_index + 1 == nodes[j]->index)
			{
				last_index++;
				nodes[j]->tag = true;
				tag_nb++;
			}
		}
		else
		{
			if (last_index < nodes[j]->value)
			{
				last_index = nodes[j]->value;
				nodes[j]->tag = true;
				tag_nb++;
			}
		}
		j++;
	}

	j = i;
	while (tag_nb >= 0)
	{
		if (nodes[j]->tag == true)
			tag_nb--;
		j++;
	}
	last_index = nodes[j - 1]->index;
	while (j < size)
	{
		if (last_index < nodes[j]->index)
		{
			last_index = nodes[j]->index;
			nodes[j]->tag = true;
			tag_nb++;
		}
		j++;
	}
	
	j = 0;
	last_index = nodes[i]->index;
	while (j <= i)
	{
		if (last_index > nodes[i - j]->index)
		{
			last_index = nodes[i - j]->index;
			nodes[i - j]->tag = true;
		}
		j++;
	}
}

static void		index_stack_nodes(t_node **nodes, int size)
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

static t_node	**init_stack_nodes(int argc, char **argv)
{
	t_node	**result;
	int		index;

	index = 0;
	result = (t_node**)malloc(sizeof(t_node*) * argc);
	if (result == NULL)
		return (NULL);
	while (index < argc)
	{
		result[index] = (t_node*)malloc(sizeof(t_node));
		if (result[index] == NULL)
		{
			while (index >= 0)
			{
				free(result[index]);
				index--;
			}
			return (NULL);
		}
		result[index]->value = ft_atoi(argv[index]);
		result[index]->index = 0;
		result[index]->tag = false;
		index++;
	}
	index_stack_nodes(result, argc);
	nodes_markup(result, argc);
	return (result);
}

t_list_node		*init_stack(int argc, char **argv)
{
	int			index;
	t_list_node	*result;
	t_node		**nodes;

	index = 0;
	nodes = init_stack_nodes(argc, argv);
	result = NULL;
	while (index < argc)
	{
		ft_list_add_back(&result, ft_malloc_node(nodes[index]));
		index++;
	}
	free(nodes);
	return (result);
}

t_system		*system_init(void)
{
	t_system	*result;

	result = (t_system*)malloc(sizeof(t_system));
	result->s_a = NULL;
	result->s_b = NULL;
	result->ops = NULL;
	return (result);
}
