/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_structure.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 07:38:41 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/01 14:44:25 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_STRUCTURE_H
# define CHECKER_STRUCTURE_H

typedef struct	s_node
{
	int			value;
	int			index;
}				t_node;

typedef struct	s_system
{
	t_list_node	*s_a;
	t_list_node	*s_b;
	t_list_node	*ops;
}				t_system;

#endif
