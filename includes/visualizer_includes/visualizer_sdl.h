/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer_sdl.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 08:37:27 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/25 18:02:42 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_SDL_H
# define VISUALIZER_SDL_H

/*
**	Return an SDL_Color based on the parameters.
*/
SDL_Color	color_init(Uint8 r, Uint8 g, Uint8 b);

/*
**	Return an SDL_Point based on the parameters.
*/
SDL_Point	point_init(int x, int y);

/*
**	Return an SDL_Rect based on the parameters.
*/
SDL_Rect	rect_init(int x, int y, int w, int h);

/*
**	Draw "to_print" according to the "visualiser.font" at a "pos" in a "color"
*/
void		draw_text(t_visualizer *visualizer, char *to_print,
										SDL_Rect pos, SDL_Color color);

/*
**	Create a renderable texture based on a surface
*/
SDL_Texture	**create_texture(t_visualizer *visualizer, SDL_Surface *surface);

/*
**	Apply a texture to the current "visualizer.render"
**	which will be draw by the next "SDL_RenderPresent"
*/
void		render_texture(t_visualizer *visualizer,
							SDL_Texture **tex, SDL_Rect *src, SDL_Rect *dst);

void		sdl_render_fill_rect(SDL_Renderer *renderer, SDL_Rect rect,
															SDL_Color color);

void		sdl_render_clear(SDL_Renderer *renderer, SDL_Color color);

#endif
