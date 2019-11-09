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

t_input			*new_t_input(t_input *temp)
{
	t_input		*new_input;

	if (new_input = (t_input *)malloc(sizeof(t_input)))
		put_error("Can't allocate memory");
	new_input->line = NULL;
	if (temp && temp->front)
		new_input->back = temp;
	else
		new_input->back = NULL;
	new_input->front = NULL;
	return (new_input);
}

void			read_input(t_input **adr_input)
{
	t_input		**temp_input;
	int			read_num;
	char		*line;

	temp_input = adr_input;
	while ((read_num = get_next_line(STDIN_FILENO, &line)) > 0)
	{
		(*temp_input)->line = line;
		(*temp_input)->front = *temp_input;
		(*temp_input)->front = new_t_input(*temp_input);
		(*temp_input) = (*temp_input)->front;
		ft_strdel(&line);
	}
}

t_input			*get_input(void)
{
	t_input		*new_input;

	if (!(new_input = new_t_input(NULL)))
		put_error("Can't allocate memory");
	read_input(&new_input);
	return (new_input);
}
