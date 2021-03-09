/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 08:21:26 by ldutriez          #+#    #+#             */
/*   Updated: 2020/10/21 17:36:26 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LIST_H
# define LIBFT_LIST_H

/*
**	The t_list_node structure is designed to put any data in it as
**	a void pointer.
**	The second variable is a pointer to the next t_list_node,
**	in a chain of linked lists.
*/

typedef struct	s_list_node
{
	void				*data;
	struct s_list_node	*next;
}				t_list_node;

t_list_node		*ft_malloc_node(void *data);
void			ft_list_add_back(t_list_node **list, t_list_node *node);
void			ft_list_add_front(t_list_node **list, t_list_node *node);
void			ft_list_clear(t_list_node **list, void (*destructor)(void*));
void			ft_list_iter(t_list_node *list, void (*function)(void*));
t_list_node		*ft_list_map(t_list_node *list, void *(*function)(void*),
												void (*destructor)(void*));
int				ft_list_size(t_list_node *list);
void			ft_list_remove_node(t_list_node **list, size_t node_index,
												void (*destructor)(void*));

#endif
