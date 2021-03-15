/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_putstr_fp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:08:49 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/15 12:42:42 by ldutriez         ###   ########.fr       */
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
**	Printing a linked list data, casted in str in a file. The actual file is
**	defined with a path rather than a file descriptor. Note that user can
**	choose 3 modes to open the file (OVERWRITE, APPEND, CREATE). User also can
**	define a name for the array. Otherwise, set NULL as the second parameter.
*/

void		ft_list_putstr_fp(char *path,
			char *name, t_list_node *list, char *mode)
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
	ft_list_putstr_fd(fd, name, list);
	close(fd);
}
