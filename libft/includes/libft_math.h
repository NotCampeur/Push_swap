/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_math.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:11:40 by ldutriez          #+#    #+#             */
/*   Updated: 2020/10/21 17:45:56 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MATH_H
# define LIBFT_MATH_H

size_t			ft_nbr_len(int nbr);
float			ft_float_roof(float value);
float			ft_float_floor(float value);
float			ft_float_round(float value);
int				ft_int_abs(int value);
float			ft_float_abs(float value);
void			ft_swap_int(int *x, int *y);
void			ft_swap_char(char *x, char *y);

#endif
