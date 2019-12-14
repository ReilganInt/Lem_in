/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_count_steps_and_ants.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 13:40:40 by cormund           #+#    #+#             */
/*   Updated: 2019/12/11 15:58:31 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		init_dist(int *dist, t_paths *finding)
{
	t_path		*path;
	int			i;

	path = finding->path;
	i = 0;
	while (i < finding->count_path)
	{
		dist[i] = path->dist;
		path = path->next;
		i++;
	}
}

static void		count_ants_for_paths(int *dist, t_path *path)
{
	int			i;

	i = 0;
	while (path)
	{
		path->ants = dist[i] - path->dist;
		++i;
		path = path->next;
	}
}

int				count_steps_and_ants(t_paths *paths, int count_ants)
{
	int			dist_increment[paths->count_path + 1];
	int			max_use_index;
	int			i;

	init_dist(dist_increment, paths);
	dist_increment[paths->count_path] = INT_MAX;
	max_use_index = 0;
	while (count_ants)
	{
		while (dist_increment[max_use_index] >=
				dist_increment[max_use_index + 1])
			++max_use_index;
		i = 0;
		while (i <= max_use_index && count_ants)
		{
			++dist_increment[i];
			++i;
			--count_ants;
		}
	}
	count_ants_for_paths(dist_increment, paths->path);
	return (dist_increment[0] - 1);
}
