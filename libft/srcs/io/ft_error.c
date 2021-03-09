/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 15:31:41 by ldutriez          #+#    #+#             */
/*   Updated: 2020/10/23 13:19:52 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Will print a colored message according where the function have been called
**	and why, glad to the __PRETTY_NAME__ and __LINE__ attributes.
**	The return of this function is always NULL which grant you the possibility
**	to return the function directly in most of the case instead of
**	print the error and then return.
*/

void	*ft_print_error(const char *function_name, int line, char *reason)
{
	ft_putstr(FT_RED"Exiting ");
	ft_putstr(FT_BOLD_RED);
	ft_putstr((char*)function_name);
	ft_putstr(FT_RED" at line ");
	ft_putstr(FT_BOLD_RED);
	ft_putnbr(line);
	if (reason != NULL)
	{
		ft_putstr(FT_RED" due to ");
		ft_putstr(FT_BOLD_RED);
		ft_putstr(reason);
	}
	ft_putstr("."FT_BASIC"\n");
	return (NULL);
}
