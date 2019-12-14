/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjacencies.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:34:01 by cormund           #+#    #+#             */
/*   Updated: 2019/12/12 12:01:09 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				set_matrix_adj(char **matrix_adj, t_link *link)
{
	while (link)
	{
		matrix_adj[link->a->id][link->b->id] = LI_TRUE;
		matrix_adj[link->b->id][link->a->id] = LI_TRUE;
		link = link->next;
	}
}

static int			get_count_links(char *links, int count_vertex)
{
	int				count_links;
	int				i;

	count_links = 0;
	i = 0;
	while (i < count_vertex)
	{
		count_links += links[i];
		++i;
	}
	return (count_links);
}

static void			get_adjacencies(t_lem_in *li, t_vertex **adj, char *links)
{
	int				i;

	i = 0;
	while (i < li->count_vertex)
	{
		if (links[i] == LI_TRUE)
		{
			*adj = li->hash_table[i];
			++adj;
		}
		++i;
	}
}

static void			list_adj(t_lem_in *li)
{
	t_vertex		**adj;
	int				count_links;
	int				i;

	i = 0;
	while (i < li->count_vertex)
	{
		count_links = get_count_links(li->matrix_adj[i], li->count_vertex);
		adj = (t_vertex **)malloc(sizeof(t_vertex *) * count_links);
		if (!adj)
			error(strerror(errno));
		get_adjacencies(li, adj, li->matrix_adj[i]);
		li->list_adj[i]->count_edges = count_links;
		li->list_adj[i]->adj = adj;
		++i;
	}
}

void				adjacencies(t_lem_in *li)
{
	li->count_vertex = id_increment(li->start);
	li->hash_table = hash_table(li->start, li->count_vertex);
	li->matrix_adj = ft_memalloc_char_2xmas(li->count_vertex, li->count_vertex);
	li->edges = li->matrix_adj;
	if (!li->matrix_adj)
		error(strerror(errno));
	set_matrix_adj(li->matrix_adj, li->first_link);
	li->list_adj = li->hash_table;
	list_adj(li);
	li->end = li->list_adj[li->count_vertex - 1];
}
