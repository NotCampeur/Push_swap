/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_parsing.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:57:38 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/17 15:18:37 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_PARSING_H
# define CHECKER_PARSING_H

/*
** Check if the program can properly work with the given params
*/
int				parse_args(int argc, char *argv[], t_bool *debug);

#endif
