/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_load.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:49:33 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/07 16:34:56 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_load_define.h"

static t_node		**init_stack_nodes(int argc, char **argv, int index
															, t_node **result)
{
	int	data[3];

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
	data[SIZE] = argc;
	nodes_markup(result, data, 0, true);
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
