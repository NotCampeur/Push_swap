/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:40:31 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/01 12:07:45 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char *argv[])
{
	t_system	*sys;

	sys = system_init();
	if (parse_args(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	sys->s_a = init_stack(argc - 1, argv + 1);
	if (sys->s_a == NULL)
		return (EXIT_FAILURE);
	sys->s_b = NULL;
	gen_instructions(sys);
	send_instructions(sys->ops);
	quit(sys);
	return (EXIT_SUCCESS);
}
