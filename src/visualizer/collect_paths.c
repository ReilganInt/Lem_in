/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:58:57 by cormund           #+#    #+#             */
/*   Updated: 2019/12/13 15:39:36 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_visualizer.h"

SDL_Color		get_color(t_vis *vis, int index)
{
	if (index <= COUNT_COLORS && index >= 0)
		return (vis->colors[index]);
	else
	{
		srand(index);
		return (set_color(rand(), SDL_ALPHA_OPAQUE));
	}
}

static void		add_color(t_step *step, t_path *path, int index, SDL_Color clr)
{
	if (index)
	{
		if (path->edge[index])
		{
			step->m_clrs[path->v[index]->id][path->v[index - 1]->id] = clr;
			step->m_clrs[path->v[index - 1]->id][path->v[index]->id] = clr;
		}
		else
		{
			step->m_clrs[path->v[index]->id][path->v[index - 1]->id] =\
										set_color(CLR_BLACK, LI_ALPHA_BLACK);
			step->m_clrs[path->v[index - 1]->id][path->v[index]->id] =\
										set_color(CLR_BLACK, LI_ALPHA_BLACK);
		}
	}
	else
	{
		step->m_clrs[path->v[index]->id][0] = clr;
		step->m_clrs[0][path->v[index]->id] = clr;
	}
	if (path->v[index]->type != LI_END)
		step->clr_v[path->v[index]->id].clr = clr;
}

t_step			*collect_srbll_paths(t_vis *vis, t_step *step, t_lem_in *li,\
																t_paths *paths)
{
	t_path		*path;
	int			n_path;
	int			n_v;

	path = paths->path;
	n_path = 0;
	while (n_path < paths->count_path)
	{
		n_v = LI_COUNTER;
		while (++n_v < path->dist)
		{
			step->next = new_step();
			step->next->m_clrs = init_matrix_clr(step->m_clrs, LI_COUNT_VRTX,\
																li->first_link);
			step->next->clr_v = init_vertex_clr(step->clr_v, li);
			add_color(step->next, path, n_v, get_color(vis, n_path));
			step->next->prev = step;
			step = step->next;
		}
		path = path->next;
		++n_path;
	}
	return (step);
}

t_step			*turn_off_unused_paths(t_step *step, t_lem_in *li, t_link *link)
{
	step->next = new_step();
	step->next->clr_v = init_vertex_clr(NULL, li);
	step->next->m_clrs = init_matrix_clr(step->m_clrs, LI_COUNT_VRTX, link);
	step->next->prev = step;
	step = step->next;
	while (link)
	{
		if (step->prev->m_clrs[link->a->id][link->b->id].r ==\
										set_color(CLR_LINE, LI_ALPHA_LINE).r)
			step->m_clrs[link->a->id][link->b->id] = set_color(CLR_BLACK,\
																LI_ALPHA_BLACK);
		else if (step->prev->m_clrs[link->a->id][link->b->id].r !=\
										set_color(CLR_BLACK, LI_ALPHA_BLACK).r)
			step->m_clrs[link->a->id][link->b->id] = set_color(CLR_LINE,\
																LI_ALPHA_LINE);
		link = link->next;
	}
	return (step);
}

t_step			*collect_final_paths(t_vis *vis, t_step *step, t_lem_in *li,\
																t_paths *paths)
{
	t_path		*path;
	int			n_v;
	int			n_clr;

	path = paths->path;
	n_clr = COUNT_COLORS;
	while (path)
	{
		step->next = new_step();
		step->next->m_clrs = init_matrix_clr(step->m_clrs, LI_COUNT_VRTX,\
															li->first_link);
		step->next->clr_v = init_vertex_clr(step->clr_v, li);
		step->next->prev = step;
		step = step->next;
		n_v = LI_COUNTER;
		while (++n_v < path->dist)
			add_color(step, path, n_v, get_color(vis, n_clr));
		--n_clr;
		path = path->next;
	}
	return (step);
}
