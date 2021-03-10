/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:44:29 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/10 11:14:53 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_OPERATIONS_H
# define CHECKER_OPERATIONS_H

/*
** Swap the first 2 elements at the top of stack A.
** Do nothing if there is only one or no elements).
*/
void    swap_a(void **stack_a);

/*
** Swap the first 2 elements at the top of stack B.
** Do nothing if there is only one or no elements).
*/
void    swap_b(void **stack_b);

/*
** Call swap_a and swap_b at the same time.
*/
void    swap_swap(void **stack_a, void **stack_b);

/*
** Take the first element at the top of B and put it
** at the top of A. Do nothing if B is empty.
*/
void    push_a(void **stack_a);

/*
** Take the first element at the top of A and put it
** at the top of B. Do nothing if A is empty.
*/
void    push_b(void **stack_b);

/*
** Shift up all elements of stack A by 1.
** The first element becomes the last one.
*/
void    rotate_a(void **stack_a);

/*
** Shift up all elements of stack B by 1.
** The first element becomes the last one.
*/
void    rotate_b(void **stack_b);

/*
** Call rotate_a and rotate_b at the same time.
*/
void    rotate_rotate(void **stack_a, void **stack_b);

/*
** Shift down all elements of stack A by 1.
** The last element becomes the first one.
*/
void    reverse_rotate_a(void **stack_a);

/*
** Shift down all elements of stack B by 1.
** The last element becomes the first one.
*/
void    reverse_rotate_b(void **stack_b);

/*
** Call revserse_rotate_a and reverse_rotate_b at the same time.
*/
void    reverse_rotate_rotate(void **stack_a, void **stack_b);

/*
** Will process the various operations on stacks.
*/
void	apply_operation(char *operation);

#endif