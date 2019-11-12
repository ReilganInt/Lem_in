/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getInput.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 22:37:43 by vmormont          #+#    #+#             */
/*   Updated: 2019/11/07 22:37:46 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	1 - start, 2 - end, 3 - comment, 4 - vertex, 5 - edges, 6 - ants or trash
*/

static int		check_line(char *line)
{
    int			i;

    if (*line == '#')
    {
       if (ft_strequ(line, "##start"))
			return (1);
		if (ft_strequ(line, "##end"))
			return (2);
		return (3);
    }
	while (*line)
	{
		if (*line == ' ')
			return (4);
		if (*line == '-')
			return (5);
		++line;
	}
	return (6);
}

static t_input	*new_t_input(t_input *temp)
{
	t_input		*new_input;

	if (new_input = (t_input *)malloc(sizeof(t_input)))
		put_error("Can't allocate memory");
	new_input->line = NULL;
	new_input->type = NULL;
	if (temp && temp->front)
		new_input->back = temp;
	else
		new_input->back = NULL;
	new_input->front = NULL;
	return (new_input);
}

static void		read_input(t_input **adr_input)
{
	t_input		**temp_input;
	int			read_num;
	char		*line;

	temp_input = adr_input;
	while ((read_num = get_next_line(STDIN_FILENO, &line)) > 0)
	{
		(*temp_input)->line = line;
		(*temp_input)->type = check_line(line);
		(*temp_input)->front = *temp_input;
		(*temp_input)->front = new_t_input(*temp_input);
		(*temp_input) = (*temp_input)->front;
		ft_strdel(&line);
	}
}

t_input			*get_input(t_lemin *lemin)
{
	t_input		*new_input;

	if (!(new_input = new_t_input(NULL)))
		put_error("Can't allocate memory");
	read_input(&new_input);
	valid_input(new_input, lemin);
	return (new_input);
}
