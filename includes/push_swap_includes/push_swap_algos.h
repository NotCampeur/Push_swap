/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algos.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:00:39 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/06 14:30:03 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_ALGOS_H
# define PUSH_SWAP_ALGOS_H

/*
** Will order the stack according to the position of the minimal value
*/
void		order_stack(t_list_node **s_a, t_list_node	**ops);

/*
** Will check the string value of operations and call functions accordingly.
*/
void		execute_ops(t_list_node **s_a, t_list_node **s_b, t_list_node *ops);

/*
** Will compute the moves to place well the actual value of the stack.
** and return the operations array used.
*/
t_list_node	*moves_to_place(t_list_node **s_a, t_list_node **s_b
							, int *moves_needed, int index);

/*
** Will process a king of backtracking.
** Checking the value which need the less move to be well placed.
*/
void		move_the_best_value(t_system *sys);

/*
** Will move every int with the tag set to false.
*/
void		push_untagged(t_list_node **s_a, t_list_node **s_b
											, t_list_node	**ops);

/*
** Will just iter through the stack and push the next smallest int.
*/
void		rev_push_sort(t_system *sys);

#endif
