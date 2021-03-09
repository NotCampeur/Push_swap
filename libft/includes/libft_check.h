/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_check.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:12:54 by ldutriez          #+#    #+#             */
/*   Updated: 2020/10/21 13:34:39 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_CHECK_H
# define LIBFT_CHECK_H

t_bool			ft_is_char_in_str(char to_find, char *str);
t_bool			ft_is_only_digits(char *str);
t_bool			ft_is_digit(char c);
t_bool			ft_strcmp(char *src, char *target);
t_bool			ft_is_charset_in_str(char *str, char *to_find);
t_bool			ft_is_white_space(char c);
t_bool			ft_is_upper(char c);
t_bool			ft_is_lower(char c);
t_bool			ft_is_alpha(char c);
t_bool			ft_is_alpha_num(char c);
t_bool			ft_is_valid_file_path(char *path);

#endif
