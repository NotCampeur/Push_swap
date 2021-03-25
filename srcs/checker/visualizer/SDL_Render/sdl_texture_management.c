/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_texture_management.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 08:34:51 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/25 17:51:52 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void		render_texture(t_visualizer *visualizer,
							SDL_Texture **tex, SDL_Rect *src, SDL_Rect *dst)
{
	SDL_RenderCopy(visualizer->render, *tex, src, dst);
}

SDL_Texture	**create_texture(t_visualizer *visualizer, SDL_Surface *surface)
{
	SDL_Texture	**result;

	result = (SDL_Texture**)malloc(sizeof(SDL_Texture*));
	*result = SDL_CreateTextureFromSurface(visualizer->render, surface);
	SDL_FreeSurface(surface);
	return (result);
}
