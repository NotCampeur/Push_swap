/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:03:39 by ncoudsi           #+#    #+#             */
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

static int	file_create(char *path)
{
	int	fd;

	fd = open(path, O_WRONLY | O_APPEND | O_CREAT, 00700);
	return (fd);
}

/*
**	Printing a character in a file. The actual file is defined with
**	a path rathe than a file descriptor. Note that user can choose
**	3 modes to open the file (OVERWRITE, APPEND, CREATE). User also can
**	define a name for the array. Otherwise, set NULL as the second parameter.
*/

void		ft_putchar_fp(char *path, char c, char *mode)
{
	int	fd;

	fd = -1;
	if (path == NULL || mode == NULL || path == NULL)
	{
		ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG);
		return ;
	}
	if (ft_strcmp(mode, "OVERWRITE"))
		fd = file_overwrite(path);
	else if (ft_strcmp(mode, "APPEND"))
		fd = file_append(path);
	else if (ft_strcmp(mode, "CREATE"))
		fd = file_create(path);
	if (fd == -1)
	{
		ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_OPN);
		return ;
	}
	ft_putchar_fd(fd, c);
	close(fd);
}
