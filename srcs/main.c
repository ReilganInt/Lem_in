/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:15:06 by vmormont          #+#    #+#             */
/*   Updated: 2019/11/08 21:15:08 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			put_error(char *error)
{
	ft_printf("%s\n", error);
	exit(EXIT_FAILURE);
}

int				main(int argc, char **argv)
{
	t_lemin		lemin;
	t_input		*input;

	input = get_input(&lemin);
	return (0);
}
