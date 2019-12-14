/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:32:25 by cormund           #+#    #+#             */
/*   Updated: 2019/12/13 15:44:55 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		free_path(t_path *free_p)
{
	if (!free_p)
		return ;
	free_path(free_p->next);
	free(free_p->v);
	free(free_p);
	free_p = NULL;
}

static void		free_paths(t_paths *free_paths)
{
	free_path(free_paths->path);
	free(free_paths);
}

static t_paths	*new_best_paths(t_paths *old_best, t_paths *new)
{
	free_paths(old_best);
	return (new);
}

t_paths			*check_paths(t_lem_in *li)
{
	t_paths		*best_paths;
	t_paths		*new;
	int			count_required_paths;

	best_paths = suurballe(li, 1, NULL);
	if (best_paths->count_path == 0)
		error(LI_ERROR_NO_PATH_FROM_START_2_END);
	best_paths->count_steps = count_steps_and_ants(best_paths, li->count_ants);
	count_required_paths = LI_REQUIRED_TWO_PATHS;
	while (++count_required_paths < li->count_ants)
	{
		new = suurballe(li, count_required_paths, NULL);
		new->count_steps = count_steps_and_ants(new, li->count_ants);
		if (new->count_path < count_required_paths ||\
						new->count_steps > best_paths->count_steps)
		{
			free_paths(new);
			break ;
		}
		if (new->count_steps < best_paths->count_steps)
			best_paths = new_best_paths(best_paths, new);
		else
			free_paths(new);
	}
	return (best_paths);
}
