/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_load.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:28:19 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/26 10:31:20 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_LOAD_H
# define PUSH_SWAP_LOAD_H

/*
** Will convert argv into a t_list_node *. by creating nodes and indexing them.
*/
t_list_node		*init_stack(int argc, char **args);

/*
** Check if the program can properly work with the given params
*/
int				parse_args(int argc, char *argv[]);

#endif
