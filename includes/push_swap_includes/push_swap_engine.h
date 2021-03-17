/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_engine.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:31:14 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/17 12:41:39 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_ENGINE_H
# define PUSH_SWAP_ENGINE_H

/*
** Send the instructions in STDIN to sort the stack
*/
void	**gen_instructions(t_list_node	*stack_a);

/*
** Send the instructions in STDIN to sort the stack
*/
void	send_instructions(void **operation);

/*
** Will exit properly by freeing what needs to be.
*/
void	quit(t_list_node *stack_a, t_list_node *stack_b, void **ops);

#endif
