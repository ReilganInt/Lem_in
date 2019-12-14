/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:00:59 by cormund           #+#    #+#             */
/*   Updated: 2019/12/12 17:30:01 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant		*init_ants(int count_ants, t_vertex *start)
{
	t_ant	*first_ant;
	t_ant	*ant;

	first_ant = ft_memalloc(sizeof(t_ant));
	if (!first_ant)
		error(strerror(errno));
	first_ant->number = 1;
	first_ant->x = start->coord.x;
	first_ant->y = start->coord.y;
	ant = first_ant;
	while (--count_ants)
	{
		ant->next = ft_memalloc(sizeof(t_ant));
		if (!ant->next)
			error(strerror(errno));
		ant->next->x = start->coord.x;
		ant->next->y = start->coord.y;
		ant->next->number = ant->number + 1;
		ant = ant->next;
	}
	return (first_ant);
}

static void	ant_is_move(t_ant **ant)
{
	(*(*ant)->room)->vizited = false;
	++(*ant)->room;
	(*(*ant)->room)->vizited = true;
	if ((*(*ant)->room)->type == LI_END)
		++(*(*ant)->room)->count_ants;
}

void		move_ant(t_ant *ant, t_path *path, int visu_flag)
{
	if (ant->move && (*ant->room)->type == LI_END)
	{
		ant->move = false;
		ant->end = true;
		(*ant->room)->vizited = false;
	}
	else if (!ant->move)
	{
		while (path && (path->v[0]->vizited || !path->ants))
			path = path->next;
		if (!path)
			return ;
		ant->room = path->v;
		ant->move = true;
		(*path->v)->vizited = true;
		--path->ants;
		if ((*path->v)->type == LI_END)
			++(*path->v)->count_ants;
	}
	else if (ant->move)
		ant_is_move(&ant);
	if (ant->move && !visu_flag)
		ft_printf("L%d-%s ", ant->number, (*ant->room)->name);
}

static void	destroy_ants(t_ant *ants)
{
	t_ant	*tmp_free;
	t_ant	*tmp_ant;

	tmp_ant = ants;
	while (tmp_ant)
	{
		tmp_free = tmp_ant->next;
		free(tmp_ant);
		tmp_ant = tmp_free;
	}
}

t_ant		*push_ants(t_lem_in *li, t_paths *paths)
{
	t_ant	*ant;

	if (!li->first_ant)
		li->first_ant = init_ants(li->count_ants, li->start);
	while (li->end->count_ants < li->count_ants)
	{
		ant = li->first_ant;
		while (ant)
		{
			if (!ant->end)
				move_ant(ant, paths->path, li->visu);
			ant = ant->next;
		}
		if (li->visu == true)
			return (li->first_ant);
		else
			ft_printf("\n");
	}
	destroy_ants(li->first_ant);
	return (NULL);
}
