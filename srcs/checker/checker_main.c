/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:51:21 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/24 18:13:10 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int				main(int argc, char *argv[])
{
	t_list_node		*stack_a;
	t_list_node		*stack_b;
	void			**operations;
	t_bool			debug;
	t_visualizer	*visualizer;

	debug = false;
	visualizer = NULL; 
	if (parse_args(argc, argv, &debug) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	stack_a = init_stack(argv + debug);
	stack_b = NULL;
	if (debug == true)
		visualizer = start_visualizer(stack_a);
	operations = NULL;
	error_quit(visualizer, stack_a, stack_b, operations);
	operations = get_instructions();
	if (operations == NULL)
	{
		ft_putstr_fd(2, FT_BOLD_RED"Error\nWrong operation\n"FT_BASIC);
		error_quit(visualizer, stack_a, stack_b, operations);
	}
	apply_operation((char**)operations, &stack_a, &stack_b, debug, visualizer);
	resolution(stack_a, stack_b);
	quit(visualizer, stack_a, stack_b, operations);
	return (EXIT_SUCCESS);
}
