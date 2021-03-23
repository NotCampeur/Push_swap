/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:40:31 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/23 12:52:30 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char *argv[])
{
	t_list_node	*stack_a;
	t_list_node	*stack_b;
	void		**operations;

	if (parse_args(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	stack_a = init_stack(argv);
	stack_b = NULL;
	operations = gen_instructions(&stack_a, &stack_b);
	send_instructions(operations);
	quit(stack_a, stack_b, operations);
	return (EXIT_SUCCESS);
}
