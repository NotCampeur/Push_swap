/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_engine.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:14:05 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/24 18:07:42 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_ENGINE_H
# define CHECKER_ENGINE_H

/*
** Will exit properly by freeing what needs to be.
*/
void	quit(t_visualizer *visualizer,
					t_list_node *stack_a, t_list_node *stack_b, void **ops);

/*
** Will exit properly by freeing what needs to be.
*/
void	error_quit(t_visualizer *visualizer,
					t_list_node *stack_a, t_list_node *stack_b, void **ops);

/*
** Check is the stack A is sort and if the stack B is empty.
*/
t_bool	resolution(t_list_node *stack_a, t_list_node *stack_b);

#endif
