/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:01:40 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/10/23 13:30:00 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Printing a string in a file.
*/

void	ft_putstr_fd(int fd, char *str)
{
	if (str == NULL || fd == -1)
		return ((void)ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG));
	if (write(fd, str, ft_strlen(str)) == -1)
		ft_print_error(__PRETTY_FUNCTION__, __LINE__, "malfunction of write");
}
