/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:13:30 by cormund           #+#    #+#             */
/*   Updated: 2019/05/20 16:55:26 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	char const	*l;

	if (s)
	{
		l = s;
		while (*l)
			++l;
		write(fd, s, l - s);
	}
	ft_putchar_fd('\n', fd);
}
