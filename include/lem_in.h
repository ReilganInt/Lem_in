/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:52:00 by vmormont          #+#    #+#             */
/*   Updated: 2019/11/01 15:52:01 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
#define LEM_IN_H
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <math.h>
# include <iso646.h>
# include <string.h>
# include <float.h>

/*
**	Description of graph node
*/

typedef struct		s_lemin
{
	int				antsNum;
	t_ants			*ants;
	int				vertexs;
	int				**edges;
	t_vertex		**rooms;
	t_vertex		*start;
	t_vertex		*end;
}					t_lemin;

typedef struct		s_input
{
	char			*line;
	struct s_input	*back;
	struct s_input	*front;
}					t_input;

t_input			*get_input(void);

typedef struct		s_path
{
	/* data */	
}					t_path;


typedef struct		s_vertex
{
	/* data */
}					t_vertex;

typedef struct		s_ants
{
	/* data */
}					t_ants;

#endif