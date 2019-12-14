/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:02:47 by cormund           #+#    #+#             */
/*   Updated: 2019/12/13 15:37:44 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_visualizer.h"

static void		events(t_vis *vis, t_step **step)
{
	if (SDL_EVENT == SDL_QUIT || SDL_KEYSTATE[SDL_ESCAPE])
		vis->quit = SDL_TRUE;
	else if (SDL_EVENT == SDL_KEYDOWN && SDL_KEYSTATE[SDL_SPACE])
		vis->pause ^= SDL_TRUE;
	else if (vis->pause && SDL_EVENT == SDL_KEYDOWN &&\
			SDL_KEYSTATE[SDL_RIGHT] && *step && (*step)->next && !(*step)->fin)
		*step = (*step)->next;
	else if (vis->pause && SDL_EVENT == SDL_KEYDOWN &&\
			SDL_KEYSTATE[SDL_LEFT] && *step && (*step)->prev)
		*step = (*step)->prev;
	else if (SDL_EVENT == SDL_KEYDOWN && SDL_KEYSTATE[SDL_UP] &&\
													vis->delay < 100)
		++vis->delay;
	else if (SDL_EVENT == SDL_KEYDOWN && SDL_KEYSTATE[SDL_DOWN] &&\
													vis->delay > 0)
		--vis->delay;
	else if (SDL_EVENT == SDL_KEYDOWN && SDL_KEYSTATE[SDL_R])
		*step = vis->first_step;
}

void			render_update(t_vis *vis, t_lem_in *li, t_step *step)
{
	SDL_SetRenderDrawColor(vis->ren, vis->bgrnd_clr.r, vis->bgrnd_clr.g,\
										vis->bgrnd_clr.b, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(vis->ren);
	if (step)
		render_graph(vis, li, step);
	SDL_RenderPresent(vis->ren);
}

void			loop(t_vis *vis, t_lem_in *li, t_step *step)
{
	int			delay;

	delay = vis->delay;
	while (!vis->quit)
	{
		SDL_Delay(2);
		while (SDL_PollEvent(&vis->e))
			events(vis, &step);
		render_update(vis, li, step);
		if (!vis->pause && (!delay || step->n_ant) && !step->fin)
			step = next_step(vis, li, step);
		delay += delay ? -1 : vis->delay;
	}
}
