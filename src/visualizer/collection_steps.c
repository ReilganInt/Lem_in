/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collection_steps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:40:20 by cormund           #+#    #+#             */
/*   Updated: 2019/12/13 15:33:10 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_visualizer.h"

t_step				*new_step(void)
{
	t_step			*new;

	new = (t_step *)ft_memalloc(sizeof(t_step));
	if (!new)
		error(strerror(errno));
	return (new);
}

SDL_Color			**init_matrix_clr(SDL_Color **m_cpy, int n_v, t_link *link)
{
	SDL_Color		**m_clr;

	m_clr = (SDL_Color **)ft_memalloc_int_mas(n_v, n_v);
	if (!m_clr)
		error(strerror(errno));
	if (m_cpy)
		while (link)
		{
			m_clr[link->a->id][link->b->id] = m_cpy[link->a->id][link->b->id];
			link = link->next;
		}
	else
		while (link)
		{
			m_clr[link->a->id][link->b->id] = set_color(CLR_LINE,\
													LI_ALPHA_LINE);
			link = link->next;
		}
	return (m_clr);
}

t_circle			*init_vertex_clr(t_circle *cpy_v, t_lem_in *li)
{
	t_circle		*clr_v;
	int				i;

	clr_v = (t_circle *)ft_memalloc(sizeof(t_circle) * LI_COUNT_VRTX);
	if (!clr_v)
		error(strerror(errno));
	i = 0;
	while (i < LI_COUNT_VRTX)
	{
		clr_v[i].x = li->list_adj[i]->coord.x;
		clr_v[i].y = li->list_adj[i]->coord.y;
		clr_v[i].clr = cpy_v ? cpy_v[i].clr : set_color(CLR_CIRCLE,\
													SDL_ALPHA_OPAQUE);
		++i;
	}
	return (clr_v);
}

t_step				*collection_steps(t_vis *vis, t_lem_in *li, t_step *step)
{
	t_step			*last_step;

	last_step = NULL;
	if (!step)
	{
		step = new_step();
		step->m_clrs = init_matrix_clr(NULL, LI_COUNT_VRTX, li->first_link);
		step->clr_v = init_vertex_clr(NULL, li);
		return (step);
	}
	else if (vis->srbll_flag == false)
	{
		collect_srbll_paths(vis, step, li, vis->srbll);
		vis->srbll_flag = true;
	}
	else if (!vis->final_paths)
	{
		last_step = turn_off_unused_paths(step, li, li->first_link);
		vis->final_paths = collect_final_paths(vis, last_step, li, vis->paths);
	}
	else
		collect_ant_move(vis, li, step);
	return (step->next);
}
