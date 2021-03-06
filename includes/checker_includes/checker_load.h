/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_load.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:15:07 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/01 14:57:56 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_LOAD_H
# define CHECKER_LOAD_H

/*
** Read STDIN until a \n is catch
*/
t_list_node		*get_instructions(void);

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

/*
** Initialize the system structure for futur uses.
*/
t_system		*system_init(void);

#endif
