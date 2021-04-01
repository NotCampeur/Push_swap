/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:51:21 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/01 15:33:27 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int				main(int argc, char *argv[])
{

	t_system		*sys;
	t_visualizer	*visualizer;

	sys = system_init();
	visualizer = NULL;
	if (parse_args(argc, argv) == EXIT_FAILURE)
		visualizer_quit(visualizer, sys, EXIT_FAILURE);
	sys->s_a = init_stack(argc - 1, argv + 1);
	if (sys->s_a == NULL)
		return (EXIT_FAILURE);
	sys->s_b = NULL;
	visualizer = start_visualizer(sys->s_a);
	sys->ops = get_instructions();
	if (ft_strcmp(sys->ops->data, "Error") == true)
	{
		ft_putstr_fd(2, FT_BOLD_RED"Error\n"FT_BASIC);
		visualizer_quit(visualizer, sys, EXIT_FAILURE);
	}
	visualize_operation(sys->ops, &sys->s_a, &sys->s_b, visualizer);
	resolution(sys->s_a, sys->s_b);
	visualizer_quit(visualizer, sys, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
