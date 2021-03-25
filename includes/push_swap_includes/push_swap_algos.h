/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algos.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:00:39 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/25 18:01:28 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_ALGOS_H
# define PUSH_SWAP_ALGOS_H

/*
** Will push src to dst until src is empty.
*/
void	empty_stack(t_list_node **src, t_list_node **dst, void ***operations);

/*
** Will catch the next smallest int and push it at top of stack B.
*/
void	push_smallest_a_on_b(t_list_node **stack_a, t_list_node **stack_b,
															void ***operations);

/*
** Will just iter through the stack and push the next smallest int.
*/
void	rev_push_sort(t_list_node **stack_a, t_list_node **stack_b,
															void ***operations);

#endif
