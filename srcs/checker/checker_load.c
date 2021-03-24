/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:21:18 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/24 11:23:29 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_bool	is_a_valid_operation(char *str)
{
	if (ft_strcmp(str, "sa\n") == true || ft_strcmp(str, "rrr\n") == true
			|| ft_strcmp(str, "sb\n") == true || ft_strcmp(str, "ss\n") == true
			|| ft_strcmp(str, "pa\n") == true || ft_strcmp(str, "pb\n") == true
			|| ft_strcmp(str, "ra\n") == true || ft_strcmp(str, "rb\n") == true
			|| ft_strcmp(str, "rr\n") == true || ft_strcmp(str, "rra\n") == true
			|| ft_strcmp(str, "rrb\n") == true)
		return (true);
	return (false);
}

static void		*incorrect_instruction(void **operations, char *buf)
{
	ft_free_tab(operations);
	free(buf);
	return (NULL);
}

void			**get_instructions(void)
{
	int		ret;
	void	**operations;
	char	*buf;

	ret = 3;
	operations = ft_tab_new(0);
	while (ret > 2)
	{
		buf = ft_strnew(5);
		ret = read(STDIN_FILENO, buf, 3);
		if (is_a_valid_operation(buf) == true)
			ft_add_to_tab(ft_strdup(buf), &operations);
		else if (ft_strcmp(buf, "\n") == false)
		{
			if (ret == 3 && read(STDIN_FILENO, buf + 3, 1) == 1
						&& is_a_valid_operation(buf) == true)
				ft_add_to_tab(ft_strdup(buf), &operations);
			else if (ret != 0)
				return (incorrect_instruction(operations, buf));
		}
		free(buf);
	}
	return (operations);
}

void			index_stack_nodes(t_node **nodes, int size)
{
	int	i;
	int	j;
	int	pod_index;

	i = 0;
	while (i < size)
	{
		pod_index = 0;;
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
	// ft_putstr_fp("log_push_swap.log", "INDEXING THE STACK\n", "OVERWRITE");
	// while (i < size)
	// {
	// 	ft_putnbr_fp("log_push_swap.log", nodes[i]->value, "APPEND");
	// 	ft_putstr_fp("log_push_swap.log", " <- | -> ", "APPEND");
	// 	ft_putnbr_fp("log_push_swap.log", nodes[i]->index, "APPEND");
	// 	ft_putstr_fp("log_push_swap.log", "\n", "APPEND");
	// 	i++;
	// }
}

t_node			**init_stack_nodes(char **splitted_args, int args_nb)
{
	t_node	**result;
	int		index;

	index = 0;
	result = (t_node**)malloc(sizeof(t_node*) * args_nb);
	if (result == NULL)
		return (ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_MLC));
	while (index < args_nb)
	{
		result[index] = (t_node*)malloc(sizeof(t_node));
		if (result[index] == NULL)
		{
			while (index >= 0)
			{
				free(result[index]);
				index--;
			}
			return (ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_MLC));
		}
		result[index]->value = ft_atoi(splitted_args[index]);
		result[index]->index = 0;
		index++;
	}
	index_stack_nodes(result, args_nb);
	ft_free_tab((void**)splitted_args);
	return (result);
}

t_list_node		*init_stack(char **args)
{
	int			index;
	char		**splitted_args;
	int			args_nb;
	t_list_node	*result;
	t_node		**nodes;
	
	index = 0;
	splitted_args = ft_split(args[1], ' ');
	args_nb = ft_tab_len((void**)splitted_args);
	nodes = init_stack_nodes(splitted_args, args_nb);
	result = NULL;
	while (index < args_nb)
	{
		ft_list_add_back(&result, ft_malloc_node(nodes[index]));
		index++;
	}
	free(nodes);
	return (result);
}
