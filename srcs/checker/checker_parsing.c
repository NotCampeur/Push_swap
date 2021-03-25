/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:56:52 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/25 16:32:49 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_bool		is_duplicate(char *str[])
{
	int		index;
	int		cursor;

	index = 1;
	while (str[index] != NULL)
	{
		cursor = index + 1;
		while (str[cursor] != NULL)
		{
			if (ft_strcmp(str[index], str[cursor]) == true)
			{
				ft_putstr_fd(2, FT_BOLD_RED"Error\n"FT_BASIC);
				return (true);
			}
			cursor++;
		}
		index++;
	}
	return (false);
}

static long long	static_ft_atoll(char *str)
{
	long long	result;
	long long	index;
	long long	sign;

	if (str == NULL)
		return (0);
	result = 0;
	index = 0;
	sign = 1;
	while (str[index] == ' ')
		index++;
	if (str[index] == '+')
		index++;
	else if (str[index] == '-')
	{
		index++;
		sign *= -1;
	}
	while (str[index] != '\0' && (str[index] >= '0' && str[index] <= '9'))
	{
		result = (result * 10) + (str[index] - '0');
		index++;
	}
	return (result * sign);
}

static t_bool		is_only_int(char *str[])
{
	int			index;
	long long	value;

	index = 1;
	value = 0;
	while (str[index] != NULL)
	{
		value = static_ft_atoll(str[index]);
		if (ft_strlen(str[index]) > 11
				|| value > INT_MAX
				|| value < INT_MIN)
		{
			ft_putstr_fd(2, FT_BOLD_RED"Error\n"FT_BASIC);
			return (false);
		}
		index++;
	}
	return (true);
}

static t_bool		is_suitable(char *str[])
{
	int	i;
	int	c;

	i = 1;
	while (str[i] != NULL)
	{
		c = 0;
		while (str[i][c] != '\0')
		{
			if ((ft_is_digit(str[i][c]) == false
				&& ft_is_white_space(str[i][c]) == false && str[i][c] != '-')
				|| (str[i][0] == '-' && str[i][1] == '\0')
				|| (c > 0 && (str[i][c] == '-' || str[i][c] == ' ')
				&& (str[i][c - 1] != ' '
									|| ft_is_digit(str[i][c + 1]) == false)))
			{
				ft_putstr_fd(2, FT_BOLD_RED"Error\n"FT_BASIC);
				return (false);
			}
			c++;
		}
		i++;
	}
	return (true);
}

int					parse_args(int argc, char *argv[])
{
	if (argc == 1)
		return (EXIT_FAILURE);
	if (is_duplicate(argv) == true)
		return (EXIT_FAILURE);
	if (is_only_int(argv) == false)
		return (EXIT_FAILURE);
	if (is_suitable(argv) == false)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
