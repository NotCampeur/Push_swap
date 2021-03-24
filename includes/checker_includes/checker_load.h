/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_load.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:15:07 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/24 11:24:06 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_LOAD_H
# define CHECKER_LOAD_H

/*
** Read STDIN until a \n is catch
*/
void			**get_instructions(void);

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
t_list_node		*init_stack(char **args);

#endif
