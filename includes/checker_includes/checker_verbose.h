/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_verbose.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:34:19 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/23 13:05:34 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_VERBOSE_H
# define CHECKER_VERBOSE_H

/*
** Will print the first debug message and overwrite the log_checker.log file
*/
void	start_debug(void **operations, t_list_node	*stack_a);

#endif
