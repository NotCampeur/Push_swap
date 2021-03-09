/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:54:08 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/10/23 13:24:44 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The 3 static functions bellow open the file with specific mode.
*/

static int	file_overwrite(char *path)
{
	int	fd;

	fd = open(path, O_WRONLY | O_TRUNC);
	return (fd);
}

static int	file_append(char *path)
{
	int	fd;

	fd = open(path, O_WRONLY | O_APPEND);
	return (fd);
}

static	int	file_create(char *path)
{
	int	fd;

	fd = open(path, O_WRONLY | O_APPEND | O_CREAT, 00700);
	return (fd);
}

/*
**	Printing an integer value in a file. The actual file
**	is defined with a path rather than a file descriptor.
*/

void		ft_putnbr_fp(char *path, int nb, char *mode)
{
	int	fd;

	fd = -1;
	if (path == NULL || mode == NULL)
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
	ft_putnbr_fd(fd, nb);
	close(fd);
}
