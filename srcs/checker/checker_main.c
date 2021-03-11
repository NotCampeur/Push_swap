/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:51:21 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/11 16:36:17 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		quit(t_list_node *stack_a, t_list_node *stack_b, void **ops)
{
	ft_list_clear(&stack_a, NULL);
	if (stack_b != NULL)
		ft_list_clear(&stack_b, NULL);
	ft_free_tab(ops);
	exit(0);
}

static t_bool	resolution(t_list_node *stack_a, t_list_node *stack_b)
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

static void		**get_instructions()
{
	int		ret;
	void	**operation;
	char	*readed;
	
	ret = 3;
	operation = ft_tab_new(0);
	readed = ft_strnew(5);
	while (ret > 2)
	{
		ret = read(STDIN_FILENO, readed, 4);
		if (ret > 2)
			ft_add_to_tab(ft_strdup(readed), &operation);
	}
	free(readed);
	return (operation);
}

int				main(int argc, char *argv[])
{
	int			index;
	t_list_node	*stack_a;
	t_list_node	*stack_b;
	void		**operations;

	if (argc < 2)
		return (1);
	index = 2;
	stack_a = ft_malloc_node(argv[1]);
	stack_b = NULL;
	while (index < argc)
	{
		ft_list_add_back(&stack_a, ft_malloc_node(argv[index]));
		index++;
	}
	ft_list_print_str(stack_a);
	operations = get_instructions();
	ft_print_str_tab("Operations", (char **)operations);
	apply_operation((char**)operations, stack_a, stack_b);
	ft_list_print_str(stack_a);
	resolution(stack_a, stack_b);
	quit(stack_a, stack_b, operations);
	return (0);
}
