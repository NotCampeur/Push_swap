/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:51:21 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/07 12:02:13 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int				main(int argc, char *argv[])
{
	t_system	*sys;

	sys = system_init();
	if (parse_args(argc, argv) == EXIT_FAILURE)
		quit(sys, EXIT_FAILURE);
	sys->s_a = init_stack(argc - 1, argv + 1);
	if (sys->s_a == NULL)
		quit(sys, EXIT_FAILURE);
	sys->s_b = NULL;
	sys->ops = get_instructions();
	if (sys->ops != NULL && ft_strcmp(sys->ops->data, "Error") == true)
	{
		ft_putstr_fd(2, FT_BOLD_RED"Error\n"FT_BASIC);
		quit(sys, EXIT_FAILURE);
	}
	apply_operation(sys->ops, &sys->s_a, &sys->s_b);
	resolution(sys->s_a, sys->s_b);
	quit(sys, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
