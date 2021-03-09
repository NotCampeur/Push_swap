/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_string.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:10:21 by ldutriez          #+#    #+#             */
/*   Updated: 2020/10/20 15:39:56 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRING_H
# define LIBFT_STRING_H

char			*ft_strnew(size_t len);
char			*ft_strdup(char *src);
char			*ft_strduc(char c);
size_t			ft_strlen(char	*src);

/*
** DEPRECATED FUNCTION :
** size_t			ft_strlen_arg(char *str, char c);
*/

char			*ft_strcpy(char *src, char *dest);
char			*ft_strsub(char *src, size_t start, size_t len);
char			*ft_strjoin(char *str1, char *str2);
char			*ft_strstr(char *haystack, char *needle);
char			**ft_split(char *src, char sep);
void			ft_str_add_prefixe(char *prefixe, char **str);
void			ft_str_add_suffix(char **str, char *suffix);
int				ft_str_count_c(char *str, char c);
char			*ft_strnstr(char *haystack, char *needle, size_t len);
char			*ft_rm_charset(char *str, char *charset);

#endif
