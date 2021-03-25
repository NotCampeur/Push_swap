/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer_system.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:28:04 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/25 17:50:24 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

t_visualizer	init_visualizer(void)
{
	t_visualizer result;

	result.win = NULL;
	result.render = NULL;
	result.font = NULL;
	result.stack_m_s = 0;
	result.b_wd = 0;
	return (result);
}

t_visualizer	*start_visualizer(t_list_node *stack_a)
{
	t_visualizer *result;

	result = (t_visualizer*)malloc(sizeof(t_visualizer));
	*result = init_visualizer();
	SDL_Init(SDL_INIT_VIDEO);
	result->win = SDL_CreateWindow("Push Swap's checker visualizer",
						SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
						S_WD, S_HT, 0);
	result->render = SDL_CreateRenderer(result->win, -1, 0);
	TTF_Init();
	result->font = TTF_OpenFont("ressources/OpenSans-Bold.ttf", 20);
	SDL_RenderClear(result->render);
	SDL_RenderPresent(result->render);
	result->stack_m_s = ft_list_size(stack_a);
	result->b_wd = S_WD / result->stack_m_s;
	return (result);
}

void			destroy_visualizer(t_visualizer *visualizer)
{
	if (visualizer->render != NULL)
		SDL_DestroyRenderer(visualizer->render);
	if (visualizer->win != NULL)
		SDL_DestroyWindow(visualizer->win);
	if (visualizer->font != NULL)
		TTF_CloseFont(visualizer->font);
	TTF_Quit();
	SDL_Quit();
	free(visualizer);
}

void			visualizer_quit(t_visualizer *visualizer,
						t_list_node *stack_a, t_list_node *stack_b, void **ops)
{
	if (stack_a != NULL)
		ft_list_clear(&stack_a, free);
	if (stack_b != NULL)
		ft_list_clear(&stack_b, free);
	if (ops != NULL)
		ft_free_tab(ops);
	if (visualizer != NULL)
		destroy_visualizer(visualizer);
	exit(0);
}

void			visualizer_error_quit(t_visualizer *visualizer,
						t_list_node *stack_a, t_list_node *stack_b, void **ops)
{
	if (stack_a != NULL)
		ft_list_clear(&stack_a, free);
	if (stack_b != NULL)
		ft_list_clear(&stack_b, free);
	if (ops != NULL)
		ft_free_tab(ops);
	if (visualizer != NULL)
		destroy_visualizer(visualizer);
	exit(1);
}
