/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <vmormont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 13:28:56 by cormund           #+#    #+#             */
/*   Updated: 2019/12/04 20:30:21 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				id_increment(t_vertex *vertex)
{
	int			count_vertex;

	count_vertex = 0;
	while (vertex)
	{
		vertex->id = count_vertex;
		++count_vertex;
		vertex = vertex->next;
	}
	return (count_vertex);
}

t_vertex		**hash_table(t_vertex *vertex, int count_vertex)
{
	t_vertex	**hash_table;
	int			i;

	hash_table = (t_vertex **)ft_memalloc(sizeof(t_vertex *)
											* (count_vertex + 1));
	if (!hash_table)
		error(strerror(errno));
	i = 0;
	while (i < count_vertex)
	{
		hash_table[i] = vertex;
		vertex = vertex->next;
		++i;
	}
	return (hash_table);
}
