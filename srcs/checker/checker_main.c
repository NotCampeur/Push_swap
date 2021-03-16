/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:51:21 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/16 12:41:44 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int				main(int argc, char *argv[])
{
	t_list_node	*stack_a;
	t_list_node	*stack_b;
	void		**operations;
	t_bool		debug;

	debug = false;
	if (parse_args(argc, argv, &debug) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	stack_a = init_stack(argv + debug);
	stack_b = NULL;
	operations = get_instructions();
	if (operations == NULL)
	{
		ft_putstr_fd(2, FT_BOLD_RED"Error\nWrong operation\n"FT_BASIC);
		quit(stack_a, stack_b, operations);
	}
	if (debug == true)
		start_debug(operations, stack_a);
	apply_operation((char**)operations, debug, &stack_a, &stack_b);
	resolution(stack_a, stack_b);
	quit(stack_a, stack_b, operations);
	return (EXIT_SUCCESS);
}