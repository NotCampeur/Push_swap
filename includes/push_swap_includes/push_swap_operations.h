/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:44:29 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/22 13:46:19 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_OPERATIONS_H
# define PUSH_SWAP_OPERATIONS_H

/*
** Swap the first 2 elements at the top of stack A.
** Do nothing if there is only one or no elements).
*/
void	swap_a(t_list_node **stack_a);

/*
** Swap the first 2 elements at the top of stack B.
** Do nothing if there is only one or no elements).
*/
void	swap_b(t_list_node **stack_b);

/*
** Take the first element at the top of B and put it
** at the top of A. Do nothing if B is empty.
*/
void	push_a(t_list_node **stack_a, t_list_node **stack_b);

/*
** Take the first element at the top of A and put it
** at the top of B. Do nothing if A is empty.
*/
void	push_b(t_list_node **stack_a, t_list_node **stack_b);

/*
** Shift up all elements of stack A by 1.
** The first element becomes the last one.
*/
void	rotate_a(t_list_node **stack_a);

/*
** Shift up all elements of stack B by 1.
** The first element becomes the last one.
*/
void	rotate_b(t_list_node **stack_b);

/*
** Shift down all elements of stack A by 1.
** The last element becomes the first one.
*/
void	reverse_rotate_a(t_list_node **stack_a);

/*
** Shift down all elements of stack B by 1.
** The last element becomes the first one.
*/
void	reverse_rotate_b(t_list_node **stack_b);

#endif
