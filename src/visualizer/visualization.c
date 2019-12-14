/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:40:31 by cormund           #+#    #+#             */
/*   Updated: 2019/12/13 16:07:22 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_visualizer.h"

static void	cleaning_up(t_vis *vis, t_step *stp)
{
	t_step	*tmp;

	while (stp)
	{
		if (!stp->n_ant && !stp->fin)
		{
			ft_free_2x_mas((void **)stp->m_clrs);
			free(stp->clr_v);
		}
		else if (stp->n_ant)
			free(stp->ants_move);
		tmp = stp;
		stp = stp->next;
		free(tmp);
	}
	clear_paths(&vis->srbll->path);
	free(vis->srbll);
	clear_paths(&vis->paths->path);
	free(vis->paths);
	free(vis);
}

static void	destroy_init(t_vis *vis)
{
	SDL_DestroyRenderer(vis->ren);
	SDL_DestroyWindow(vis->win);
	SDL_Quit();
}

static void	init(t_vis *vis)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
		error(SDL_GetError());
	vis->win = SDL_CreateWindow("Lem-in visualizer", SDL_WINDOWPOS_CENTERED,\
	SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!vis->win)
		error(NULL);
	if (!(vis->ren = SDL_CreateRenderer(vis->win, -1, 0)))
		error(NULL);
	vis->keystate = SDL_GetKeyboardState(NULL);
	vis->delay = 30;
}

void		visualizer(t_lem_in *li, int count_paths)
{
	t_vis	*vis;

	li->visu = true;
	if (!(vis = ft_memalloc(sizeof(t_vis))))
		error(strerror(errno));
	init(vis);
	background(vis, li);
	vis->srbll = ft_memalloc(sizeof(t_paths));
	if (!vis->srbll)
		error(strerror(errno));
	vis->paths = suurballe(li, count_paths, vis->srbll);
	vis->first_step = collection_steps(vis, li, NULL);
	loop(vis, li, vis->first_step);
	destroy_init(vis);
	cleaning_up(vis, vis->first_step);
}
