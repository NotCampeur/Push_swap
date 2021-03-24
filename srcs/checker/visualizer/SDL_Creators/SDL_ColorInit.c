/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL_ColorInit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 08:27:24 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/24 08:29:44 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

SDL_Color	color_init(Uint8 r, Uint8 g, Uint8 b)
{
	SDL_Color	result;

	result.r = r;
	result.g = g;
	result.b = b;
	return result;
}
