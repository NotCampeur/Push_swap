/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_render_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:39:55 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/25 17:51:02 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	draw_text(t_visualizer *visualizer, char *to_print,
										SDL_Rect pos, SDL_Color color)
{
	SDL_Texture	**texture;

	texture = create_texture(visualizer,
					TTF_RenderText_Solid(visualizer->font, to_print, color));
	render_texture(visualizer, texture, NULL, &pos);
	SDL_DestroyTexture(*texture);
	free(texture);
}

void	sdl_render_clear(SDL_Renderer *renderer, SDL_Color color)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderClear(renderer);
}

void	sdl_render_fill_rect(SDL_Renderer *renderer, SDL_Rect rect,
																SDL_Color color)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(renderer, &rect);
}
