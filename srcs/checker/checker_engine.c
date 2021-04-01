/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_engine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:16:15 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/01 15:24:42 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			quit(t_system *sys, int exit_nb)
{
	if (sys->s_a != NULL)
		ft_list_clear(&sys->s_a, free);
	if (sys->s_b != NULL)
		ft_list_clear(&sys->s_b, free);
	if (sys->ops != NULL)
		ft_list_clear(&sys->ops, free);
	free(sys);
	exit(exit_nb);
}

t_bool			resolution(t_list_node *s_a, t_list_node *s_b)
{
	t_list_node	*tmp;

	tmp = s_a;
	if (s_b != NULL && ft_list_size(s_b) != 0)
	{
		ft_putstr(FT_BOLD_RED"KO\n"FT_BASIC);
		return (false);
	}
	while (s_a->next != NULL)
	{
		if (((t_node*)s_a->data)->value >=
									((t_node*)s_a->next->data)->value)
		{
			ft_putstr(FT_BOLD_RED"KO\n"FT_BASIC);
			s_a = tmp;
			return (false);
		}
		s_a = s_a->next;
	}
	ft_putstr(FT_BOLD_GREEN"OK\n"FT_BASIC);
	s_a = tmp;
	return (true);
}
