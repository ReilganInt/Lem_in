/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 13:10:37 by cormund           #+#    #+#             */
/*   Updated: 2019/12/06 12:56:56 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_vertex		*pop_queue(t_queue **queue)
{
	t_vertex	*v;
	t_queue		*head;

	v = NULL;
	if (*queue)
	{
		v = (*queue)->vertex;
		head = *queue;
		*queue = (*queue)->next;
		free(head);
		head = NULL;
	}
	return (v);
}

void			enqueue(t_queue **queue, t_vertex *vertex, t_queue **last)
{
	t_queue		*new;

	if (!*queue)
	{
		if (!(*queue = (t_queue *)ft_memalloc(sizeof(t_queue))))
			error(strerror(errno));
		(*queue)->vertex = vertex;
		*last = *queue;
	}
	else
	{
		if (!(new = (t_queue *)ft_memalloc(sizeof(t_queue))))
			error(strerror(errno));
		new->prev = *last;
		new->vertex = vertex;
		(*last)->next = new;
		*last = new;
	}
}

void			clean_queue(t_queue **queue)
{
	t_queue		*tmp;
	t_queue		*free_tmp;

	tmp = *queue;
	while (tmp)
	{
		free_tmp = tmp;
		tmp = tmp->next;
		free(free_tmp);
	}
	*queue = NULL;
}
