/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_engine.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:31:14 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/23 12:53:31 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_ENGINE_H
# define PUSH_SWAP_ENGINE_H

/*
** Check if the stack is sort
*/
t_bool	is_sort(t_list_node *stack_a, t_list_node *stack_b);

/*
** Send the instructions in STDIN to sort the stack
*/
void	**gen_instructions(t_list_node	**stack_a, t_list_node	**stack_b);

/*
** Send the instructions in STDIN to sort the stack
*/
void	send_instructions(void **operation);

/*
** Will exit properly by freeing what needs to be.
*/
void	quit(t_list_node *stack_a, t_list_node *stack_b, void **ops);

#endif
