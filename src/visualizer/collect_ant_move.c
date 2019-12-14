/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_ant_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:11:59 by cormund           #+#    #+#             */
/*   Updated: 2019/12/13 15:34:11 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_visualizer.h"

static int		catching_ants(t_circle *anthill, t_ant *ant)
{
	int			n_ants;

	n_ants = 0;
	while (ant)
	{
		if (ant->move)
		{
			anthill[n_ants].x = ant->x;
			anthill[n_ants].y = ant->y;
			ant->x = (*ant->room)->coord.x;
			ant->y = (*ant->room)->coord.y;
			anthill[n_ants].dx = (ant->x - anthill[n_ants].x) /\
												COUNT_MOVE_STEPS;
			anthill[n_ants].dy = (ant->y - anthill[n_ants].y) /\
												COUNT_MOVE_STEPS;
			++n_ants;
		}
		ant = ant->next;
	}
	return (n_ants);
}

static t_step	*init_move(t_circle *anthill, int n_ant, t_step *prev_move)
{
	t_step		*move;
	int			i;

	move = new_step();
	move->prev = prev_move;
	prev_move->next = move;
	ft_memcpy(move, prev_move, sizeof(t_step));
	move->n_ant = n_ant;
	move->ants_move = (t_circle *)malloc(sizeof(t_circle) * n_ant);
	if (!move->ants_move)
		error(strerror(errno));
	i = 0;
	while (i < n_ant)
	{
		move->ants_move[i].x = anthill[i].x;
		move->ants_move[i].y = anthill[i].y;
		anthill[i].x += anthill[i].dx;
		anthill[i].y += anthill[i].dy;
		++i;
	}
	return (move);
}

t_step			*movement_ant(t_circle *anthill, int n_ant, t_step *step)
{
	t_step		*move;
	int			n_step;

	n_step = 0;
	move = step;
	while (n_step < COUNT_MOVE_STEPS)
	{
		move = init_move(anthill, n_ant, move);
		++n_step;
	}
	return (move);
}

void			collect_ant_move(t_vis *vis, t_lem_in *li, t_step *final_step)
{
	t_step		*step;
	t_circle	*anthill;
	int			n_ant;

	count_steps_and_ants(vis->paths, li->count_ants);
	anthill = (t_circle *)malloc(sizeof(t_circle) * li->count_ants);
	if (!anthill)
		error(strerror(errno));
	step = final_step;
	while (push_ants(li, vis->paths))
	{
		n_ant = catching_ants(anthill, li->first_ant);
		step = movement_ant(anthill, n_ant, step);
	}
	step->next = new_step();
	ft_memcpy(step->next, final_step, sizeof(t_step));
	step->next->fin = SDL_TRUE;
	step->next->prev = step;
	step->next->next = NULL;
	free(anthill);
}
