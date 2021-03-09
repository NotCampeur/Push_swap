/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:17:20 by ldutriez          #+#    #+#             */
/*   Updated: 2020/10/23 15:08:56 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_params(int ac, char *av[])
{
	int	i;

	i = 0;
	while (i < ac)
	{
		ft_putnbr(i);
		ft_putstr(" : ");
		ft_putstr(av[i]);
		ft_putstr("\n");
		i++;
	}
}

int			main(int argc, char *argv[])
{
	print_params(argc, argv);
	return (0);
}
