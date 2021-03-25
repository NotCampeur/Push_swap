/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer_engine.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:25:40 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/25 18:02:28 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_ENGINE_H
# define VISUALIZER_ENGINE_H

/*
** Will exit properly by freeing what needs to be. return code : 0
*/
void	visualizer_quit(t_visualizer *visualizer,
					t_list_node *stack_a, t_list_node *stack_b, void **ops);

/*
** Will exit properly by freeing what needs to be. return code : 1
*/
void	visualizer_error_quit(t_visualizer *visualizer,
					t_list_node *stack_a, t_list_node *stack_b, void **ops);

/*
** Will, using SDL draw the two stacks
*/
void	draw_stacks(t_visualizer *visualizer,
								t_list_node **stack_a, t_list_node **stack_b);

/*
** Will process and draw the various operations on stacks.
*/
void	visualize_operation(char **op, t_list_node **stack_a,
				t_list_node **stack_b, t_visualizer *visualizer);

#endif
