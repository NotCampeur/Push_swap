/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_array.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:17:39 by ldutriez          #+#    #+#             */
/*   Updated: 2020/10/20 15:30:56 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_ARRAY_H
# define LIBFT_ARRAY_H

void			**ft_tab_new(int size);
size_t			ft_tab_len(void	**tab);
void			ft_free_tab(void **tab);
void			ft_tab_cpy(void **dst, void **src);
void			ft_add_to_tab(void *to_add, void ***tab);

#endif
