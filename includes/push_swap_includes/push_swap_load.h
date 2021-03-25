/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_load.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:28:19 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/25 14:01:55 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_LOAD_H
# define PUSH_SWAP_LOAD_H

/*
** Will index the arguments of the stack in crescent order.
*/
void			index_stack_nodes(t_node **nodes, int size);

/*
** Will malloc each node of the future linked list.
** And call the index_stack_nodes.
*/
t_node			**init_stack_nodes(char **splitted_args, int args_nb);

/*
** Will split argv into a t_liat_node *.
*/
t_list_node		*init_stack(int argc, char **args);

/*
** Check if the program can properly work with the given params
*/
int				parse_args(int argc, char *argv[]);

#endif
