/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_load.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:28:19 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/17 15:17:46 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_LOAD_H
# define PUSH_SWAP_LOAD_H

/*
** Will split argv into a t_liat_node *.
*/
t_list_node		*init_stack(char **args);

/*
** Check if the program can properly work with the given params
*/
int				parse_args(int argc, char *argv[]);

#endif
