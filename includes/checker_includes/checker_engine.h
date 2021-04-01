/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_engine.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:14:05 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/01 15:25:16 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_ENGINE_H
# define CHECKER_ENGINE_H

/*
** Will exit properly by freeing what needs to be. return code : exit_nb
*/
void	quit(t_system *sys, int exit_nb);

/*
** Check is the stack A is sort and if the stack B is empty.
*/
t_bool	resolution(t_list_node *s_a, t_list_node *s_b);

/*
** Will process the various operations on stacks.
*/
void	apply_operation(t_list_node *op, t_list_node **s_a, t_list_node **s_b);

#endif
