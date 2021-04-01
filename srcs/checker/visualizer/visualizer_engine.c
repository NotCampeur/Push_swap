/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer_engine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:31:11 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/01 15:20:51 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static void	draw_stacks_size(t_visualizer *vz, t_list_node **s_a,
													t_list_node **s_b, int op)
{
	char	*s_a_size;
	char	*s_b_size;
	char	*op_count;

	s_a_size = ft_itoa(ft_list_size(*s_a));
	s_b_size = ft_itoa(ft_list_size(*s_b));
	op_count = ft_itoa(op);
	draw_text(vz, s_a_size, rect_init(10, 10, ft_strlen(s_a_size) * 14, 50),
			color_init(0, 0, 255));
	draw_text(vz, s_b_size, rect_init(S_WD - vz->s_wd - 10 - ft_strlen(s_b_size)
				* 14, 10, ft_strlen(s_b_size) * 14, 50), color_init(0, 0, 255));
	draw_text(vz, op_count, rect_init((S_WD - vz->s_wd) / 2 -
		(ft_strlen(op_count) * 14) / 2, 10, ft_strlen(op_count) * 14, 50)
		, color_init(255, 255, 255));
	free(s_a_size);
	free(s_b_size);
	free(op_count);
	SDL_RenderPresent(vz->render);
}

static void	draw_bar(t_visualizer *vz, t_list_node **stack,
													int index, char stack_id)
{
	int			height;
	SDL_Rect	bar;

	height = (((t_node*)(*stack)->data)->index + 1) * S_HT / vz->stack_m_s;
	bar = rect_init(vz->b_wd * index, S_HT - height, vz->b_wd, height);
	if (stack_id == 'a')
	{
		if (((*stack)->next != NULL && ((t_node*)(*stack)->data)->value
			< ((t_node*)(*stack)->next->data)->value) || (*stack)->next == NULL)
			sdl_render_fill_rect(vz->render, bar, color_init(0, 200, 0));
		else
			sdl_render_fill_rect(vz->render, bar, color_init(155, 0, 0));
	}
	else if (stack_id == 'b')
	{
		if (((*stack)->next != NULL && ((t_node*)(*stack)->data)->value
			> ((t_node*)(*stack)->next->data)->value) || (*stack)->next == NULL)
			sdl_render_fill_rect(vz->render, bar, color_init(0, 0, 200));
		else
			sdl_render_fill_rect(vz->render, bar, color_init(155, 0, 0));
	}
}

void		draw_stacks(t_visualizer *vz, t_list_node **s_a, t_list_node **s_b)
{
	int			index;
	t_list_node	*tmp;

	index = 0;
	sdl_render_clear(vz->render, color_init(30, 30, 30));
	tmp = *s_a;
	while (*s_a != NULL)
	{
		draw_bar(vz, s_a, index, 'a');
		index++;
		*s_a = (*s_a)->next;
	}
	*s_a = tmp;
	tmp = *s_b;
	while (*s_b != NULL)
	{
		draw_bar(vz, s_b, index, 'b');
		index++;
		*s_b = (*s_b)->next;
	}
	*s_b = tmp;
	sdl_render_fill_rect(vz->render,
		rect_init(vz->b_wd * ft_list_size(*s_a), 0, 1, S_HT),
		color_init(255, 155, 0));
}

void		visualize_operation(t_list_node *op, t_list_node **stack_a,
				t_list_node **stack_b, t_visualizer *visualizer)
{
	t_list_node	*tmp;
	SDL_Event	e;
	t_bool		step;
	int			i;

	tmp = op;
	step = false;
	i = 0;
	while (visualizer->run == true || op != NULL)
	{
		draw_stacks_size(visualizer, stack_a, stack_b, i);
		draw_stacks(visualizer, stack_a, stack_b);
		if (SDL_PollEvent(&e) == 1 && e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_SPACE && visualizer->run == true)
				visualizer->run = false;
			else if (e.key.keysym.sym == SDLK_SPACE && visualizer->run == false)
				visualizer->run = true;
			if (e.key.keysym.sym == SDLK_RIGHT)
				step = true;
		}
		if (visualizer->run == true || step == true)
		{
			if (op != NULL)
			{
				if (ft_strcmp(op->data, "sa\n") || ft_strcmp(op->data, "ss\n"))
					swap_stack(stack_a);
				if (ft_strcmp(op->data, "sb\n") || ft_strcmp(op->data, "ss\n"))
					swap_stack(stack_b);
				if (ft_strcmp(op->data, "pa\n"))
					push_a(stack_a, stack_b);
				if (ft_strcmp(op->data, "pb\n"))
					push_b(stack_a, stack_b);
				if (ft_strcmp(op->data, "ra\n") || ft_strcmp(op->data, "rr\n"))
					rotate_a(stack_a);
				if (ft_strcmp(op->data, "rb\n") || ft_strcmp(op->data, "rr\n"))
					rotate_b(stack_b);
				if (ft_strcmp(op->data, "rra\n") || ft_strcmp(op->data, "rrr\n"))
					reverse_rotate_a(stack_a);
				if (ft_strcmp(op->data, "rrb\n") || ft_strcmp(op->data, "rrr\n"))
					reverse_rotate_b(stack_b);
				i++;
				op = op->next;
			}
			step = false;
		}
	}
	op = tmp;
}
