/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 18:14:00 by vmormont          #+#    #+#             */
/*   Updated: 2019/12/14 19:52:28 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_vertex		*new_vertex(char *line, int vertex_type)
{
	t_vertex	*vertex;
	char		**split_line;

	split_line = ft_strsplit(line, ' ');
	vertex = (t_vertex *)ft_memalloc(sizeof(t_vertex));
	if (!vertex || !split_line)
		error(strerror(errno));
	check_split_vertex(split_line);
	vertex->name = check_name(split_line[0]);
	vertex->coord.x = check_coord(split_line[1]);
	vertex->coord.y = check_coord(split_line[2]);
	ft_free_2x_mas((void **)split_line);
	vertex->type = vertex_type;
	return (vertex);
}

void			add_vertex(t_vertex **start, t_vertex *vertex)
{
	t_vertex	*tmp;

	if (!(tmp = *start))
		*start = vertex;
	else
	{
		if (vertex->type == LI_VERTEX || vertex->type == LI_END)
		{
			while (tmp->next && tmp->next->type != LI_END)
				tmp = tmp->next;
			if (!tmp->next)
				tmp->next = vertex;
			else
			{
				vertex->next = tmp->next;
				tmp->next = vertex;
			}
		}
		else if (vertex->type == LI_START)
		{
			vertex->next = tmp;
			*start = vertex;
		}
	}
}

t_vertex		*get_vertex(t_vertex *vertex, char *name)
{
	while (vertex && !ft_strequ(vertex->name, name))
	{
		vertex = vertex->next;
		while (vertex && *vertex->name != *name)
			vertex = vertex->next;
	}
	if (!vertex)
		error(LI_ERROR_NOT_VALID_EDGE);
	return (vertex);
}

void			add_new_link(t_link **first_link, t_vertex *vertex, char *line)
{
	t_link		*link;
	char		**split_line;

	split_line = ft_strsplit(line, '-');
	link = (t_link *)ft_memalloc(sizeof(t_link));
	if (!link || !split_line)
		error(strerror(errno));
	check_split(split_line);
	link->a = get_vertex(vertex, split_line[0]);
	link->b = get_vertex(vertex, split_line[1]);
	ft_free_2x_mas((void **)split_line);
	if (*first_link)
		link->next = *first_link;
	*first_link = link;
}
