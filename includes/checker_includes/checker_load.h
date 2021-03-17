/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_load.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:15:07 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/17 13:58:17 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_LOAD_H
# define CHECKER_LOAD_H

/*
** Read STDIN until a \n is catch
*/
void			**get_instructions(void);

/*
** Will split argv into a t_liat_node *.
*/
t_list_node		*init_stack(char **args);

#endif
