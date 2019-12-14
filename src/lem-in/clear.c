/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <vmormont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:41:32 by vmormont          #+#    #+#             */
/*   Updated: 2019/12/04 20:52:24 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			clear_links(t_link *links)
{
	t_link		*tmp;

	while (links)
	{
		tmp = links;
		links = links->next;
		free(tmp);
	}
}

void			clear_input(t_input *input)
{
	t_input		*tmp_head;
	t_input		*tmp_tail;

	tmp_head = input;
	while (tmp_head)
	{
		ft_strdel(&tmp_head->line);
		tmp_tail = tmp_head;
		tmp_head = tmp_head->next;
		free(tmp_tail);
	}
}

void			clear_start(t_vertex *start)
{
	t_vertex	*tmp_head;
	t_vertex	*tmp_tail;

	tmp_head = start;
	while (tmp_head)
	{
		tmp_tail = tmp_head;
		tmp_head = tmp_head->next;
		free(tmp_tail->adj);
		ft_strdel(&tmp_tail->name);
		free(tmp_tail);
	}
}

void			clear_matrix(char **matrix)
{
	int			i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		++i;
	}
	free(matrix);
}

void			clear_paths(t_path **paths)
{
	t_path		*tmp_head;
	t_path		*tmp_tail;

	tmp_head = *paths;
	while (tmp_head)
	{
		tmp_tail = tmp_head;
		tmp_head = tmp_head->next;
		free(tmp_tail->v);
		free(tmp_tail);
	}
}
