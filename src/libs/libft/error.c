/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 19:48:47 by cormund           #+#    #+#             */
/*   Updated: 2019/11/08 13:27:08 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			error(const char *error_msg)
{
	if (error_msg)
	{
		ft_putstr("ERROR: ");
		ft_putendl(error_msg);
	}
	exit(-1);
}
