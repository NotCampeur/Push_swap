/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:25:33 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/23 15:10:18 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	ft_atoll(char *str)
{
	long long	result;
	long long	index;
	long long	sign;

	if (str == NULL)
		return ((int)ft_print_error(__PRETTY_FUNCTION__, __LINE__, FT_E_ARG));
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

static t_bool		is_duplicate(char *str)
{
	char	**c_nb;
	int		index;
	int		cursor;

	c_nb = ft_split(str, ' ');
	index = 0;
	while (c_nb[index] != NULL)
	{
		cursor = index + 1;
		while (c_nb[cursor] != NULL)
		{
			if (ft_strcmp(c_nb[index], c_nb[cursor]) == true)
			{
				ft_free_tab((void**)c_nb);
				ft_putstr_fd(2,
					FT_BOLD_RED"Error\nDuplicated numbers\n"FT_BASIC);
				return (true);
			}
			cursor++;
		}
		index++;
	}
	ft_free_tab((void**)c_nb);
	return (false);
}

static t_bool		is_only_int(char *str)
{
	char		**char_numbers;
	int			index;
	long long	value;

	char_numbers = ft_split(str, ' ');
	index = 0;
	value = 0;
	while (char_numbers[index] != NULL)
	{
		value = ft_atoll(char_numbers[index]);
		if (ft_strlen(char_numbers[index]) > 11
				|| value > INT_MAX
				|| value < INT_MIN)
		{
			ft_putstr_fd(2,
				FT_BOLD_RED"Error\nSome arguments are not integers\n"FT_BASIC);
			ft_putstr_fd(2, char_numbers[index]);
			ft_free_tab((void**)char_numbers);
			return (false);
		}
		index++;
	}
	ft_free_tab((void**)char_numbers);
	return (true);
}

static t_bool		is_suitable(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if ((ft_is_digit(str[index]) == false
			&& ft_is_white_space(str[index]) == false && str[index] != '-')
			|| (str[0] == '-' && str[1] == '\0')
			|| (index > 0 && str[index] == '-'
			&& (str[index - 1] != ' ' || ft_is_digit(str[index + 1]) == false)))
		{
			ft_putstr_fd(2,
				FT_BOLD_RED"Error\nArgument not suitable\n"FT_BASIC);
			return (false);
		}
		index++;
	}
	return (true);
}

int					parse_args(int argc, char *argv[])
{
	if (argc == 1
		|| (argc == 2 && (ft_strlen(argv[1]) == 0
				|| (argv[1][0] == '-' && ft_is_digit(argv[1][1]) == false))))
		return (EXIT_FAILURE);
	else if (argc > 2)
	{
		ft_putstr_fd(2, FT_BOLD_RED"Error\nToo much arguments\n"FT_BASIC);
		return (EXIT_FAILURE);
	}
	if (is_duplicate(argv[1]) == true)
		return (EXIT_FAILURE);
	if (is_only_int(argv[1]) == false)
		return (EXIT_FAILURE);
	if (is_suitable(argv[1]) == false)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
