/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:48:05 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/10/23 08:44:27 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Printing a character.
*/

void	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		ft_print_error(__PRETTY_FUNCTION__, __LINE__, "malfunction of write");
}
