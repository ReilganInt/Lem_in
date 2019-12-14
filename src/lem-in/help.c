/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:15:03 by cormund           #+#    #+#             */
/*   Updated: 2019/12/14 20:25:11 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			print_help(void)
{
	ft_printf("Welcome to Lem-in (Authors: Cormund and Vmormont)\n\n");
	ft_printf("Start the program correctly:\n\n");
	ft_printf("\t./lem-in {flag} < {map}\n\n");
	ft_printf("Flags:\n\n");
	ft_printf("\t-d - for debug information\n");
	ft_printf("\t-v - for visualisation\n\n");
	ft_printf("Have a nice day, My Friend!\n");
}

void			check_split(char **split)
{
	int			i;

	i = 0;
	while (split[i])
		i++;
	if (i == 2)
		return ;
	error(LI_ERROR_NOT_VALID_EDGE);
}

void			check_split_vertex(char **split)
{
	int			i;

	i = 0;
	while (split[i])
		i++;
	if (i == 3)
		return ;
	error(LI_ERROR_NOT_VALID_V);
}

int				check_coord(char *coord)
{
	int			int_nbr;
	char		*char_nbr;

	int_nbr = 0;
	char_nbr = NULL;
	int_nbr = ft_atoi(coord);
	char_nbr = ft_itoa(int_nbr);
	if (ft_strequ(char_nbr, coord))
	{
		free(char_nbr);
		return (int_nbr);
	}
	else
		error(LI_ERROR_NOT_VALID_COORD);
	return (1);
}

char			*check_name(char *name)
{
	if (*name == 'L')
		error(LI_ERROR_NOT_VALID_V);
	return (ft_strdup(name));
}
