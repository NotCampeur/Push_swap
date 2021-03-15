/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_engine.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:14:05 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/15 15:40:13 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_ENGINE_H
# define CHECKER_ENGINE_H

/*
** Will exit properly by freeing what needs to be.
*/
void		quit(t_list_node *stack_a, t_list_node *stack_b, void **ops);

/*
** Check is the stack A is sort and if the stack B is empty.
*/
t_bool	resolution(t_list_node *stack_a, t_list_node *stack_b);

/*
** Read STDIN until a \n is catch
*/
void		**get_instructions(void);

/*
** Will split argv into a t_liat_node *.
*/
t_list_node		*init_stack(char **args);

/*
** Check if the program can properly work with the given params
*/
int				parse_args(int argc, char *argv[], t_bool *debug);

#endif