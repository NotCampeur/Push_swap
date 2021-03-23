/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_peculiar_cases.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:54:36 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/23 11:03:17 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PECULIAR_CASES_H
# define PUSH_SWAP_PECULIAR_CASES_H

/*
** Return true and send ra instructions if the stack
** is already sort in descending order
*/
t_bool	is_in_descending_order(t_list_node *stack_a);

/*
** Return true if the stack
** is already sort in crescent order
*/
t_bool	is_in_crescent_order(t_list_node *stack_a);

/*
** Check if the stack is in some order bY calling
** "is_in_crescent_order" and "is_in_descending_order"
*/
t_bool	is_in_following_order(t_list_node *stack_a, void ***operations);

#endif