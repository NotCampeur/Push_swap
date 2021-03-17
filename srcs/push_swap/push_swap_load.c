/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_load.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:49:33 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/17 15:29:18 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_node		*init_stack(char **args)
{
	int			index;
	char		**splitted_args;
	int			args_nb;
	t_list_node	*result;

	index = 0;
	splitted_args = ft_split(args[1], ' ');
	args_nb = ft_tab_len((void**)splitted_args);
	result = NULL;
	while (index < args_nb)
	{
		ft_list_add_back(&result, ft_malloc_node(splitted_args[index]));
		index++;
	}
	free(splitted_args);
	return (result);
}
