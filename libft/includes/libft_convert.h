/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_convert.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:13:45 by ldutriez          #+#    #+#             */
/*   Updated: 2020/10/21 17:07:37 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_CONVERT_H
# define LIBFT_CONVERT_H

char			*ft_itoa_base(long long int nbr, char *base);
char			*ft_itoa(long long int nbr);
char			*ft_itoa_hexa(long long int nbr);
char			*ft_itoa_octa(long long int nbr);
int				ft_atoi(char *str);

#endif
