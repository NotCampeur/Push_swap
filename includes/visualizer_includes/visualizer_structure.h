/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer_structure.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:23:18 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/01 15:31:06 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_STRUCTURE_H
# define VISUALIZER_STRUCTURE_H

/*
** Structure used to store SDL and draw relative data
**
** *win will store the pointer to the window
** *render will store the pointer to the current renderer
** *font will store the pointer to the font style
** stack_m_s will store the number of arguments which compose the stack
** b_wd will store the width of the bars depending on stack_m_s and S_WD
** s_wd will store the width of the screen depending on stack_m_s and S_WD
** run will store the keypressed to know if he should run
*/
typedef struct			s_visualizer
{
	SDL_Window			*win;
	SDL_Renderer		*render;
	TTF_Font			*font;
	int					stack_m_s;
	int					b_wd;
	int					s_wd;
	t_bool				run;
}						t_visualizer;

#endif
