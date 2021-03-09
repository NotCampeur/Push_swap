/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:00:18 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/10/23 13:29:48 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Printing an integer value in a file.
*/

void	ft_putnbr_fd(int fd, int nbr)
{
	if (fd == -1)
		return ((void)ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG));
	if (nbr < 0)
	{
		ft_putchar_fd(fd, '-');
		nbr = nbr * -1;
	}
	if (nbr >= 10)
		ft_putnbr_fd(fd, nbr / 10);
	ft_putchar_fd(fd, (nbr % 10) + '0');
}
