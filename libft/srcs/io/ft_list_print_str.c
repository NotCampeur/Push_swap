/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_print_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:06:07 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/11 14:14:00 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putstr_void(void *str)
{
	ft_putstr((char*)str);
	ft_putchar('\n');
}

void	ft_list_print_str(t_list_node *list)
{
	ft_list_iter(list, ft_putstr_void);
}