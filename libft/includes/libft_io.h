/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_io.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:15:30 by ldutriez          #+#    #+#             */
/*   Updated: 2020/10/23 15:03:06 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_IO_H
# define LIBFT_IO_H

void			ft_putchar(char c);
void			ft_putchar_fd(int fd, char c);
void			ft_putchar_fp(char *path, char c, char *mode);
void			ft_putstr(char *str);
void			ft_putstr_fd(int fd, char *str);
void			ft_putstr_fp(char *path, char *str, char *mode);
void			ft_putnbr(int nb);
void			ft_putnbr_fd(int fd, int nb);
void			ft_putnbr_fp(char *path, int nb, char *mode);
void			ft_print_str_tab(char *name, char **tab);
void			ft_print_str_tab_fd(int fd, char *name, char **tab);
void			ft_print_str_tab_fp(char *path,
				char *name, char **tab, char *mode);
void			ft_print_int_tab(char *name, int *tab, size_t len);
void			ft_print_int_tab_fd(int fd,
				char *name, int *tab, size_t len);

#endif
