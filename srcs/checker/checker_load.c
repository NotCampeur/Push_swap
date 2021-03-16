/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:21:18 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/16 17:11:56 by ldutriez         ###   ########.fr       */
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
			|| ft_strcmp(str, "rrb\n") == true || ft_strcmp(str, "\n") == true)
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
		if (ret == 3 && is_a_valid_operation(buf) == true)
			ft_add_to_tab(ft_strdup(buf), &operations);
		else if (ret == 3 && read(STDIN_FILENO, buf + 3, 1) == 1)
		{
			if (is_a_valid_operation(buf) == true)
				ft_add_to_tab(ft_strdup(buf), &operations);
			else
			{
				return (incorrect_instruction(operations, buf));
			}
		}
		free(buf);
	}
	return (operations);
}

t_list_node		*init_stack(char **args)
{
	int			index;
	char		**splitted_args;
	int			args_nb;
	t_list_node	*result;

	index = 0;
	splitted_args = ft_split(args[1], ' ');
	args_nb = ft_tab_len((void**)splitted_args);
	result = NULL;
	while (index < args_nb)
	{
		ft_list_add_back(&result, ft_malloc_node(splitted_args[index]));
		index++;
	}
	free(splitted_args);
	return (result);
}

int				parse_args(int argc, char *argv[], t_bool *debug)
{
	int	index;
	int	len;

	index = 0;
	if (argc < 2)
		return (EXIT_FAILURE);
	else if (argc == 3 && ft_strcmp(argv[1], "-v"))
		*debug = true;
	else if (argc > 2)
	{
		ft_putstr_fd(2, FT_BOLD_RED"Error\nToo much arguments\n"FT_BASIC);
		return (EXIT_FAILURE);
	}
	len = ft_strlen(argv[1 + *debug]);
	while (index < len)
	{
		if (ft_is_digit(argv[1 + *debug][index]) == false
			&& ft_is_white_space(argv[1 + *debug][index]) == false)
		{
			ft_putstr_fd(2, FT_BOLD_RED"Error\nArg not suitable\n"FT_BASIC);
			return (EXIT_FAILURE);
		}
		index++;
	}
	return (EXIT_SUCCESS);
}