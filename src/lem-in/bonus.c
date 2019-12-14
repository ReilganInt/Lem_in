/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:55:42 by cormund           #+#    #+#             */
/*   Updated: 2019/12/11 15:52:40 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			print_input(t_input *in)
{
	while (in)
	{
		ft_putendl(in->line);
		in = in->next;
	}
}

void			print_matrix_adj(char **matrix, int count_vertex)
{
	int			i;
	int			j;

	ft_printf("\nmatrix_adj:\n\n ");
	i = 0;
	while (i < count_vertex)
		ft_printf("  %d", i++);
	j = 0;
	while (j < count_vertex)
	{
		ft_printf("\n%d", j);
		i = 0;
		while (i < count_vertex)
			ft_printf("  %d", matrix[j][i++]);
		++j;
	}
	ft_printf("\n");
}

void			print_list_adj(t_vertex **list_adj, int count_vertex)
{
	int			i;
	int			j;
	t_vertex	**linked;

	ft_printf("\nlist_adj:\n ");
	i = 0;
	while (i < count_vertex)
	{
		ft_printf("\n%d ", list_adj[i]->id);
		linked = list_adj[i]->adj;
		j = list_adj[i]->count_edges;
		while (j--)
		{
			ft_printf("%d-", (*linked)->id);
			++linked;
		}
		++i;
	}
	ft_printf("\n");
}

void			print_finding(t_paths *finding)
{
	t_path		*path;
	int			i;
	int			j;

	ft_printf("\n-----All paths found in the graph:-----\n");
	path = finding->path;
	j = 1;
	while (path)
	{
		ft_printf("\nPath #%i:\n", j++);
		ft_printf("Path length %d\n\n", path->dist);
		i = 0;
		while (i < path->dist)
		{
			if (i + 1 < path->dist)
				ft_printf("%s - ", path->v[i]->name);
			else
				ft_printf("%s", path->v[i]->name);
			++i;
		}
		ft_printf("\n");
		path = path->next;
	}
	ft_printf("\n--Total number of paths in \
the graph:--\n%d\n", finding->count_path);
}
