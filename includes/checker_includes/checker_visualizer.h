/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_visualizer.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:34:19 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/24 18:16:39 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_VERBOSE_H
# define CHECKER_VERBOSE_H

# define SCREEN_WIDTH 2000
# define SCREEN_HEIGHT 600

/*
** Will, using SDL draw the two stacks
*/
void			draw_stacks(t_visualizer *visualizer,
								t_list_node **stack_a, t_list_node **stack_b);

/*
** Will init the SDL and open a window
*/
t_visualizer	*start_visualizer(t_list_node *stack_a);

/*
** Will destroy the SDL's components
*/
void	destroy_visualizer(t_visualizer *visualizer);

#endif
