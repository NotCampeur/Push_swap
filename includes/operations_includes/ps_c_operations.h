/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_c_operations.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:37:30 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/25 17:20:24 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_C_OPERATIONS_H
# define PS_C_OPERATIONS_H

# include "libft.h"

/*
** Swap the first 2 elements at the top of the stack.
** Do nothing if there is only one or no elements).
*/
void	swap_stack(t_list_node **stack);

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
