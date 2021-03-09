/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:03:27 by ldutriez          #+#    #+#             */
/*   Updated: 2020/10/20 11:39:35 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbr_len(int nbr)
{
	size_t result;

	result = 1;
	if (nbr < 0)
		nbr *= -1;
	while (nbr >= 10)
	{
		nbr /= 10;
		result++;
	}
	return (result);
}
