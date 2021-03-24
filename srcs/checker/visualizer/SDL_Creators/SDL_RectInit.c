/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL_RectInit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 08:29:52 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/24 08:30:14 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

SDL_Rect	rect_init(int x, int y, int w, int h)
{
	SDL_Rect	result;

	result.x = x;
	result.y = y;
	result.w = w;
	result.h = h;
	return result;
}
