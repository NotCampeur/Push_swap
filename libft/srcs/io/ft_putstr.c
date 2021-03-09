/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:48:45 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/10/23 13:22:57 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Printing a string.
*/

void	ft_putstr(char *str)
{
	if (str == NULL)
	{
		ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG);
		return ;
	}
	if (write(1, str, ft_strlen(str)) == -1)
		ft_print_error(__PRETTY_FUNCTION__, __LINE__, "malfunction of write");
}
