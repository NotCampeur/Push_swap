/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_add_suffix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:32:29 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/10/23 15:07:22 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Adding a suffix to a string. Free the old string, re-allocate the new one.
*/

void	ft_str_add_suffix(char **str, char *suffix)
{
	char	*tmp;

	if (suffix == NULL)
		return ((void)ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG));
	tmp = ft_strdup(*str);
	free(*str);
	*str = ft_strjoin(tmp, suffix);
	free(tmp);
}
