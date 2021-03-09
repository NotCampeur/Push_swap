/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_upper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoudsi <ncoudsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:25:38 by ldutriez          #+#    #+#             */
/*   Updated: 2020/10/14 15:36:22 by ncoudsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Checking if a character is an upper case alphabetic.
*/

t_bool	ft_is_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (true);
	return (false);
}
