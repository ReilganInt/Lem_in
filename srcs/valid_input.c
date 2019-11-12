/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validInput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:14:55 by vmormont          #+#    #+#             */
/*   Updated: 2019/11/08 21:14:56 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	1 - start, 2 - end, 3 - comment, 4 - vertex, 5 - edges, 6 - ants or trash
*/

static int		valid_vertexs(t_input **input)
{
	int			vertexs;
	int			error;

	vertexs = 0;
	error = 0;
	while ((*input) && (*input)->type != 5)
	{
		if ((*input)->type == 4)
			++vertexs;
		else if ((*input)->type == 1 || (*input)->type == 2)
		{
			if (!((*input) = (*input)->front))
				put_error("Not valid start/end");
			if ((*input)->type == 3)
				continue;
			if ((*input)->type != 4)
				put_error("Not valid start/end");
			(*input)->type = (*input)->back->type;
			(*input)->back->type = 3;
			error = error + (*input)->type;
			++vertexs;
		}
		else if ((*input)->type != 3)
			put_error("Not valid vertex");
		(*input) = (*input)->front;
	}
	if (error != 3 || vertexs < 2)
		put_error("Not valid vertexs");
	return (vertexs);
}

static int		valid_ants(t_input **input)
{
	int			ants;

	ants = 0;
	while ((*input)->type == 3)
		(*input) = (*input)->front;
	if (!(*input))
		put_error("Can't find ants");
	ants = ft_atoi((*input)->line);
	if (!(ants) || !(ft_strequ((*input)->line, ft_itoa(ants))))
		put_error("Not valid ants");
	return (ants);
}

void			valid_input(t_input	*input, t_lemin *lemin)
{
	lemin->ants = valid_ants(&input);
	lemin->vertexs = valid_vertexs(&input);

}
