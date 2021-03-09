/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_lower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoudsi <ncoudsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:27:37 by ldutriez          #+#    #+#             */
/*   Updated: 2020/10/14 15:35:56 by ncoudsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Checking if a character is a lower case alphabetic.
*/

t_bool	ft_is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (true);
	return (false);
}
