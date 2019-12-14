/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:23:55 by cormund           #+#    #+#             */
/*   Updated: 2019/12/13 18:20:42 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_input	*check_comment(t_input *input, t_lem_in **li)
{
	t_vertex	*vertex;
	t_input		*comment;

	if ((input->type == LI_START || input->type == LI_END))
	{
		comment = input->next;
		while (comment->type == LI_COMMENT)
			comment = comment->next;
		vertex = new_vertex(comment->line, input->type);
		add_vertex(&(*li)->start, vertex);
		input = comment;
	}
	return (input);
}

void			parsing(t_lem_in *li)
{
	t_input		*input;
	t_vertex	*vertex;

	if ((input = li->first_line->next))
		while (input->line)
		{
			if ((input->type == LI_START || input->type == LI_END))
				input = check_comment(input, &li);
			else if (input->type == LI_VERTEX)
			{
				vertex = new_vertex(input->line, LI_VERTEX);
				add_vertex(&li->start, vertex);
			}
			else if (input->type == LI_LINK)
			{
				add_new_link(&li->first_link, li->start, input->line);
				li->flag_link = true;
			}
			input = input->next;
		}
	li->count_ants = validation(li, li->first_line->line);
}
