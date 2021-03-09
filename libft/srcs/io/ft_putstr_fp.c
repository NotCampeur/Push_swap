/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:58:50 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/10/23 13:29:34 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	file_overwrite(char *path)
{
	int	fd;

	fd = -1;
	if (ft_is_valid_file_path(path))
		fd = open(path, O_WRONLY | O_TRUNC);
	return (fd);
}

static int	file_append(char *path)
{
	int	fd;

	fd = -1;
	if (ft_is_valid_file_path(path))
		fd = open(path, O_WRONLY | O_APPEND);
	return (fd);
}

static int	file_create(char *path)
{
	int	fd;

	fd = -1;
	if (ft_is_valid_file_path(path) == false)
		fd = open(path, O_WRONLY | O_APPEND | O_CREAT, 00700);
	return (fd);
}

/*
**	Printing a string in a file. The actual file
**	is defined with a path rather than a file descriptor.
*/

void		ft_putstr_fp(char *path, char *str, char *mode)
{
	int	fd;

	fd = -1;
	if (path == NULL || str == NULL || mode == NULL)
		return ((void)ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG));
	if (ft_strcmp(mode, "OVERWRITE"))
		fd = file_overwrite(path);
	else if (ft_strcmp(mode, "APPEND"))
		fd = file_append(path);
	else if (ft_strcmp(mode, "CREATE"))
		fd = file_create(path);
	else
		return ((void)ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG));
	if (fd == -1)
		return ((void)ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_OPN));
	ft_putstr_fd(fd, str);
	close(fd);
}
