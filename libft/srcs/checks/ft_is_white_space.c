/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_white_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoudsi <ncoudsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:14:14 by ldutriez          #+#    #+#             */
/*   Updated: 2020/10/14 15:37:27 by ncoudsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Cheking if a character is a white space.
*/

t_bool	ft_is_white_space(char c)
{
	if (c == '\t' || c == '\v' || c == '\n' || c == '\r' ||
	c == '\f' || c == ' ')
		return (true);
	return (false);
}
