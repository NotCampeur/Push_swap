/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer_system.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:12:19 by ldutriez          #+#    #+#             */
/*   Updated: 2022/01/17 14:22:40 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_SYSTEM_H
# define VISUALIZER_SYSTEM_H

# define S_WD 1920
# define S_HT 600

/*
** Will create a t_visualizer and give a standard value to each variables
*/
t_visualizer	init_visualizer(void);

/*
** Will init the SDL and open a window
*/
t_visualizer	*start_visualizer(t_list_node *stack_a);

/*
** Will destroy the SDL's components
*/
void			destroy_visualizer(t_visualizer *visualizer);

#endif
