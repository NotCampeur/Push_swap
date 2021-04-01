/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_structure.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:55:00 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/01 10:28:33 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_STRUCTURE_H
# define PUSH_SWAP_STRUCTURE_H

typedef struct	s_node
{
	int			value;
	int			index;
	t_bool		tag;
}				t_node;

typedef struct	s_system
{
	t_list_node	*s_a;
	t_list_node	*s_b;
	t_list_node	*ops;
}				t_system;

#endif
