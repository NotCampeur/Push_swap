/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_load.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:49:33 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/29 16:19:53 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		find_markup_head(t_node **nodes, int size)
{
	int	i;
	int	j;
	int	tag_nb;
	int	tag_max;
	int	max_value;
	int	m_h_index;

	i = 0;
	tag_max = 0;
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
		if (tag_nb > tag_max)
		{
			tag_max = tag_nb;
			m_h_index = i;
		}
		i++;
	}
	ft_putstr_fd(2, "markup_head = [");
	ft_putnbr_fd(2, m_h_index);
	ft_putstr_fd(2, "] with (");
	ft_putnbr_fd(2, tag_max);
	ft_putstr_fd(2, ")\n");
	return (m_h_index);
}

static void		nodes_markup(t_node **nodes, int size)
{
	int	j;
	int	tag_nb;
	int	max_value;

	j = find_markup_head(nodes, size);
	tag_nb = 0;
	max_value = nodes[j]->value;
	nodes[j]->tag = true;
			ft_putstr_fd(2, "[");
			ft_putnbr_fd(2, j);
			ft_putstr_fd(2, "|");
			ft_putnbr_fd(2, nodes[j]->index);
			ft_putstr_fd(2, "|");
			ft_putnbr_fd(2, nodes[j]->value);
			ft_putstr_fd(2, "]\n");
	j++;
	while (j < size)
	{
		if (max_value < nodes[j]->value)
		{
			ft_putstr_fd(2, "[");
			ft_putnbr_fd(2, j);
			ft_putstr_fd(2, "|");
			ft_putnbr_fd(2, nodes[j]->index);
			ft_putstr_fd(2, "|");
			ft_putnbr_fd(2, nodes[j]->value);
			ft_putstr_fd(2, "]\n");
			max_value = nodes[j]->value;
			nodes[j]->tag = true;
			tag_nb++;
		}
		// if (nodes[i]->index == nodes[j]->index - 1 - tag_nb)
		// {
		// 	nodes[j]->tag = true;
		// 	tag_nb++;
		// }
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
