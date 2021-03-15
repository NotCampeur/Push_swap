/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_engine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:16:15 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/15 16:24:25 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			quit(t_list_node *stack_a, t_list_node *stack_b, void **ops)
{
	ft_list_clear(&stack_a, NULL);
	if (stack_b != NULL)
		ft_list_clear(&stack_b, NULL);
	ft_free_tab(ops);
	exit(0);
}

t_bool			resolution(t_list_node *stack_a, t_list_node *stack_b)
{
	int stack_len;

	stack_len = ft_list_size(stack_a);
	if (stack_b != NULL && ft_list_size(stack_b) != 0)
	{
		ft_putstr(FT_BOLD_RED"KO\n"FT_BASIC);
		return (false);
	}
	while (stack_a->next != NULL)
	{
		if (ft_atoi((stack_a->data)) >= ft_atoi((stack_a->next->data)))
		{
			ft_putstr(FT_BOLD_RED"KO\n"FT_BASIC);
			return (false);
		}
		stack_a = stack_a->next;
	}
	ft_putstr(FT_BOLD_GREEN"OK\n"FT_BASIC);
	return (true);
}

void			**get_instructions(void)
{
	int		ret;
	void	**operations;
	char	*buf;

	ret = 3;
	operations = ft_tab_new(0);
	buf = ft_strnew(5);
	while (ret > 2)
	{
		ret = read(STDIN_FILENO, buf, 4);
		if (ret > 2
			&& (ft_strcmp(buf, "sa\n") == true || ft_strcmp(buf, "ss\n") == true
			|| ft_strcmp(buf, "sb\n") == true || ft_strcmp(buf, "ss\n") == true
			|| ft_strcmp(buf, "pa\n") == true || ft_strcmp(buf, "pb\n") == true
			|| ft_strcmp(buf, "ra\n") == true || ft_strcmp(buf, "rr\n") == true
			|| ft_strcmp(buf, "rb\n") == true || ft_strcmp(buf, "rr\n") == true
			|| ft_strcmp(buf, "rra\n") == true
			|| ft_strcmp(buf, "rrr\n") == true
			|| ft_strcmp(buf, "rrb\n") == true
			|| ft_strcmp(buf, "rrr\n") == true))
			ft_add_to_tab(ft_strdup(buf), &operations);
		else
			break ;
	}
	free(buf);
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
		ft_putstr_fd(2, FT_BOLD_RED"Error\nToo much arguments"FT_BASIC);
		return (EXIT_FAILURE);
	}
	len = ft_strlen(argv[1 + *debug]);
	while (index < len)
	{
		if (ft_is_digit(argv[1 + *debug][index]) == false
			&& ft_is_white_space(argv[1 + *debug][index]) == false)
		{
			ft_putstr_fd(2, FT_BOLD_RED"Error\nArg not well formated"FT_BASIC);
			return (EXIT_FAILURE);
		}
		index++;
	}
	return (EXIT_SUCCESS);
}
