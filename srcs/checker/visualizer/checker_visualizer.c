/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_visualizer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:31:11 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/24 18:16:27 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	draw_text(t_visualizer *visualizer, char *to_print,
										SDL_Rect pos, SDL_Color color)
{
	SDL_Texture	**texture;

	texture = create_texture(visualizer,
						TTF_RenderText_Solid(visualizer->font, to_print, color));
	render_texture(visualizer, texture, NULL, &pos);
	SDL_DestroyTexture(*texture);
	free(texture);
}

static void		draw_stacks_size(t_visualizer *visualizer,
					t_list_node **stack_a, t_list_node **stack_b, int op)
{
	char	*stack_a_size;
	char	*stack_b_size;
	char	*op_count;
	
	if (stack_a != NULL && *stack_a != NULL)
		stack_a_size = ft_itoa(ft_list_size(*stack_a));
	else
		stack_a_size = ft_strdup("0");
	if (stack_b != NULL && *stack_b != NULL)
		stack_b_size = ft_itoa(ft_list_size(*stack_b));
	else
		stack_b_size = ft_strdup("0");
	op_count = ft_itoa(op);
	draw_text(visualizer, stack_a_size
			, rect_init(10, 10, ft_strlen(stack_a_size) * 14, 50)
			, color_init(0, 0, 255));
	draw_text(visualizer, stack_b_size
			, rect_init(SCREEN_WIDTH - 10 - ft_strlen(stack_b_size) * 14, 10,
			ft_strlen(stack_b_size) * 14, 50), color_init(0, 0, 255));
	draw_text(visualizer, op_count,
		rect_init(SCREEN_WIDTH / 2 - (ft_strlen(op_count) * 14) / 2, 10,
		ft_strlen(op_count) * 14, 50), color_init(255, 255, 255));
	free(stack_a_size);
	free(stack_b_size);
	free(op_count);
}

void			draw_stacks(t_visualizer *visualizer,
					t_list_node **stack_a, t_list_node **stack_b)
{
	int			index;
	static int	op = 0;
	SDL_Rect	number;
	int			width;
	int			height;
	t_list_node	*tmp;

	index = 0;
	SDL_SetRenderDrawColor(visualizer->render, 30, 30, 30, 255);
	SDL_RenderClear(visualizer->render);
	tmp = *stack_a;
	width = SCREEN_WIDTH / visualizer->stack_max_size;
	while (*stack_a != NULL)
	{
		if ((*stack_a)->next != NULL
			&& ((t_node*)(*stack_a)->data)->value
				< ((t_node*)(*stack_a)->next->data)->value)
			SDL_SetRenderDrawColor(visualizer->render, 0, 255, 0, 255);
		else if ((*stack_a)->next == NULL)
			SDL_SetRenderDrawColor(visualizer->render, 0, 255, 0, 255);
		else
			SDL_SetRenderDrawColor(visualizer->render, 255, 0, 0, 255);
		height = ((t_node*)(*stack_a)->data)->index *
									SCREEN_HEIGHT / visualizer->stack_max_size;
		number = rect_init(width * index,
										SCREEN_HEIGHT - height, width, height);
		SDL_RenderFillRect(visualizer->render, &number);
		index++;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = tmp;
	tmp = *stack_b;
	SDL_SetRenderDrawColor(visualizer->render, 255, 255, 255, 255);
	number = rect_init(width * index - 1, 0, 1, SCREEN_HEIGHT);
	SDL_RenderFillRect(visualizer->render, &number);
	SDL_SetRenderDrawColor(visualizer->render, 255, 0, 0, 255);
	while (*stack_b != NULL)
	{
		if ((*stack_b)->next != NULL
			&& ((t_node*)(*stack_b)->data)->value
			> ((t_node*)(*stack_b)->next->data)->value)
			SDL_SetRenderDrawColor(visualizer->render, 0, 0, 255, 255);
		else if ((*stack_b)->next == NULL)
			SDL_SetRenderDrawColor(visualizer->render, 0, 255, 0, 255);
		else
			SDL_SetRenderDrawColor(visualizer->render, 255, 0, 0, 255);
		height = ((t_node*)(*stack_b)->data)->index *
									SCREEN_HEIGHT / visualizer->stack_max_size;
		number = rect_init(width * index,
										SCREEN_HEIGHT - height, width, height);
		SDL_RenderFillRect(visualizer->render, &number);
		index++;
		*stack_b = (*stack_b)->next;
	}
	*stack_b = tmp;
	draw_stacks_size(visualizer, stack_a, stack_b, op);
	SDL_RenderPresent(visualizer->render);
	op++;
}

t_visualizer	*start_visualizer(t_list_node *stack_a)
{
	t_visualizer *result;
	
	result = (t_visualizer*)malloc(sizeof(t_visualizer));
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT,
								SDL_WINDOW_SHOWN, &result->win, &result->render);
	TTF_Init();
	SDL_SetWindowTitle(result->win, "Push Swap's checker visualizer");
	result->font = TTF_OpenFont("ressources/OpenSans-Bold.ttf", 20);
	SDL_RenderClear(result->render);
	SDL_RenderPresent(result->render);
	result->stack_max_size = ft_list_size(stack_a);
	return (result);
}

void	destroy_visualizer(t_visualizer *visualizer)
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