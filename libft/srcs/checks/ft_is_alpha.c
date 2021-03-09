/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoudsi <ncoudsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:21:16 by ldutriez          #+#    #+#             */
/*   Updated: 2020/10/14 15:35:19 by ncoudsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Checking if a character is alphabetic, upper or lower case.
*/

t_bool	ft_is_alpha(char c)
{
	if (ft_is_upper(c) == true || ft_is_lower(c) == true)
		return (true);
	return (false);
}
