/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL_PointInit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 08:28:50 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/24 08:29:02 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

SDL_Point	point_init(int x, int y)
{
	SDL_Point	result;

	result.x = x;
	result.y = y;
	return result;
}
