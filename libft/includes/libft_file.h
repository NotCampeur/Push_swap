/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_file.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:07:15 by ldutriez          #+#    #+#             */
/*   Updated: 2020/10/20 15:30:14 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_FILE_H
# define LIBFT_FILE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define IS_NOT_A_LINE 2
# define IS_A_LINE 1
# define IS_END_OF_FILE 0
# define IS_AN_ERROR -1

int				ft_get_next_line(int fd, char **line);
char			**ft_get_file(char *path);

#endif
