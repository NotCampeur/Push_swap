/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_tab_fp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:49:30 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/10/23 13:30:16 by ldutriez         ###   ########.fr       */
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
**	Printing a 2 dimensions characters array in a file. The actual file is
**	defined with a path rathe than a file descriptor. Note that user can
**	choose 3 modes to open the file (OVERWRITE, APPEND, CREATE). User also can
**	define a name for the array. Otherwise, set NULL as the second parameter.
*/

void		ft_print_str_tab_fp(char *path,
			char *name, char **tab, char *mode)
{
	int	fd;

	fd = -1;
	if (path == NULL || mode == NULL)
		return ((void)ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG));
	if (ft_strcmp(mode, "OVERWRITE") == true)
		fd = file_overwrite(path);
	else if (ft_strcmp(mode, "APPEND") == true)
		fd = file_append(path);
	else if (ft_strcmp(mode, "CREATE") == true)
		fd = file_create(path);
	else
		return ((void)ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG));
	if (fd == -1)
		return ((void)ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_OPN));
	ft_print_str_tab_fd(fd, name, tab);
	close(fd);
}
