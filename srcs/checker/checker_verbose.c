/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_verbose.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:31:11 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/23 13:04:34 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	start_debug(void **operations, t_list_node *stack_a)
{
	if (ft_is_valid_file_path("log_checker.log") == true)
		ft_putstr_fp("log_checker.log", "The start stack\n", "OVERWRITE");
	else
		ft_putstr_fp("log_checker.log", "The start stack\n", "CREATE");
	if (stack_a != NULL)
		ft_list_putstr_fp("log_checker.log", "STACK A", stack_a, "APPEND");
	else
		ft_putstr_fp("log_checker.log", "Stack A is empty\n", "APPEND");
	ft_putstr_tab_fp("log_checker.log", "Ops sent",
												(char **)operations, "APPEND");
	ft_putstr_fp("log_checker.log", "Applying operations\n", "APPEND");
}
