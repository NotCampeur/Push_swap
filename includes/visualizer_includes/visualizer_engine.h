/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer_engine.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:25:40 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/02 09:38:49 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_ENGINE_H
# define VISUALIZER_ENGINE_H

/*
** Will exit properly by freeing what needs to be. return code : exit_nb
*/
void	visualizer_quit(t_visualizer *vz, t_system *sys, int exit_nb);

/*
** Will, using SDL draw the two ss
*/
void	draw_ss(t_visualizer *vz, t_list_node **s_a, t_list_node **s_b);

/*
** Will process and draw the various operations on ss.
*/
void	visualize_operation(t_system *sys, t_visualizer *vz);

#endif
