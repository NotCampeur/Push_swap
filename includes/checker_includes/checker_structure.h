/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_structure.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 07:38:41 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/24 13:46:39 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_STRUCTURE_H
# define CHECKER_STRUCTURE_H

typedef struct			s_visualizer
{
	SDL_Window			*win;
	SDL_Renderer		*render;
	TTF_Font			*font;
	int					stack_max_size;
}						t_visualizer;

typedef struct	s_node
{
	int			value;
	int			index;
}				t_node;

#endif
