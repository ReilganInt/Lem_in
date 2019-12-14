/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:54:03 by vmormont          #+#    #+#             */
/*   Updated: 2019/12/09 11:56:57 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				get_edge(t_lem_in *li, t_vertex *src, t_vertex *dst)
{
	return (li->matrix_adj[src->id][dst->id]);
}

static t_vertex	*marked_adjacent(t_queue **queue, t_lem_in *li,\
								t_vertex *vrx, t_queue **last)
{
	int			i;

	i = LI_COUNTER;
	while (++i < LI_COUNT_ADJACENTS)
		if (get_edge(li, vrx, vrx->adj[i]) == 1 && !LI_ADJ_MARKED)
		{
			vrx->adj[i]->dist = vrx->dist + 1;
			vrx->adj[i]->neighbor = vrx;
			if (vrx->adj[i]->type == LI_END)
				return (vrx->adj[i]);
			else
				enqueue(queue, vrx->adj[i], last);
			LI_ADJ_MARKED = true;
		}
	return (NULL);
}

t_vertex		*bfs(t_queue **queue, t_lem_in *li)
{
	t_vertex	*vrx;
	t_queue		*last;

	enqueue(queue, li->list_adj[0], &last);
	while (*queue)
	{
		vrx = pop_queue(queue);
		if (vrx->splited && get_edge(li, vrx, vrx->neighbor) == LI_OPEN)
		{
			if (vrx->out->type != LI_START && !vrx->out->marked)
			{
				vrx->out->dist = vrx->dist + 1;
				vrx->out->marked = true;
				vrx->out->neighbor = vrx;
				if ((vrx = marked_adjacent(queue, li, vrx->out, &last)))
					return (vrx);
			}
		}
		else if ((vrx = marked_adjacent(queue, li, vrx, &last)))
			return (vrx);
	}
	return (NULL);
}
