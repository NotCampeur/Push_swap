/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:34:11 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/10/23 13:22:57 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Opening a file and getting its datas line by line. Storing it in a char **
**	and returning it. If the path to the file is incorrect, returning NULL.
*/

char	**ft_get_file(char *path)
{
	char	**result;
	int		fd;
	char	*line;

	result = NULL;
	line = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 3)
	{
		return (ft_print_error(__PRETTY_FUNCTION__, __LINE__,
								FT_E_ARG));
	}
	while (ft_get_next_line(fd, &line) > 0)
	{
		ft_add_to_tab((void *)line, (void ***)&result);
	}
	ft_add_to_tab((void *)line, (void ***)&result);
	close(fd);
	return (result);
}
