/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:51:21 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/29 16:22:24 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int				main(int argc, char *argv[])
{
	t_list_node		*stack_a;
	t_list_node		*stack_b;
	void			**operations;

	if (parse_args(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	stack_a = init_stack(argc - 1, argv + 1);
	if (stack_a == NULL)
		return (EXIT_FAILURE);
	stack_b = NULL;
	operations = get_instructions();
	if (operations == NULL)
	{
		ft_putstr_fd(2, FT_BOLD_RED"Error\n"FT_BASIC);
		error_quit(stack_a, stack_b, operations);
	}
	apply_operation((char**)operations, &stack_a, &stack_b);
	resolution(stack_a, stack_b);
	quit(stack_a, stack_b, operations);
	return (EXIT_SUCCESS);
}
