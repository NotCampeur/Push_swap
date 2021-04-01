/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:53:46 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/01 15:06:55 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_bool		is_a_valid_operation(char *str)
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

static t_list_node	*incorrect_instruction(t_list_node **operations, char *buf)
{
	ft_list_clear(operations, free);
	free(buf);
	ft_list_add_back(operations, ft_malloc_node(ft_strdup("Error")));
	return (*operations);
}

t_list_node			*get_instructions(void)
{
	int			ret;
	t_list_node	*operations;
	char		*buf;

	ret = 3;
	operations = NULL;
	while (ret > 2)
	{
		buf = ft_strnew(5);
		ret = read(STDIN_FILENO, buf, 3);
		if (is_a_valid_operation(buf) == true)
			ft_list_add_back(&operations, ft_malloc_node(ft_strdup(buf)));
		else
		{
			if (ret == 3 && read(STDIN_FILENO, buf + 3, 1) == 1
						&& is_a_valid_operation(buf) == true)
				ft_list_add_back(&operations, ft_malloc_node(ft_strdup(buf)));
			else if (ret != 0)
				return (incorrect_instruction(&operations, buf));
		}
		free(buf);
	}
	return (operations);
}
