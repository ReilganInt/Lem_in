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

int				valid_input(t_input		*input, t_lemin *lemin)
{
	t_input     *temp;
	int         flag;

	if (!(lemin = (t_lemin *)malloc(sizeof(t_lemin))))
		put_error("Can't allocate memory");
	temp = input;
	flag = 0;
	while (temp->front)
	{
		/* data */
		temp = temp->front;
	}
	return (1);
}
