/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:51:21 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/10 16:18:36 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		quit(void **stack_a, void **stack_b)
{
	free(stack_a);
	free(stack_b);
	exit(0);
}

static t_bool	resolution(void **stack_a, void **stack_b)
{
	int index;
	int tab_len;

	index = 0;
	tab_len = ft_tab_len(stack_a);
	while (index < tab_len)
	{
		if (stack_b[index] != NULL)
			return (false);
		if (index < tab_len - 1
			&& ft_atoi((stack_a[index])) >= ft_atoi((stack_a[index + 1])))
		{
			/* ft_putstr(FT_BOLD_RED"KO\n"FT_BASIC); */
			return (false);
		}
		index++;
	}
	ft_putstr(FT_BOLD_GREEN"OK\n"FT_BASIC);
	return (true);
}

int				main(int argc, char *argv[])
{
	int		index;
	void	**stack_a;
	void	**stack_b;
	char	*operation;

	if (argc < 2)
	{
		ft_putstr_fd(2, FT_BOLD_RED"Error\nFT_REDArgument is missing"FT_BASIC);
		return (1);
	}
	index = 1;
	stack_a = ft_tab_new(argc - 1);
	stack_b = ft_tab_new(argc - 1);
	operation = ft_strnew(0);
	while (index < argc)
	{
		ft_add_to_tab(argv[index], &stack_a);
		index++;
	}
	while (resolution(stack_a, stack_b) == false)
	{
		ft_print_str_tab("Stack A", (char**)stack_a);
		ft_print_str_tab("Stack B", (char**)stack_b);
		ft_get_next_line(0, &operation);
		apply_operation(operation);
		free(operation);
	}
	quit(stack_a, stack_b);
	return (0);
}
