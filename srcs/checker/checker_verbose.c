/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_verbose.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:31:11 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/15 14:47:05 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	start_debug(void **operations, t_list_node *stack_a)
{
	ft_putstr_fp("log.log", "The start stack\n", "OVERWRITE");
	ft_list_putstr_fp("log.log", "STACK A", stack_a, "APPEND");
	ft_putstr_tab_fp("log.log", "Ops sent", (char **)operations, "APPEND");
	ft_putstr_fp("log.log", "Applying operations\n", "APPEND");
}
