/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:53:02 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/10/23 13:22:57 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Printing a character in a file.
*/

void	ft_putchar_fd(int fd, char c)
{
	if (fd == -1)
		ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG);
	if (write(fd, &c, 1) == -1)
		ft_print_error(__PRETTY_FUNCTION__, __LINE__, "malfunction of write");
}
