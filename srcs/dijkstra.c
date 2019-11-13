/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 04:08:11 by vmormont          #+#    #+#             */
/*   Updated: 2019/11/13 04:08:12 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_way			dijkstra_ford(t_lemin *lemin, t_input *input)
{
	t_way		ways;
	const int	inf = 2147483647;
	char		flag;
	int			i;

	i = 0;
	if (lemin->antsNum > 1)
		while (1)
		{
			flag = '0';
			while (i < m)
			{
				if ( < inf)
					if ()
					{

						flag = '1';
					}
				i++;
			}
			if (!flag)
				break ;
		}
	else
	{
		/* 1 short way */
	}
	
}
